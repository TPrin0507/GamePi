#include <stdlib.h>
#include <sys/stat.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <string>

#define BITS_PER_LONG (sizeof(long)*8)
#define NBITS(x) ((((x)-1)/BITS_PER_LONG)+1)
#define SIZESTRUCT sizeof(struct input_event)

void openInputfile();
void readInputfile();
std::string getKey();
void closeInputfile();


