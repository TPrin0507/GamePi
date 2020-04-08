#ifndef DISPLAYLIB_H
#define DISPLAYLIB_H


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <iostream>
#include "colourlib.h"


void writeFrame(rgb colour);
void writeSquare(int x, int y, rgb colour);
void writeCircle();
void writeHorizontalLine();
void writeVerticalLine();
void writeTriangle();
void clearScreen();
void toggleBrightness();

void writePixel(int x, int y, rgb colour);
void writeAllPixel(rgb colour);
int openFramebuffer();
int closeFramebuffer();

#endif
