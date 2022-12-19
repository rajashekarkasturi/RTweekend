# Ray Tracing
This repository contains Implementation of Ray Tracing from scratch.

## [Latest](https://github.com/rajashekarkasturi/RTweekend)
Added behavioural lightning to sphere based on material system which are now mapped to spheres Individually, Earlier I was unfortunately running on Debug Build, so changed it to Release.
* Specifying the materials Individually
    ```
    src/BasicRendererMain.cpp // L 21-42
    src/Scene.h 
    ```
* Reflected rays property is changed by simulating the World's Normal, [microfacet](https://www.pbr-book.org/3ed-2018/Reflection_Models/Microfacet_Models) .
    ```
    src/Renderer.cpp // L 103
    ```
    ![Materialism](/assets/images/materials_PBR_1.png)

    ![Materialism](/assets/images/materials_PBR_2.png)


## [Output 1](https://github.com/rajashekarkasturi/RTweekend/tree/b3c1bf220b838ce092d41051aca96c856ba9dd01)
Rendering of Random RGBA pixels in Real-time using [Walnut](https://github.com/TheCherno/Walnut), ImGui and the Vulkan API.
* Specifying the Image_data and passing it to the Viewport in our sample Rendering application.
* Focus Area
    ``` 
    RTweekend/src/BasicRenderMain.cpp
    Render();
    ```
    ![Random RGB Render](/assets/images/RandomRenderRGB.PNG)

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

## [Output 4](https://github.com/rajashekarkasturi/RTweekend/tree/ffdaebdac500b3b356fb25e49231bbb379e98c4a)
Rendering of Sphere, focusing on Normals, Lighting and RGBA(0-1) convention for coloring using glm.
* Focus Area
    ```
    File-> Renderer.cpp, Functions-> Utils::ConvertToRGBA(), Renderer::PerPixel(), Lines 85-98;
    ```
    ![Lighting_sphere_rt](/assets/images/Lighting_Shading_rt.PNG)


## [Output 5](https://github.com/rajashekarkasturi/RTweekend/tree/e2c5bda2e08f64649a91892da7aec5e5d58adf0b)
Real-time Rendering of Sphere with Keyboard and Mouse events.
* Focus Area
    ```
    Renderer::PerPixel() -> Renderer::TraceRay(), Camera.cpp, Camera.h, Ray.h
    Camera::RecalculateRayDirections();  // Moving from Clip space to World space
    ```

## [Output 6](https://github.com/rajashekarkasturi/RTweekend/tree/d582a6c8b5eaef53472454ece3999b0390fcc27d)
Real-time Rendering of multiple spheres interactively with ImGUI.
* Focus Area
    ```
    Scene.h
    Renderer::Render(), Renderer::TraceRay() -> Finding out the closestSphere and hitDistances.
    BasicRenderMain:: -> ExampleLayer's constructor(adding of spheres), OnUIRender(Interaction with Spheres in Realtime)
    ```
    ![Rendering_Multiple_Spheres](/assets//images/RT-multipleSpheres.png)

## [Output 6](https://github.com/rajashekarkasturi/RTweekend/tree/045263854eab5e678c9f28499eb50502ce60fd21)
The whole code is restructured to work more like Raytracing shaders.
* Added some lighting to the spheres while shooting rays by invoking TraceRay() functionality from PerPixel(). 
* Focus Area
    ```
    RTweekend/src/Renderer.cpp
    PerPixel(); TraceRay();
    ClosestHit();
    Miss();
    ```
    ![RT-raybounce-basic-reflection](/assets//images/RT-Raybouncing-basic-reflection.png)

## Credits
### Walnut App Template

This is a simple app template for [Walnut](https://github.com/TheCherno/Walnut) - unlike the example within the Walnut repository, this keeps Walnut as an external submodule and is much more sensible for actually building applications. See the [Walnut](https://github.com/TheCherno/Walnut) repository for more details.
