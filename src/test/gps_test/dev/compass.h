#ifndef COMPASS_H
#define COMPASS_H 1
#include "gpio.h"
#include "i2c.h"
#include <math.h>

#define      LSM303_READ_REG           0x1F
#define      LSM303_WRITE_REG          0x1F  
#define      LSM303_CTRL0              0x1F  
#define      LSM303_CTRL1              0x20  
#define      LSM303_CTRL2              0x21  
#define      LSM303_CTRL3              0x22  
#define      LSM303_CTRL4              0x23  
#define      LSM303_CTRL5              0x24  
#define      LSM303_CTRL6              0x25  
#define      LSM303_CTRL7              0x26 
#define      LSM303_WHO_AM_I           0x0F  
#define      LSM303_OUT_X_L_M          0x08
#define      LSM303_OUT_X_H_M          0x09
#define      LSM303_OUT_Y_L_M          0x0A
#define      LSM303_OUT_Y_H_M          0x0B
#define      LSM303_OUT_Z_L_M          0x0C
#define      LSM303_OUT_Z_H_M          0x0D

#define      COMPASS_I2C               hi2c1
#define      COMPASS_I2C_ADDR          0x3A

void compass_init();

float* compass_get_angle();

#endif
