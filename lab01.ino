#include <LiquidCrystal.h> // include the LCD library
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int potPin = A0; //Potentiometer input pin
int potValue1 = 0;
int potValue2 = 0; // final display variable
void setup() {
    lcd.begin(16, 2); // lcd rows and columns
    lcd.print("maraba televole"); // title of sorts
}

void loop() {
// read then divide the input(max 1020 in this case) by 10
    potValue1 = analogRead(potPin) / 10;
// divide by 1.02 to get percentage
    potValue2 = potValue1 / 1.02;
// set cursor to second row, first column
    lcd.setCursor(0, 1);
//display final percentage
    lcd.print(potValue2);
//print the percent symbol at the end
    lcd.print("%");
//wait 0.1 seconds
    delay(100);
//wipe the extra characters
    lcd.print(" ");
    delay(1);
}  
