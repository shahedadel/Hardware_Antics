# Smart Environmental Duck

An Arduino-based environmental sensing platform that collects sensor data, controls actuators, and analyzes sensor performance using Python.

## Overview

This project explores embedded systems, sensor integration, and data analysis through the development of an interactive smart duck.

The system currently supports:
- Button input
- Servo-controlled neck movement
- LED eye control
- Ultrasonic distance sensing
- PIR motion detection

Future additions:
- Temperature/humidity sensing
- Light sensing
- Sound sensing
- CSV data logging
- Python-based sensor analysis

## Hardware

Microcontroller:
- Arduino Uno

Sensors:
- HC-SR04 Ultrasonic Sensor
- PIR Motion Sensor

Actuators:
- Servo motor
- LEDs

## Current Features

- Press button → duck eyes turn on
- Press button → duck turns head
- Detect motion → sends message over serial
- Measure distance → outputs distance readings

## Software

Languages:
- C++ (Arduino)
- Python (analysis)

Tools:
- Arduino IDE
- VS Code
- Jupyter Notebook
