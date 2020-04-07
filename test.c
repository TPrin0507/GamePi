#include "displaylib.c"

void main(){
	openFramebuffer();
	writePixel(7, 7, white);
	closeFramebuffer();
}
