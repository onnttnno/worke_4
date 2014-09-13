#include<SoftwareSerial.h>
#define rxPin 18
#define txPin 18
SoftwareSerial MySerial = SoftwareSerial(rxPin,txPin);
int LeftSensor;
int RightSensor;

void setup(){
  digitalWrite(txPin,HIGH);
  pinMode(txPin,OUTPUT);
  MySerial.begin(9600);
  delay(1000);
}
void LCD_CMD(int Command){
  MySerial.write(0xFE);
  MySerial.write(Command);
}
void loop(){
  LeftSensor = analogRead(3);
  RightSensor = analogRead(1);
  LCD_CMD(0x80);
  MySerial.print("L Sensor=    ");
  LCD_CMD(0x8A);
  MySerial.print(LeftSensor,DEC);
  
  LCD_CMD(0xC0);
  MySerial.print("R Sensor=    ");
  LCD_CMD(0xCA);
  MySerial.print(RightSensor,DEC);
  delay(200);
  }
