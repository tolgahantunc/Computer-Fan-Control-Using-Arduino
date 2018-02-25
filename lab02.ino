#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

volatile float time = 0;
volatile float time_last = 0;
volatile float c = 0;
void setup()
{
  //Digital Pin 2 Set As An Interrupt
 attachInterrupt(0, fan_interrupt, FALLING);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Current RPM:");
}

//Main Loop To Calculate RPM and Update LCD Display
void loop()
{
  int rpm = 0;
  
  while(1){    
  //Slow Down The LCD Display Updates
  delay(400);
  
  //Clear The Bottom Row
  lcd.setCursor(0, 1);
  lcd.print("                ");
 
  
  //Update The Rpm Count
  lcd.setCursor(0, 1);
  lcd.print(rpm);   

  //analogWrite(6,32);
  //lcd.setCursor(4, 1);
  //lcd.print(time);   

  //Update The RPM
  if(time > 0)
  {
    //5 Sample Moving Average To Smooth Out T
     rpm = 60*(1000000/(time*7));
    }
 
 }
}

//Capture The IR Break-Beam Interrupt
void fan_interrupt()
{
   time = (micros() - time_last); 
   time_last = micros();
}
