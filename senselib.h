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
#define OUT_X_G 0x18
#define OUT_Y_G 0x1A
#define OUT_Z_G 0x1C
#define CTRL_REG_GYRO 0x10

void openI2C();

int enableGyro();

void readGyro();

int readRegister(unsigned char reg);


#endif
