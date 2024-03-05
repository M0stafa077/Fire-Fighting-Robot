#define R_SENS            2
#define F_SENS            3
#define L_SENS            4
  
#define FIRE              0
#define NO_FIRE           1

uint8_t r_sensor_reading = NO_FIRE;
uint8_t f_sensor_reading = NO_FIRE;
uint8_t l_sensor_reading = NO_FIRE;

uint8_t fire_flag = NO_FIRE;

/* A software Interface setups 
  the fire fighter mode */
void fire_fighter_mode_init(void)
{
  pinMode(R_SENS, INPUT);
  pinMode(L_SENS, INPUT);
  pinMode(F_SENS, INPUT);
}

/* A software Interface puts the
  robot in the fire fighting mode */
void fire_fighter_mode(void)
{
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("NO Fire  ^_^     ");

  /* Read state from the flame sensors */
  read_sensors(); 
  /* Check where the fire is */ 

  /* 1. No fire */
  if((1 == r_sensor_reading) && (1 == f_sensor_reading) && (1 == l_sensor_reading))
    { stop(); }
  
  /* 2. Fire in the front */
  else if ( (0 == f_sensor_reading) && (1 == r_sensor_reading) && (1 == l_sensor_reading) )
  { 
    forward(); 
    fire_flag = FIRE;
    lcd.setCursor(0, 1);
    lcd.print("Fire Forward");
    buzz();
  }

  /* 3. fire at the right */
  else if ( 0 == r_sensor_reading && (1 == f_sensor_reading) && (1 == l_sensor_reading))
  {
    FF_backward();
    delay(50);
    FF_right(); 
    delay(300);
    lcd.setCursor(0, 1);
    lcd.print("Fire Right");
    buzz();
  }

  /* 4. fire at the left */
  else if ( 0 == l_sensor_reading && (1 == r_sensor_reading) && (1 == f_sensor_reading) )
  { 
    FF_backward();
    delay(50);
    FF_left(); 
    delay(300);
    lcd.setCursor(0, 1);
    lcd.print("Fire Left      ");
    buzz();
  }
  
  /* 5. fire in the front and at the right */
  else if ( (0 == f_sensor_reading) && (0 == r_sensor_reading) && (1 == l_sensor_reading) )
  { 
    fire_flag = FIRE;
    forward(); 
    lcd.setCursor(0, 1);
    lcd.print("Go Forward   ");
    buzz();
  }

  /* 6. fire in the front and at the left */
  else if ( 0 == l_sensor_reading && (1 == r_sensor_reading) && (0 == f_sensor_reading) )
  { 
    fire_flag = FIRE;
    forward(); 
    lcd.setCursor(0, 1);
    lcd.print("Go Forward");
    buzz();
  }
  
  /* 7. fire at the right and at the left */
  else if ( 0 == r_sensor_reading && (1 == f_sensor_reading) && (0 == l_sensor_reading))
  { 
    FF_backward();
    delay(50);
    FF_right();
    delay(50);

    lcd.setCursor(0, 1);
    lcd.print("Go Right");
    buzz();
  }
  
  /* 8. fire at all directions */
  else
  { 
    forward();
    fire_flag = FIRE;
    lcd.setCursor(0, 1);
    lcd.print("RUN!!");
    buzz();
  }

  while ( FIRE == fire_flag )
  { 
    /* Wait to reach the fire */
    delay(200);

    digitalWrite(BUZZER, LOW);

    /* Stop in front of the fire */
    stop();

    handle_fire();
  }
}

/* A software Interface handles the
  fire (if exists) */
void handle_fire()
{
  /* Check if the fire still exists */
  f_sensor_reading = digitalRead(F_SENS);
  
  /* Set the fire off */
  if( 0 == f_sensor_reading )
  {
    
    /* Start PUMP */
    digitalWrite(PUMP, HIGH);

    lcd.setCursor(8, 0);
    lcd.print("ON   ");

    /* move Servo */
    move_servo();

    /* Stop Pump */
    digitalWrite(PUMP, LOW);
    lcd.setCursor(8, 0);
    lcd.print("OFF");
  }
  else
    { fire_flag = NO_FIRE; lcd.setCursor(0, 1); lcd.print("Done :)   "); delay(100); return; }

  /* Check if the fire still exists */
  f_sensor_reading = digitalRead(F_SENS);
  if (0 == f_sensor_reading)
    { fire_flag = FIRE; return; }
  else
  { 
    /* Reset the fire flag */
    fire_flag = NO_FIRE;

    /* Get Back */
    /* 1. Move back */
    backward();
    /* 2. move the same distance */
    delay(300);
    /* 3. Stop the robot */
    stop();
  }    
}

/* A software Interface reads the state 
  of the flame sensors  */
void read_sensors(void)
{
  r_sensor_reading = digitalRead(R_SENS);
  f_sensor_reading = digitalRead(F_SENS);
  l_sensor_reading = digitalRead(L_SENS);
}

void buzz()
{
  digitalWrite(BUZZER, HIGH);
  delay(20);
  digitalWrite(BUZZER, LOW);
  delay(10);
  digitalWrite(BUZZER, HIGH);
  delay(20);
  digitalWrite(BUZZER, LOW);
}
