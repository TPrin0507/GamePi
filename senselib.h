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

void openI2C();

int readGyro();


#endif
