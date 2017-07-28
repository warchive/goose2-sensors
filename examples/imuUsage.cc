/*!
 * @file
 * @author Deep Dhillon
 * @date July 27, 2017
 * @brief This file shows an example of how to use IMU sensor in this library
 */

#include <imu/SparkfunIMU.h>
#include <imu/Accel.h>
#include <imu/Gyro.h>
#include <imu/Mag.h>

// create raw imu
SparkfunIMU rawImu; // provide addresses (optional)

// create imu sub sensor objects
Accel accel{"accel", 60, rawImu};
Gyro gyro{"gyro", 60, rawImu};
Mag mag{"mag", 60, rawImu};

void setup(){
	// begin serial
	wlp::serial.begin(115200);

	// start the raw imu
	if (rawImu.begin()){
		wlp::serial << "Success" << wlp::endl;
	} else{
		wlp::serial << "Not Working" << wlp::endl;
	}

	// adjust different settings for each component. Look at documentation of
	// each component to get list of methods available
	accel.setSampleRate(6);
	gyro.flipY();
	mag.setMagPerformance(3);
}

void loop(){
	// these reads return 1 or 0 based on if the read was successful
	accel.read();
	gyro.read();
	mag.read();

	// obtain different set of values separately
	float ax = accel.getX();
	float ay = accel.getY();
	float az = accel.getZ();

	float mx = mag.getX();
	float my = mag.getY();
	float mz = mag.getZ();

	// get specific values based on sensor components
	float rool = accel.getRoll(ay, az);
	float pitch = accel.getPitch(ax, ay, az);
	float g = mag.getHeading(mx, my);
}
