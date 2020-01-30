#include "dht.h"
#include <LiquidCrystal.h>
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
LiquidCrystal lcd(8, 2, 4, 5, 6, 7);
 
void setup(){
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  lcd.begin(16,2);
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed 
  lcd.print("Temp:   Humid:");
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    /*
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    */
    Serial.print("temperature = ");
    Serial.print(DHT.temperature * 1.8 + 32); 
    Serial.println("F  ");
    
   delay(3000); // 3 seconds delay 
   lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
   lcd.print(DHT.temperature * 1.8 + 32);
   lcd.setCursor(5,1);
   lcd.print('F');
   lcd.setCursor(8,1);
   lcd.print(DHT.humidity);
   lcd.setCursor(12,1);
   lcd.print('%');
   /*
   lcd.clear(); // Clears the display 
   lcd.blink(); //Displays the blinking LCD cursor 
   delay(4000); 
   lcd.setCursor(7,1); 
   delay(3000); 
   lcd.noBlink(); // Turns off the blinking LCD cursor 
   lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
   delay(4000); 
   lcd.noCursor(); // Hides the LCD cursor 
   lcd.clear(); // Clears the LCD screen
   */
 
  //Fastest should be once every two seconds.
 
}// end loop() 
