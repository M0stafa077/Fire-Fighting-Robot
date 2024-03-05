#define RIGHT_KEY         'R'
#define LEFT_KEY          'L'
#define STOP_KEY          'S'
  
#define PUMP_KEY_1        'u'
#define PUMP_KEY_2        'U'
  
#define BUZZER_KEY_1      'v'
#define BUZZER_KEY_2      'V'
  
#define PUMP              7
  
#define BUZZER            10

uint8_t direction = 0;

void RC_mode(void)
{ 
  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (Serial.available()) 
  {
    direction = Serial.read();

    if ((FORWARD_KEY == direction))
      { RC_forward(); }
    
    else if ((BACKWARD_KEY == direction))
      { RC_backward(); }
    
    else if ((RIGHT_KEY == direction))
      { right(); }
    
    else if ((LEFT_KEY == direction))
      { left(); }
    
    else if ((STOP_KEY == direction))
      { stop(); }
    
    else if ((PUMP_KEY_1 == direction) || (PUMP_KEY_2 == direction))
      { RC_start_pump(); }
    
    else if ((BUZZER_KEY_1 == direction) || (BUZZER_KEY_2 == direction))
      { buzz(); }

    else
      { stop(); }
  }
}

void RC_start_pump(void)
{
  digitalWrite(PUMP, HIGH);

  lcd.setCursor(8, 0);
  lcd.print("ON ");

  move_servo();
  
  digitalWrite(PUMP, LOW);
  
  lcd.setCursor(8, 0);
  lcd.print("OFF");
  servo_motor.write(90);
}
