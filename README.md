# Ray Tracing
This is a Hands-on Implementation of Ray Tracing from scratch.

## [Output 1](https://github.com/rajashekarkasturi/RTweekend/tree/b3c1bf220b838ce092d41051aca96c856ba9dd01)
Rendering of Random RGBA pixels in Real-time using [Walnut](https://github.com/TheCherno/Walnut), ImGui and the Vulkan API.
* Specifying the Image_data and passing it to the Viewport in our sample rendering Application.
* Focus Area
    ``` 
    RTweekend/src/BasicRenderMain.cpp
    Render();
    ```
    ![Random RGB Render](/assets/images/RandomRenderRGB.PNG "Random RGBA")

## [Output 2](https://github.com/rajashekarkasturi/RTweekend/tree/a4f5e609ffc351f5c17af4dabd3da37062941467)
Rendering of uv co-ordinate mechanism using Red and Green channels and restrucuted code to work more like a Pixel shader ([shadertoy](https://www.shadertoy.com/view/7scBz7))

* Focus Area
    ```
    Renderer.cpp, Renderer::PerPixel();
    Renderer.hpp
    ```
    ![Pixel Coordinates RG Channels](/assets/images/PixelationUVCoordinates.png)

## [Output 3](https://github.com/rajashekarkasturi/RTweekend/tree/88a1f98436a4f09d9745105d3217cfb7196f984d)
Rendering of Sphere by setting the RayDirection, RayOrigin using the PerPixel method which was re-structured earlier to work like a Pixel shader.
* Focus Area
    ```
    Renderer.cpp, Renderer::PerPixel();
    ```
    ![basic_sphere](/assets/images/RayTraced-sphere1.png)

## [Output 4](https://github.com/rajashekarkasturi/RTweekend)
Rendering of Sphere, focusing on Normals, Lighting and RGBA(0-1) convention for coloring using glm.
* Focus Area
    ```
    File-> Renderer.cpp, Functions-> Utils::ConvertToRGBA(), Renderer::PerPixel(), Lines 85-98;
    ```
    ![Lighting_sphere_rt](/assets/images/Lighting_Shading_rt.PNG)

## Credits
### Walnut App Template

This is a simple app template for [Walnut](https://github.com/TheCherno/Walnut) - unlike the example within the Walnut repository, this keeps Walnut as an external submodule and is much more sensible for actually building applications. See the [Walnut](https://github.com/TheCherno/Walnut) repository for more details.
