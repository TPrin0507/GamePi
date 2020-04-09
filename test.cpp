#include "displaylib.h"
#include "inputlib.h"
#include "gyrolib.h"

int main(){
	
	/*openFramebuffer();
	clearScreen();
	writeLine(0, 0, 3, 0, blue);
	closeFramebuffer();*/

	/*openInputfile();
	while(1){
		readInputfile();
	}
	closeInputfile();*/

	activateIMU();
	activateGyro();
	getGyroData();

	return 1;
}
