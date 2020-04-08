#include "displaylib.h"
#include "inputlib.h"

int main(){
	
	openFramebuffer();
	writeAllPixel(darkyellow);
	closeFramebuffer();

	openInputfile();
	while(1){
		readInputfile();
	}
	closeInputfile();

	/*activateIMU();
	activateGyro();
	getGyroData();*/

	return 1;
}
