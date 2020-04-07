// Raspi SenseHAT 8x8 framebuffer 5-6-5 BGR

#include "displaylib.h"

int fbfd = 0;
long int screensize = 0;
char *fbp = 0;
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;

void writePixel(int x, int y, rgb colour){
	long int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
			    (y+vinfo.yoffset) * finfo.line_length;
	unsigned short int t = colour.r<<11 | colour.g<<5 | colour.b;
	*((unsigned short int*)(fbp + location)) = t;
}

void writeAllPixel(rgb colour){
	for (int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++){
			writePixel(x, y, colour);
		}
	}
}

int openFramebuffer()
{

    // Open the file for reading and writing
    fbfd = open("/dev/fb1", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    return 0;
}

int closeFramebuffer(){
	munmap(fbp, screensize);
	close(fbfd);
	
	return 0;
}
