#include "inputlib.h"

int filedev;

void openInputfile(){
	int version;
	unsigned short id[4];
	unsigned long bit[EV_MAX][NBITS(KEY_MAX)];


	//open device file
	if((filedev = open("/dev/input/event0", O_RDONLY)) < 0){
		perror("Can't open input device");
		close(filedev);
		return;
	}
}

void readInputfile(){
	
	int readdev, index;
	struct input_event inputevent[64];
	readdev = read(filedev, inputevent, sizeof(SIZESTRUCT) * 64);

	if(readdev < (int) sizeof(SIZESTRUCT)){
		perror("Error while reading from file - device lost?");
		closeInputfile();
		return;
	}
	else{
	
	printf("Vor Ausgabe");
	
		for(index = 0; index < readdev / SIZESTRUCT; index++){
			if(inputevent[index].type == EV_KEY){
			
				switch(inputevent[index].value){
				
					case 0: printf("%i Key Released\n", imputevent[]);
						break;

					case 1: printf("Key Pressed\n");
						break;

					case 2: printf("Key Hold\n");
						break;

					default: perror("Unknown Code");
						 return;
				
				}
			
			}
		}
	
	}
}

void closeInputfile(){
	
	close(filedev);

}
