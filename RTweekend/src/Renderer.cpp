#include "Renderer.h"


namespace Utils {

	static uint32_t ConvertToRGBA(const glm::vec4& color)
	{
		uint8_t r = uint8_t(color.r * 255.0f);
		uint8_t g = uint8_t(color.g * 255.0f);
		uint8_t b = uint8_t(color.b * 255.0f);
		uint8_t a = uint8_t(color.a * 255.0f);

		uint32_t result = (a << 24) | (b << 16) | (g << 8) | r;
		return result;
	}
}

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

void Renderer::Render(const Scene& scene, const Camera& camera) {
	//render every pixel
	
	const glm::vec3& rayOrigin = camera.GetPosition();
	
	Ray ray;
	ray.Origin = camera.GetPosition();


	for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++)
	{
		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++)
		{

			ray.Direction = camera.GetRayDirections()[x+y* m_FinalImage->GetWidth()];
			
			glm::vec4 color = TraceRay(scene, ray);
			color = glm::clamp(color, glm::vec4(0.0f), glm::vec4(1.0f));
			m_ImageData[x + y * m_FinalImage->GetWidth()] = Utils::ConvertToRGBA(color);
		}
	}
	m_FinalImage->SetData(m_ImageData);
}

glm::vec4 Renderer::TraceRay(const Scene& scene, const Ray& ray)
{
	
	// (bx^2 + by^2)t^2 + (2axbx + 2ayby)t + (ax^2 + ay^2 - r^2) = 0
	// a = origin of the Ray
	// b = Direction of the Ray along b
	// r = Radius
	// t = Hit distance

	if (scene.Speheres.empty()) {
		return glm::vec4(0, 0, 0, 1);
	}


	const Sphere* closestSphere = nullptr;
	
	float hitDistance =  std::numeric_limits<float>::max(); // FLT_MAX;

	for (const Sphere& sphere : scene.Speheres) {
		
		glm::vec3 origin = ray.Origin - sphere.Position;


		//Forming the quadratic equation's coefficents(a,b,c)
		float a = glm::dot(ray.Direction, ray.Direction);
		float b = 2.0f * glm::dot(origin, ray.Direction);
		float c = glm::dot(origin, origin) - sphere.Radius * sphere.Radius;

		//Quadratic formula discriminant
		//b^2 - 4ac

		float discriminant = b * b - 4.0f * a * c;
		// (- b +- sqrt(b*b - 4*a*c) ) / (2 * a)

		if (discriminant < 0.0f)
			continue; //if we miss the current spehere we loop through another, untill all the spheres are processed. 

		//The Entry hit point is considered as the closestHit Point
		float closestHit = (-b - glm::sqrt(discriminant)) / (2.0f * a);
		//float t0 = (-b + glm::sqrt(discriminant)) / (2.0f * a);
		
		if (closestHit < hitDistance) {
			closestSphere = &sphere;
			hitDistance = closestHit;
		}
	}

	if (closestSphere == nullptr) {
		return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	}

	glm::vec3 origin = ray.Origin - (*closestSphere).Position;
	glm::vec3 hitPoint = origin + ray.Direction * hitDistance;
	glm::vec3 normal = glm::normalize(hitPoint);

	glm::vec3 lightDirection = glm::normalize(glm::vec3(-1, -1, -1));

	//gives the Cosine of angle between Normal & LightDir and taking the values which are > 0. 
	//lightIntensity calculation
	float lightIntensity = glm::max(glm::dot(normal, -lightDirection), 0.0f);
	
	glm::vec3 sphereColor = (*closestSphere).Albedo;
	sphereColor *= lightIntensity;
	return glm::vec4(sphereColor, 1.0f);

}
