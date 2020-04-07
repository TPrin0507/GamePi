#include "accerolib.h"

void activateAccelo(){
	
	imu->ImuInit();

	imu->setAccelEnable(true);
}

void getAcceloData(){


}
