#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define BUZZER            10

#define RC_MODE           true
#define FF_MODE           false

#define RC_MODE_KEY       'W'
#define FF_MODE_KEY       'X'

#define FORWARD_KEY       'F'
#define BACKWARD_KEY      'B'

bool mode = RC_MODE;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo_motor;

void setup() 
{
  Serial.begin(9600);
  motors_init();
  fire_fighter_mode_init();
  
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("PUMP : ");
  lcd.setCursor(8, 0);
  lcd.print("OFF");
}

void loop() 
{  
  if(Serial.available())
  {
    char key = Serial.read();
    
    if( (RC_MODE_KEY == key) || (FORWARD_KEY == key) || (BACKWARD_KEY == key) )
      { mode = RC_MODE; }    
    else if ( FF_MODE_KEY == key )
      { mode = FF_MODE; }
    else
      { /* Nothing */ }
  }
  else
    { /* Nothing */ }

  if ( RC_MODE == mode )
    { RC_mode(); }
  else if ( FF_MODE == mode )
    { fire_fighter_mode(); }
  else
    { /* Nothing */ }
}

