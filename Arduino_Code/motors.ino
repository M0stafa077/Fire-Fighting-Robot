#define MOTOR_L_EN        6
#define MOTOR_L_F         8
#define MOTOR_L_B         9
#define MOTOR_R_EN        11
#define MOTOR_R_F         12
#define MOTOR_R_B         13
  
#define SERVO_MOTOR       5
  
#define PUMP              7

/* A software Interface intializes 
  the motors' pins */
void motors_init(void)
{
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
  pinMode(MOTOR_R_EN, OUTPUT);

  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_L_EN, OUTPUT);

  pinMode(PUMP, OUTPUT);
  
  pinMode(BUZZER, OUTPUT);
  servo_motor.attach(SERVO_MOTOR);
  servo_motor.write(90);
}

/* A software Interface moves the
  robot forward */
void forward(void)
{
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);

  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);

  analogWrite(MOTOR_R_EN, 130);
  analogWrite(MOTOR_L_EN, 130);
}

/* A software Interface moves the
  robot forward */
void RC_forward(void)
{
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);

  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);

  analogWrite(MOTOR_R_EN, 255);
  analogWrite(MOTOR_L_EN, 255);
}

/* A software Interface moves the
  robot backward */
void backward(void)
{
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);

  analogWrite(MOTOR_R_EN, 130);
  analogWrite(MOTOR_L_EN, 130);
}

/* 
  A software Interface moves the robot to the backward
  (dedicated for the fire fighter mode)
 */
void FF_backward(void)
{
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);

  analogWrite(MOTOR_R_EN, 150);
  analogWrite(MOTOR_L_EN, 150);
}

/* 
  A software Interface moves the
  robot backward 
*/
void RC_backward(void)
{
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);

  analogWrite(MOTOR_R_EN, 255);
  analogWrite(MOTOR_L_EN, 255);
}

/* 
  A software Interface moves the
  robot left 
*/
void right(void)
{ 
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);

  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  
  analogWrite(MOTOR_R_EN, 100);
  analogWrite(MOTOR_L_EN, 130);
}

/* 
  A software Interface moves the robot to the right
  (dedicated for the fire fighter mode)
*/
void FF_right(void)
{ 
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, HIGH);

  digitalWrite(MOTOR_L_F, HIGH);
  digitalWrite(MOTOR_L_B, LOW);
  
  analogWrite(MOTOR_R_EN, 65);
  analogWrite(MOTOR_L_EN, 85);
}

/* 
  A software Interface moves
  the robot left 
*/
void left(void)
{
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  
  analogWrite(MOTOR_R_EN, 130);
  analogWrite(MOTOR_L_EN, 100);
}

/* 
  A software Interface moves the robot to the left
  (dedicated for the fire fighter mode)
*/
void FF_left(void)
{
  digitalWrite(MOTOR_R_F, HIGH);
  digitalWrite(MOTOR_R_B, LOW);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_L_B, HIGH);
  
  analogWrite(MOTOR_R_EN, 85);
  analogWrite(MOTOR_L_EN, 65);
}

/* 
  A software Interface Stops 
  the robot 
*/
void stop(void)
{
  digitalWrite(MOTOR_R_F, LOW);
  digitalWrite(MOTOR_R_B, LOW);

  digitalWrite(MOTOR_L_F, LOW);
  digitalWrite(MOTOR_R_B, LOW);

  analogWrite(MOTOR_R_EN, 0);
  analogWrite(MOTOR_L_EN, 0);
}

/* 
  A software interface moves the servo motor
  to interact with the fire 
*/
void move_servo(void)
{
  for (uint8_t pos = 40; pos <= 140; pos += 1) 
  { 
    servo_motor.write(pos); 
    delay(10);  
  }

  for (uint8_t pos = 140; pos >= 40; pos -= 1) 
  { 
    servo_motor.write(pos); 
    delay(10);
  }
  
  for (uint8_t pos = 40; pos <= 90; pos += 1) 
  { 
    servo_motor.write(pos); 
    delay(10);
  }
}
