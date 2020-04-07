#include "displaylib.c"

void main(){
	openFramebuffer();
	writeAllPixel(black);
	writePixel(5, 6, magenta);
	closeFramebuffer();
}
