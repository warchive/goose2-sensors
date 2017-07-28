/*!
 * @file
 * @author Deep Dhillon
 * @date July 27, 2017
 * @brief This file shows an example of how to use sensors in this library
 */

#include <SensorPool.h>
#include <color/ColorSensor.h>
#include <pins_arduino.h>
#include <memory/SRAM.h>
#include <temp/LM35.h>

/*!
 * All sensors need few parameters to work:
 * 1) Name of the sensor
 * 2) Frequency of the sensor (read and write per second)
 * 3) Multiple parameters for pins needed for that sensor (0 or more)
 *
 * All sensors provide two ways to access data:
 * 1) Using getters provided by each sensor (read returns value for some sensors)
 * 2) Using output operator (<<) defined for each sensor
 *
 * To gather data do following:
 * 1) use the read method to read the sensor. Some sensors will return the value
 * 	  read while some sensors will return the status of read. If a sensor does
 * 	  not return value through read, it will provide getters to do so
 *
 * Organizing sensors:
 * 1) To organize multiple sensors, SensorPool class is provided. You can add
 * 	  sensors to the pool and then get each sensor using [] operator. If you just
 * 	  want to print the data, call read on the pool and it will read all the sensor.
 * 	  Then you can use the output operator to print the value of each sensor (JSON format).
 *
 * 	  Note: SensorPool should be used mostly if you do not care about storing the read
 * 	  		values and care more about printing them. In case you need to access individual
 * 	  		method of the sensor, use getSensor method to get object of that particular type
 * 	  		and then you can call those specific methods.
 */

// define Sensor Pool to manage multiple sensors
SensorPool pool;

// create objects of sensors
ColorSensor color{"color", 10, A0, A1, A2};
SRAM ram{"ram", 2};
LM35 contactTemp{"contactTemp", 5, A3};

void setup(){
	// initialize serial
	wlp::serial.begin(115200);

	// add sensors to the pool
	pool.add(&color);
	pool.add(&ram);
	pool.add(&contactTemp);
}

void loop(){
	pool.read();         // read does not return anything
	wlp::serial << pool; // end line already taken care of

	// access individual sensors using []
	pool[0].read();      // read color sensor

	// gives access to the actual specific object than just giving a Sensor object
	// use this with caution as this may result in invalid casting if used incorrectly
	pool.getSensor<ColorSensor>(0);
}
