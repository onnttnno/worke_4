#include <SoftwareSerial.h>
#include <stdlib.h>
#define rxPin 18
#define txPin 18
SoftwareSerial MySerial = SoftwareSerial (rxPin,txPin);
const int numReadings= 10;
int gp2;
float distance;
int readings[numReadings];
int index = 0; 
int total = 0;                  
int A = 0;                

void setup()
{  
  pinMode(txPin,OUTPUT);
  MySerial.begin(9600);
  delay(1000);
}
 void LCD_CMD(int Command){
 MySerial.write(0xFE);
 MySerial.write(Command); 
}
void loop(){
  gp2=analogRead(2);
  distance=(2914/(gp2+5))-1;
  LCD_CMD(0x80);
  MySerial.print("Distance=    ");
  LCD_CMD(0x8A);
  MySerial.print(distance,DEC);
  
  LCD_CMD(0xC0);
  A = 0.8*A + 0.2*analogRead(gp2);
  MySerial.print("Damping=    ");
  LCD_CMD(0xCA);
  MySerial.print(A,DEC);
  LCD_CMD(0xCE);
  MySerial.print("CM");
  delay(200);
}
