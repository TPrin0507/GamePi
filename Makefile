LDFLAGS += \
	  -lRTIMULib

test:	test.cpp gyrolib.cpp displaylib.cpp inputlib.cpp	

RTIMULibDrive11: RTIMULibDrive11.cpp

clean: 
	rm test
