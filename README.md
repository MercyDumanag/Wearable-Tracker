# Wearable-Tracker
Wearable Activity Tracker
Overview

The Wearable Activity Tracker is an embedded IoT system designed to monitor and classify human activities such as standing, walking, and running in real time. It uses an RT-Thread–based development board equipped with an inertial measurement unit (IMU) to collect motion data and process it for activity recognition.

Hardware Used

RT-Thread RT-Spark Development Board

ICM20608 Accelerometer and Gyroscope (onboard)

Android Smartphone (for data visualization, if applicable)

Software and Tools

RT-Thread Operating System

C programming language

I2C communication interface

Math library for sensor data processing

How It Works

The wearable device continuously reads acceleration and angular velocity data from the onboard IMU sensor through the I2C bus. The raw accelerometer data is converted into physical units and processed to compute motion intensity. Based on predefined thresholds, the system classifies the user’s current activity (e.g., standby, walking, or running) and outputs the result in real time.
