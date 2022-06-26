#include "Renderer.h"


void Renderer::OnResize(uint32_t width, uint32_t height)
{
	if (m_FinalImage) {
		//No resize necesdary
		if (m_FinalImage->GetWidth() == width && m_FinalImage->GetHeight() == height) {
			return;
		}

		m_FinalImage->Resize(width, height);
	}
	else
	{
		m_FinalImage = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];

}

void Renderer::Render() {
	//render every pixel
	for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++)
	{
		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++)
		{
			glm::vec2 coord = { (float)x / (float)m_FinalImage->GetWidth(), (float)y / (float)m_FinalImage->GetHeight() };
			coord = coord * 2.0f - 1.0f; // -1 -> 1

			m_ImageData[x + y * m_FinalImage->GetWidth()] = PerPixel(coord);
		}
	}
	m_FinalImage->SetData(m_ImageData);
}

uint32_t Renderer::PerPixel(glm::vec2 coord)
{
	glm::vec3 rayOrigin(0.0f, 0.0f, 2.0f); //Left handed co-ordinate system, so making the camera moving back(z = +ve)
	glm::vec3 rayDirection(coord.x, coord.y, -1.0f); //adding the depth, so the shooted rays will be into the plane
	float radius = 0.5f;
	// rayDirection = glm::normalize(rayDirection);
	
	// (bx^2 + by^2)t^2 + (2axbx + 2ayby)t + (ax^2 + ay^2 - r^2) = 0
	// a = origin of the Ray
	// b = Direction of the Ray along b
	// r = Radius
	// t = Hit distance

	//Forming the quadratic equation's coefficents(a,b,c)
	float a = glm::dot(rayDirection, rayDirection);
	float b = 2.0f * glm::dot(rayOrigin, rayDirection);
	float c = glm::dot(rayOrigin, rayOrigin) - radius * radius;

	//Quadratic formula discriminant
	//b^2 - 4ac

	float discriminant = b * b - 4 * a * c;

	if (discriminant >= 0)
		return 0xffff00ff;
	
	return 0xff000000;

}
