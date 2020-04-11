#include "senselib.h"

int file; 

void openI2C(){
	
	file = open("/dev/i2c-1", O_RDWR);

	if (file < 0){
	
		printf("Error while opening file.");
		return;
	}
}

void closeI2c(){

	close(file);

}

int enableGyro(){

	//reset gyro and accel
	writeRegister(CTRL_REG8, 0x05);

	//wait until reboot finished
	sleep(1);

	//enable xyz gyro
	writeRegister(CTRL_REG_GYRO, 0xC0);

	return 0;

}

int readGyro(){

	printf("Pitch is 0x%02x ", readRegister(OUT_X_L_G));

	printf("Yaw is 0x%02x ", readRegister(OUT_Y_L_G));

	printf("Roll is 0x%02x\n", readRegister(OUT_Z_L_G));

	return 0;

}


unsigned char readRegister(unsigned char reg){
	
	unsigned char outbuf[1], inbuf[1];
	struct i2c_rdwr_ioctl_data packets;
	struct i2c_msg msg[2];

	msg[0].addr = 0x6A;	//LSM9DS1 address
	msg[0].flags = 0;
	msg[0].len = sizeof(outbuf);
	msg[0].buf = outbuf;
	outbuf[0] = reg;

	msg[1].addr = 0x6A;
	msg[1].flags = I2C_M_RD | I2C_M_NOSTART;
	msg[1].len = sizeof(inbuf);
	msg[1].buf = inbuf;

	packets.msgs = msg;
	packets.nmsgs = 2;

	if(ioctl(file, I2C_RDWR, &packets) < 0){
	
		printf("Error while reading Data");
	
	}

	//printf("reg[0x%02x] pitch is 0x%02x \n", outbuf[0], inbuf[0]);

	return inbuf[0];
}

int writeRegister(unsigned char reg, unsigned char value){

	
	unsigned char outbuf[2];

	struct i2c_rdwr_ioctl_data packets;
	struct i2c_msg msg[1];

	outbuf[0] = reg;
	outbuf[1] = value;

	msg[0].addr = 0x6A;
	msg[0].flags = 0;
	msg[0].len = 2;
	msg[0].buf = outbuf;

	packets.msgs = msg;
	packets.nmsgs = 1;

	if(ioctl(file, I2C_RDWR, &packets) < 0){
	
		printf("Error while writing Data");

	}

	return 0;
}

