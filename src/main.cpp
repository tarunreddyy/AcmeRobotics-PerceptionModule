// Copyright 2023 Tarun Trilokesh

/**
 * @file main.cpp
 * @author  Tarun Trilokesh
 * @date    10/23/2023
 * @version 1.0
 * 
 * @brief Main entry point for the AcmeRobotics-PerceptionModule project.
 *
 * This program initializes video capture from a camera using OpenCV,
 * sets up a window to display the video feed, and implements
 * human detection using YOLO.
 */

#include "Camera.h"
#include "YOLO.h"
#include "OpenCVProcessor.h"

/**
 * @brief Main function to run the AcmeRobotics-PerceptionModule project.
 * 
 * Initializes the Camera, YOLO, and OpenCVProcessor classes. Captures video frames
 * from the camera, detects humans using the YOLO model, processes the frames using
 * OpenCV functions, and displays the processed frames in a window.
 * 
 * @return int - Returns 0 on successful execution.
 */
int main() {
    Camera camera;             ///< Camera object to capture video frames.
    YOLO yolo;                 ///< YOLO object for human detection.
    OpenCVProcessor opencvProcessor;  ///< OpenCVProcessor object for image processing.

    while (true) {
        cv::Mat frame = camera.captureImage();  ///< Capture image using Camera class.

        if (frame.empty()) {
            break;
        }

        yolo.detect(frame);   ///< Detect humans using YOLO class.
        opencvProcessor.processImages(frame);  ///< Process image using OpenCVProcessor class.

        // Display the frame
        cv::imshow("Frame", frame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    camera.release();  ///< Release the camera.
    cv::destroyAllWindows();  ///< Destroy all OpenCV windows.

    return 0;
}
