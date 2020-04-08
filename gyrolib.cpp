#include "gyrolib.h"

using namespace std;

RTIMUSettings *settings = new RTIMUSettings("RTIMULib");

RTIMU *imu = RTIMU::createIMU(settings);

RTFusionRTQF fusion;

void activateIMU(){
	
	if((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)){
		cout << "No IMU found" << endl;
		return ;
	}

	imu->IMUInit();

}

void activateGyro(){

	fusion.setSlerpPower(0);
	fusion.setGyroEnable(true);
    
}

void getGyroData(){
	while(imu->imuread()){
	
		RTMath::display("gyro: ", (RTVector3&)imu->getGyro());

	}
}
