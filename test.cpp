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
	enableGyro();

	while(1){
		
		printf("before reading");

		//readRegister(WHO_AM_I);
		readGyro();
		sleep(2);
	}

	closeI2C();
	return 1;
}
