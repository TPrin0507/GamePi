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

int enableSensor(int CTRL_REG_SENSOR){

	//reset gyro and accel
	writeRegister(CTRL_REG8, 0x05);

	//wait until reboot finished
	sleep(1);

	
	if(CTRL_REG_SENSOR == CTRL_REG_GYRO){
		//enable xyz gyro
		writeRegister(CTRL_REG_GYRO, 0x38);
	}
	else if(CTRL_REG_SENSOR == CTRL_REG_ACCEL){
		//enable xyz accel
		writeRegister(CTRL_REG_ACCEL, 0x20);
	}
	return 0;

}

int readSensor(){
	
	
unsigned char accel_x_h, accel_x_l, accel_y_h, accel_y_l, accel_z_h, accel_z_l;

	int16_t accel_x, accel_y, accel_z;

	float x, y;
	
		for(int i = 0; i < 20; i++){
			accel_x_h = readRegister(OUT_X_H_XL);
			accel_x_l = readRegister(OUT_X_L_XL);

			accel_x = accel_x_h << 8;
			accel_x = accel_x | accel_x_l;
			
			x = accel_x / 32768.0;
			
			x += x;
		}

	x = x / 20;

	printf("Pitch is %f\n", x);


	/*unsigned char gyro_x_h, gyro_x_l, gyro_y_h, gyro_y_l, gyro_z_h, gyro_z_l;

	int16_t gyro_x, gyro_y, gyro_z;

	float x, y;
	
		for(int i = 0; i < 20; i++){
			gyro_x_h = readRegister(OUT_X_H_G);
			gyro_x_l = readRegister(OUT_X_L_G);

			gyro_x = gyro_x_h << 8;
			gyro_x = gyro_x | gyro_x_l;
			
			x = gyro_x / 32768.0 * 2000;
			
			x += x;
		}

	x = x / 20;
	for(int i = 0; i < 20; i++){
		gyro_y_h = readRegister(OUT_Y_H_G);
		gyro_y_l = readRegister(OUT_Y_L_G);

		gyro_y = gyro_y_h << 8;
		gyro_y = gyro_y | gyro_y_l;
			
		y = gyro_y / 32768.0 * 2000;
			
		y += y;
	}

	y = y / 20;


	gyro_z_h = readRegister(OUT_Z_H_G);
	gyro_z_l = readRegister(OUT_Z_L_G);

	gyro_z = gyro_z_h << 8 ;
	gyro_z = gyro_z | gyro_z_l;

	printf("Pitch is %f , Roll is %f\n", x, y);

	//printf("Pitch is 0x%04x  High is 0x%02x	 Low is 0x%02x\n", gyro_x, gyro_x_h, gyro_x_l);
	
	
	//printf("Roll  is 0x%04x  High is 0x%02x	 Low is 0x%02x\n", gyro_y, gyro_y_h, gyro_y_l);

	
	//printf("Pitch is 0x%04x  High is 0x%02x	 Low is 0x%02x\n\n", gyro_z, gyro_z_h, gyro_z_l);

	//printf("Pitch Low  is 0x%02x in Hex", gyro_x);
*/
	return 0;

}

int convertToSigned(int hex){

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

