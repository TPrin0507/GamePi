#ifndef GYROLIB_H
#define GYROLIB_H

#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define WHO_AM_I 0x0F
#define OUT_X_L_G 0x18
#define OUT_X_H_G 0x19
#define OUT_Y_L_G 0x1A
#define OUT_Y_H_G 0x1B
#define OUT_Z_L_G 0x1C
#define OUT_Z_H_G 0x1D
#define CTRL_REG_GYRO 0x10

#define OUT_X_L_XL 0x28
#define OUT_X_H_XL 0x29
#define OUT_Y_L_XL 0x2A
#define OUT_Y_H_XL 0x2B
#define OUT_Z_L_XL 0x2C
#define OUT_Z_H_XL 0x2D
#define CTRL_REG_ACCEL 0x20

#define CTRL_REG8 0x22

void openI2C();

void closeI2C();

int enableSensor(int CTRL_REG_SENSOR);

int readSensor();

int convertToSigned(int hex);

unsigned char readRegister(unsigned char reg);

int writeRegister(unsigned char reg, unsigned char value);


#endif
