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

	while(1){
		
		openI2C();
		readRegister(WHO_AM_I);

		sleep(2);
	}
	return 1;
}
