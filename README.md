Robotic ARM of Fruitspector

This repository contains the implementation of a robotic arm and conveyor belt control system for a Fruitspector, which uses YOLOv12 for fruit and vegetable classification.
Features

    Fruit and Vegetable Classification: Leveraging YOLOv12 to identify and classify fruits and vegetables with high accuracy.
    Robotic Arm Control: Code for precise robotic arm movements to pick and place classified items.
    Conveyor Belt System: Code to manage the movement of items on a conveyor belt for seamless classification and sorting operations.

Repository Structure

    arm_control/: Contains code for robotic arm control.
    conveyor_belt_control/: Contains code for the conveyor belt system.
    YOLOv12 Integration: Model and configurations for fruit and vegetable classification.

Requirements

    Hardware:
        Arduino microcontroller for controlling the robotic arm and conveyor belt.
        Compatible robotic arm and conveyor belt setup.
    Software:
        Python for YOLOv12 implementation.
        C++/Arduino IDE for microcontroller programming.

Installation

    Clone the repository:
    bash

git clone https://github.com/amal-J-k/robotic-ARM-of-furutespector.git

Navigate to the directory:
bash

cd robotic-ARM-of-furutespector

Install the required dependencies for YOLOv12:
bash

    pip install -r requirements.txt

Usage

    Set up the Arduino microcontroller and upload the code for the robotic arm and conveyor belt control.
    Run the YOLOv12 model for real-time classification:
    bash

    python classify.py

    The robotic arm and conveyor belt will work in sync to classify and sort the items.

Contribution

Contributions are welcome! Please fork the repository and create a pull request with your changes.
License

This project is licensed under the MIT License. See the LICENSE file for details.
