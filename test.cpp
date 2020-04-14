#include "displaylib.h"
#include "inputlib.h"
#include "senselib.h"

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

	openI2C();
	enableSensor(CTRL_REG_ACCEL);

	while(1){
		
		readSensor();
		sleep(1);
	}

	closeI2C();
	return 1;
}
