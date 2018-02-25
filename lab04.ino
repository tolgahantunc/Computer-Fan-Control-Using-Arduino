#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

volatile float time = 0;
volatile float time_last = 0;
volatile float half_pwm = 127;
volatile float error;
volatile float old_error=0;
volatile float kp=0.4714; //4.05/8.59;
volatile float ki=0.16;

void setup()
{
  //Digital Pin 2 Set As An Interrupt
 attachInterrupt(0, fan_interrupt, FALLING);

}

//Main Loop To Calculate RPM and Update LCD Display
void loop()
{
  //Serial.begin(9000);
  int rpm = 0, half_rpm = 1200;
  float curr_pwm = half_pwm;
  float duty_cycle=0;
  
  while(1){ 
  //error calculation   
  error=(half_rpm-rpm);
  //pi control line
  curr_pwm=error*kp + old_error*ki;

  //these conditions are bounding pwm value betweem 0 and 255
  if(curr_pwm<0)
  curr_pwm=0;

  else if(curr_pwm>255)
  curr_pwm=255;
  
    //Slow Down The LCD Display Updates
  delay(100);
   lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(rpm);

  //Clear The Bottom Row
  lcd.setCursor(0, 1);
  lcd.print("                ");
 
  
  lcd.setCursor(0, 1);
  //calculate duty cycle as percentage
  duty_cycle=(curr_pwm/255)*100;
  
  lcd.print(curr_pwm);

  analogWrite(3,curr_pwm);  
  
  //Update The RPM
  if(time > 0)
  {
     rpm = 60*(1000000/(time*7));
    }
    //calculating the old error (the cumulative error)
    old_error=old_error+error;
    //Serial.println(old_error);
 
 }
}
//fan interrupt function
void fan_interrupt()
{
   time = (micros() - time_last); 
   time_last = micros();
}
