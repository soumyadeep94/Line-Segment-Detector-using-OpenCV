# Line-Segment-Detector-using-OpenCV

![Result](images/result.png)


## Principle: 
**LSD** is a linear-time line segment algorithm giving subpixel accurate results. It detects locally straight contours on images. The algorithm starts by computing the ***level-line angle*** at each pixel to produce a ***level line field***. This field is then segmented into connected region of pixels that share the same level-line angle upto a certain degree of tolerance (τ), called ***line-support regions***. 
The older algorithms like Hough transform which uses Canny filter have a lot of false detections. Ignoring the orientation of the edge points,
such algorithms obtain line segments with aberrant direction. Compared to this, LSD uses much stable approach of **Helmholtz principle**, according to which an observed geometric structure is of significance, only when it's noise expectation is less than 1.

## Compilation and Dependencies

The LSD algorithm is written in C++ and uses [OpenCV](https://opencv.org/) library.
To build the files, [CMake](https://cmake.org/) has been used.
During compilation create a new directory called **build** in the main directory.

## Usage
   Linux

- cmake ..
- make

This will create ./LSD file in the build directory. Run ./LSD to run the application.

## References
- To read more about the line segment detector algorithm, refer to the [original paper](https://www.ipol.im/pub/art/2012/gjmr-lsd/article.pdf).
- The original c code for the LSD algorithm is provided [here](http://www.ipol.im/pub/art/2012/gjmr-lsd/).



