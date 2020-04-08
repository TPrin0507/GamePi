#include "inputlib.h"

using namespace std;

int filedev, index;
struct input_event inputevent[64];

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
	
	int readdev;
	readdev = read(filedev, inputevent, sizeof(SIZESTRUCT) * 64);

	if(readdev < (int) sizeof(SIZESTRUCT)){
		perror("Error while reading from file - device lost?");
		closeInputfile();
		return;
	}
	else{
	
		for(index = 0; index < readdev / SIZESTRUCT; index++){
			if(inputevent[index].type == EV_KEY){
			
				switch(inputevent[index].value){
				
					case 0: cout << getKey()  << " Key Released" << endl;
						break;

					case 1: cout << getKey() << " Key Pressed" << endl;
						break;

					case 2: cout << getKey() << " Key Hold" << endl;
						break;

					default: perror("Unknown Code");
						 return;
				
				}
			
			}
		}
	
	}
}

string getKey(){
	switch(inputevent[index].code){
		case 103: return "Up";
			  break;
	
		case 108: return "Down";
			  break;

		case 106: return "Right";
			  break;

		case 105: return "Left";
			  break;

		case 28: return "Enter";
			 break;

		default: perror("Error while getting Key Code");
			 return NULL;
	}

	
}

void closeInputfile(){
	
	close(filedev);

}
