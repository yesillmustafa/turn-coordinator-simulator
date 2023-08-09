# Turn Coordinator Simulator (Modern OpenGL)

This project is a turn coordinator simulator developed using Modern OpenGL. The turn coordinator is an aviation instrument used to monitor the horizontal axis (roll) movements of an aircraft and provide pilots with information about the flight attitude. It is designed particularly to indicate the aircraft's bank angles and rate of turn during turning maneuvers.

https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/838610e2-43ab-4bf8-be06-9a290a04d892

## Values Read From the Turn Coordinator
**Slip**: When the aircraft is making a turn, it slides towards the center. It occurs if the rotation movement is insufficient or the rotation speed is low.
(if the ball is sliding in the direction of aircraft's rotation.)

**Skid**: When the plane is making a turn, it slides out of the center. Rotation may occur if the movement is excessive or fast.
(if the ball is sliding in the opposite direction of the aircraft's rotation.)

**Coordinated Turn**: The aircraft performs its rotation smoothly and evenly. It moves evenly on both horizontal and vertical axes, there is no sliding or skidding.
(if the ball is in the middle during the turn.)

**Standard rate turn**: A standard rate turn is defined as a 3° per second turn, which completes a 360° turn in 2 minutes. This is known as a 2-minute turn, or rate one (180°/min).
(when the aircraft miniature indicator is exactly in line with the 'R' or 'L' marker)




<div style="display: flex;">

<div style="text-align: center; margin-right: 20px;">
  <p>Stable Flight:</p>
  <img src="https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/4f16b49c-520f-4f5a-a1b2-beb6f1c2f2aa" width="200" height="200" />
</div>

<div style="text-align: center; margin-right: 20px;">
  <p>
The aircraft is making a coordinated turn to the left at the 3°/sc rate of turn:
  </p>
  <img src="https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/ebe1d456-b193-43b1-9d29-31dd7e55007f" width="200" height="200" />
</div>

<div style="text-align: center; margin-right: 20px;">
  <p>The aircraft is making a slipping turn to the left:</p>
  <img src="https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/ecccedb0-a177-440e-bba8-be9ec323dddb" width="200" height="200" />
</div>

<div style="text-align: center; margin-right: 20px;">
  <p>The aircraft is making a skidding turn to the right:</p>
  <img src="https://github.com/yesillmustafa/turn-coordinator-simulator/assets/74787246/6d874388-e342-43c2-800e-26c6f6c333e1" width="200" height="200" />
</div>

</div>


## Libraries
The simulator uses the following libraries for OpenGL interactions and rendering.
- [GLAD](https://glad.dav1d.de/) (included in the project)
- [GLFW](https://www.glfw.org/)
- [GLM](https://github.com/g-truc/glm)
- [stb image](https://github.com/nothings/stb) (included in the project)

## Features

- Realistic turn coordinator simulation.
- Display of the ball showing slip skid movements
- Smooth animations and transitions.

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
