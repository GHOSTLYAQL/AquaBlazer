/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include <Servo.h>
#define NUMMOTORS 4

typedef struct MotorDef
{
    Servo   Motor; 
    int     Pin;   // Indicates the Pin this motor is connected to
};

MotorDef Motors[NUMMOTORS];

typedef struct ESCSettingsDef
{
  int Low;
  int High;
};

ESCSettingsDef ESCSettings; 

// #define PROGRAM_MODE
// #define THROTTLE_MODE
#define NORMAL_MODE

int CurrentSpeed = 0;
//int Step = 10;



#define ESC_HIGH_DEFAULT 200
#define ESC_LOW_DEFAULT 20
int waterPump = 5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  Motors[0].Pin =  6;//FL
	Motors[1].Pin =  9;//FR
	Motors[2].Pin =  10;//RL
	Motors[3].Pin =  11;//RR

  for(int i = 0; i < NUMMOTORS; i++)
    {
      int pin = Motors[i].Pin;
      Motors[i].Motor.attach(pin);
    }
    // Motors[0].Motor.write(0);
    // Motors[1].Motor.write(0);
    // Motors[2].Motor.write(0);
    // Motors[3].Motor.write(0);
    pinMode(waterPump, OUTPUT);
    digitalWrite(waterPump, LOW);
  // Set the ESC settings to the defaults
	// ESCSettings.Low   = ESC_LOW_DEFAULT;
	// ESCSettings.High  = ESC_HIGH_DEFAULT;
  
  
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");

  if (GamePad.isUpPressed())//drone moves forward
  {
    Motors[0].Motor.write(120);
    Motors[1].Motor.write(120);
    Motors[2].Motor.write(130);
    Motors[3].Motor.write(130);
    Serial.print("UP");
  }

  else if (GamePad.isDownPressed())//drone moves backward
  {
    Motors[0].Motor.write(130);
    Motors[1].Motor.write(130);
    Motors[2].Motor.write(120);
    Motors[3].Motor.write(120);
    Serial.print("DOWN");
  }

  else if (GamePad.isLeftPressed())//drone moves left
  {
    Motors[0].Motor.write(120);
    Motors[1].Motor.write(130);
    Motors[2].Motor.write(120);
    Motors[3].Motor.write(130);
    Serial.print("Left");
  }

  else if (GamePad.isRightPressed())//drone moves right
  {
    Motors[0].Motor.write(130);
    Motors[1].Motor.write(120);
    Motors[2].Motor.write(130);
    Motors[3].Motor.write(120);
    Serial.print("Right");
  }

  else if (GamePad.isSquarePressed())//turn drone to the left
  {
    //Be sure to note the direction of the motor before changing values
    Motors[0].Motor.write(40);
    Motors[1].Motor.write(40);
    Motors[2].Motor.write(40);
    Motors[3].Motor.write(40);
    Serial.print("Square");
  }

  else if (GamePad.isCirclePressed())//turn drone right
  {
    //Be sure to note the direction of the motor before changing values
    Motors[0].Motor.write(40);
    Motors[1].Motor.write(40);
    Motors[2].Motor.write(40);
    Motors[3].Motor.write(40);
    Serial.print("Circle");
  }

  else if (GamePad.isCrossPressed())//lowers drone
  {
    Motors[0].Motor.write(100);
    Motors[1].Motor.write(100);
    Motors[2].Motor.write(100);
    Motors[3].Motor.write(100);
    Serial.print("Cross");
  }

  else if (GamePad.isTrianglePressed())//raises drone height
  {
    Motors[0].Motor.write(150);
    Motors[1].Motor.write(150);
    Motors[2].Motor.write(150);
    Motors[3].Motor.write(150);
    Serial.print("Triangle");
  }

  else if (GamePad.isStartPressed())//could be used to turn on/off the system: TBD
  {
    Motors[0].Motor.write(0);
    Motors[1].Motor.write(0);
    Motors[2].Motor.write(0);
    Motors[3].Motor.write(0);
    Serial.print("Start");
  }

  else if (GamePad.isSelectPressed())//could be used to shoot water from pump: TBD
  {
    Motors[0].Motor.write(0);
    Motors[1].Motor.write(0);
    Motors[2].Motor.write(0);
    Motors[3].Motor.write(0);
    digitalWrite(waterPump, HIGH);
    Serial.print("Select");
  }

  else
  {
    Motors[0].Motor.write(0);
    Motors[1].Motor.write(0);
    Motors[2].Motor.write(0);
    Motors[3].Motor.write(0);
    digitalWrite(waterPump, LOW);
  }
  Serial.print('\t');

  // int a = GamePad.getAngle();
  // Serial.print("Angle: ");
  // Serial.print(a);
  // Serial.print('\t');
  // int b = GamePad.getRadius();
  // Serial.print("Radius: ");
  // Serial.print(b);
  // Serial.print('\t');
  // float c = GamePad.getXaxisData();
  // Serial.print("x_axis: ");
  // Serial.print(c);
  // Serial.print('\t');
  // float d = GamePad.getYaxisData();
  // Serial.print("y_axis: ");
  // Serial.println(d);
  // Serial.println();
}
