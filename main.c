#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "icm20608.h"
#include <math.h>

#define THREAD_PRIORITY      25
#define THREAD_STACK_SIZE    4096
#define THREAD_TIMESLICE     5

#define GRAVITY_RAW          16384
#define WALK_THRESHOLD       3000   // slight movement
#define RUN_THRESHOLD        8000   // big movement

icm20608_device_t dev = RT_NULL;

static void sensor_thread_entry(void *parameter)
{
    rt_int16_t acc_x, acc_y, acc_z;
    rt_int16_t gyro_x, gyro_y, gyro_z;

    dev = icm20608_init("i2c2");
    if (dev == RT_NULL)
    {
        rt_kprintf("ICM20608 Init Failed!\n");
        return;
    }
    rt_kprintf("ICM20608 Initialized Successfully!\n");

    while (1)
    {
        // Read sensor data
        icm20608_get_accel(dev, &acc_x, &acc_y, &acc_z);
        icm20608_get_gyro(dev, &gyro_x, &gyro_y, &gyro_z);

        // Compute magnitude for activity detection
        int delta_x = acc_x;
        int delta_y = acc_y;
        int delta_z = acc_z - GRAVITY_RAW;
        int magnitude = sqrt(delta_x*delta_x + delta_y*delta_y + delta_z*delta_z);

        // Determine activity
        const char* activity;
        if (magnitude < WALK_THRESHOLD)
            activity = "standby";
        else if (magnitude < RUN_THRESHOLD)
            activity = "walking";
        else
            activity = "running";

        // Print JSON to USART
        rt_kprintf("{\"acc_x\":%d,\"acc_y\":%d,\"acc_z\":%d,"
                   "\"gyro_x\":%d,\"gyro_y\":%d,\"gyro_z\":%d,"
                   "\"activity\"😕"%s\"}\n",
                   acc_x, acc_y, acc_z,
                   gyro_x, gyro_y, gyro_z,
                   activity);

        // Delay 2 seconds
        rt_thread_mdelay(2000);
    }
}

int main(void)
{
    rt_kprintf("Starting Wearable Tracker...\n");

    rt_thread_t sensor_tid = rt_thread_create("sensor",
                                              sensor_thread_entry,
                                              RT_NULL,
                                              THREAD_STACK_SIZE,
                                              THREAD_PRIORITY,
                                              THREAD_TIMESLICE);
    if (sensor_tid != RT_NULL)
        rt_thread_startup(sensor_tid);
    else
        rt_kprintf("Failed to create sensor thread!\n");

    return 0;
}