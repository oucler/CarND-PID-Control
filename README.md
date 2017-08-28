# PID Controller Project

## Table Content: ##
- [Objective](#objective)
- [Results](#results)
- [How to run](#howto)
- [Dependencies](#dependency)
- [Directory Structure](#structure)
- [PID](#pid)
- [Discussions](#discussion)


## Objective: <a name="objective"></a>

The goal is to drive a car in the simulator without getting off the track and using PID controller method to calculate the steering. 

## Results: <a name="results"></a>

Due to the size limitation of github only small size of the video is part of the github repository and the video clip is playing below.

![](videos/pid_short.gif)

Entire vidoe capture is uploaded to youtube link: [Full Video](https://www.youtube.com/watch?v=Z5yJ4A_PVjw&feature=youtu.be)


## How to run: <a name="howto"></a>

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

This repository includes two files that can be used to set up and intall uWebSocketIO for either Linux or Mac systems. For windows you can use either Docker, VMware, or even Windows 10 Bash on Ubuntu to install uWebSocketIO.

Once the install for uWebSocketIO is complete, the main program can be built and ran by doing the following from the project top directory.

	mkdir build
	cd build
	cmake ..
	make
	./pid

## Dependencies <a name="dependency"></a>

- cmake >= 3.5
- All OSes: click here for installation instructions
- make >= 4.1
-- Linux: make is installed by default on most Linux distros
-- Mac: install Xcode command line tools to get make
-- Windows: Click here for installation instructions
- gcc/g++ >= 5.4
-- Linux: gcc / g++ is installed by default on most Linux distros
-- Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
-- Windows: recommend using MinGW
- uWebSockets == 0.13, but the master branch will probably work just fine
-- Follow the instructions in the uWebSockets README to get setup for your platform. You can download the zip of the appropriate version from the releases page. Here's a link to the v0.13 zip.
-- If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
- Simulator. You can download these from the project intro page in the classroom.
	
## Directory Structure <a name="structure"></a>
The directory structure of this repository is as follows:

```
root
|   CMakeLists.txt
|   cmakepatch.txt
|   README.md
|   *.sh
|
|___videos
|   |
|   |  pid_short.gif
|
|
|___src
    |   main.cpp
    |   PID.h
    |   PID.cpp
    |   json.hpp
```

## Proportional Integral Derivative (PID) Control <a name="pid"></a>

#### P (Proportional):

	If the error is small the more conservative the response. If the error is large the more aggressive the 
	response. If this parameter is too large the tendency is to overshoot and miss the desired output.If it's 
	too large the oscillation will be increasing and instead of converging it will diverge. If it's too small, 
	it will take a longer time to get to the desired set point.

#### I (Integral):

	The parameter that sets how much we take into consideration the cumulative error over time. This is usually 
	used when we see that there is a systematic bias wherein we are not converging to our desired set point. 

#### D (Derivative):

	This parameter considers the rate of change in the error. If the error is rapidly approaching zero, this 
	parameter will attempt to slow things down to avoid overshooting. If this is too large, then there will be 
	overdamping which means it will take longer to reach the desired goal. 

## Discussions <a name="discussions"></a>

For this project Kp, Ki, and Kd values are constant and due to these value not being optimal in the simulator the car makes sharp steerings. As an improvement, Twiddle approach can be implemented for Kp,Ki, Kd, and speed parameter optimizations. 



