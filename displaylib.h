#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <iostream>
#include "colourlib.h"


void writePixel(int x, int y, rgb colour);

void writeAllPixel(rgb colour);

int openFramebuffer();

int closeFramebuffer();

