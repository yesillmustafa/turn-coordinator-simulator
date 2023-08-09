# Turn Coordinator Simulator (Modern OpenGL)

This project is a turn coordinator simulator developed using Modern OpenGL. The turn coordinator is an aviation instrument used to monitor the horizontal axis (roll) movements of an aircraft and provide pilots with information about the flight attitude. It is designed particularly to indicate the aircraft's bank angles and rate of turn during turning maneuvers.

https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/838610e2-43ab-4bf8-be06-9a290a04d892

## Libraries
The simulator uses the following libraries for OpenGL interactions and rendering.
- [GLAD](https://glad.dav1d.de/) (included in the project)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [stb image](https://github.com/nothings/stb) (included in the project)

## Features

- Realistic turn coordinator simulation.
- Display of the ball showing slip skid movements
- Smooth animations
- User Interaction

## Prerequisites

Before you begin, ensure you have met the following requirements:

- [CMake](https://cmake.org/)
- OpenGL 3.3 or later
- [GLFW 3.3](https://www.glfw.org/)
- [glm](https://github.com/g-truc/glm) (OpenGL Mathematics)

## Installation and Usage

To get started, follow these steps:
1. Clone the repository:
```bash
git clone https://github.com/yesillmustafa/turn-coordinator-simulator.git
```
2. Navigate to the repository folder:
```bash
cd turn-coordinator-simulator
```
3. Create a build directory:
```bash
mkdir build
cd build
```
4. Generate build files using CMake:
```bash
cmake ..
```
5. Build the project:
```bash
cmake --build .
```
6. Run the simulator:
```bash
./TurnCoordinator
```


## FAQ

#### What is GLAD?

GLAD is a multi-language GL loader-generator aimed at making OpenGL initialization easier and more consistent across different platforms and graphics drivers.

#### What is GLFW?

GLFW is an open-source, multi-platform library for creating windows with OpenGL contexts and managing input, providing a foundation for building interactive graphical applications.

#### What is GLM?

GLM is a header-only C++ mathematics library designed for use in graphics programming and simulations, providing functions and classes for vector, matrix, and geometry operations.

#### What is stb_image?
stb_image is a single-header C library that provides a simple and fast way to perform image loading operations.

#### What is CMake?
CMake is a tool used for managing software projects; it simplifies the processes of compilation, configuration, and distribution of projects, enabling the creation of seamlessly functional projects on different platforms and compilers.
