#include "gyrolib.h"

RTIMUSettings *settings = new RTIMUSettings("RTIMULib");

RTIMU *imu = RTIMU::createIMU(settings);

void activateIMU(){
	
	if((imu == NULL) || (imu->IMUType() == RTIMU_TYPE_NULL)){
	 	printf("No IMU found");
		return ;
	}

	imu->IMUInit();

}

void activateGyro(){

	imu->setSlerpPower(0.02);
	imu->setGyroEnable(true);
    
}

void getGyroData(){
	
	uint64_t rateTimer, displayTimer, now;
	
	rateTimer = displayTimer = RTMath::currentUSecsSinceEpoch();
	
	while(1){
	
		usleep(imu->IMUGetPollInterval() * 200000);

		while(imu->IMURead()){
		
			RTIMU_DATA imuData = imu->getIMUData();

			now = RTMath::currentUSecsSinceEpoch();

			//if((now - displayTimer) < 500000) {
			
				//printf("%s\n", RTMath::displayDegrees("", imuData.fusionPose));
                
                printf("x: %f y: %f z: %f\n\n", (imuData.gyro.x()*RTMATH_RAD_TO_DEGREE)/100, (imuData.gyro.y()*RTMATH_RAD_TO_DEGREE)/100, (imuData.gyro.z()*RTMATH_RAD_TO_DEGREE)/100);

                printf("x: %f y: %f z: %f\n\n\n", (imuData.accel.x()*RTMATH_DEGREE_TO_RAD)*10000, (imuData.accel.y()*RTMATH_DEGREE_TO_RAD)*10000, (imuData.accel.z()*RTMATH_DEGREE_TO_RAD)*10000);
			
                fflush(stdout);
                displayTimer = now;
                
			//}
		
		}

	}
}
