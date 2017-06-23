#include "COLOR_SENSOR.h"
#include "shared/DataHandler.h"

Color_Sensor::Color_Sensor() {
  int Out1 = 0;
  int temp = Out1;
  int Out2 = 0;
  int Out3 = 0;
  int count = 0;
} 

Color_Sensor::~Color_Sensor() {}

void Color_Sensor::get_limitOut1(){
    Out1 = analogRead(1);
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    if (Out1 >= 1000)
    {
        Out1 = 1;
    }else
    {
        Out1 = 0;
    }
}

void Color_Sensor::get_limitOut2(){
 Out2 = analogRead(2);
   //Limiting outputs to 0 & 1, instead of 0 - 1023
   if(Out2 >= 1000)
    {
      Out2 = 1;
    }else
    {
      Out2 = 0;
    }
}

void Color_Sensor::get_limitOut3(){
Out3 = analogRead(3);
   //Limiting outputs to 0 & 1, instead of 0 - 1023
    if(Out3 >= 1000)
   {
    Out3 = 1;
   }else
   {
    Out3 = 0;
   }
}

void Color_Sensor::counter() {
   //2 loops that look at the change from Out1 == 0 to Out1 == 1, to count the # of times the orange stripe has been 'seen' by the sensor

   Serial.begin(9600);
   float colorData = new float(4); 
   
  if(Out1 == 1 && Out2 == 0 && Out3 == 0)
  {
    if(temp == 0)
    {
      count++;
      temp = Out1;
    }else if(temp == 1)
    {
      temp = Out1;
    }
  }

  if(Out1 == 0 && Out2 == 0 && Out3 == 0)
  {
    if(temp == 0)
    {
      temp = Out1;
    }else if(temp == 1)
    {
      count++;
      temp = Out1;
    }
  }

  String sensor_name = Color
  
  colorData[0] = Out1, 
  colorData[1] = Out2;
  colorData[2] = Out 3;
  colorData[3] = count;

  Serial.println(data_handler.getJSONString(sensor_name, colorData, 4));
  
  delete [] colorData;
  
}




