#include "displaylib.c"
#include "inputlib.c"

void main(){
	/*openFramebuffer();
	writeAllPixel(black);
	writePixel(5, 6, magenta);
	closeFramebuffer();*/

	openInputfile();
	while(1){
		readInputfile();
	}
	closeInputfile();
}
