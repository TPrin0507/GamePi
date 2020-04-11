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
#define OUT_Y_L_G 0x1A
#define OUT_Z_L_G 0x1C
#define CTRL_REG_GYRO 0x10
#define CTRL_REG8 0x22

void openI2C();

void closeI2C();

int enableGyro();

int readGyro();

unsigned char readRegister(unsigned char reg);

int writeRegister(unsigned char reg, unsigned char value);


#endif
