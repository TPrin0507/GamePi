#include "displaylib.cpp"
#include "inputlib.cpp"

int main(){
	/*openFramebuffer();
	writeAllPixel(black);
	writePixel(5, 6, magenta);
	closeFramebuffer();*/

	openInputfile();
	while(1){
		readInputfile();
	}
	closeInputfile();

	return 1;
}
