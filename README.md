##🏃‍♂️ Wearable Activity Tracker ##

#📌 Overview

The Wearable Activity Tracker is an embedded Internet of Things (IoT) system designed to monitor and classify human activities—such as standing, walking, and running—in real time.
It is built on an RT-Thread–based development board and utilizes an onboard Inertial Measurement Unit (IMU) to capture motion data and perform lightweight activity recognition.

#🧠 Key Features

Real-time activity detection

Accelerometer- and gyroscope-based motion sensing

Lightweight and efficient embedded implementation

Designed for wearable and low-power applications

#🛠️ Hardware Used

RT-Thread RT-Spark Development Board

ICM20608 Accelerometer & Gyroscope (onboard)

Android Smartphone (optional – for data visualization)

#💻 Software & Tools

RT-Thread Operating System

C Programming Language

I2C Communication Interface


#⚙️ How It Works

The wearable device continuously reads acceleration and angular velocity data from the onboard IMU sensor via the I2C bus. Raw accelerometer readings are converted into physical units and used to compute the overall motion intensity of the user.
Using predefined thresholds, the system classifies the detected motion into activity states such as Standby, Walking, or Running, and outputs the results in real time through the serial interface or connected application.
