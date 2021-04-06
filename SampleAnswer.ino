int button;
int reqIntensity;
int Speed = 100;
int intensity;
void setup() {
pinMode(TXO, OUTPUT); //TRANSMITTER WIRELESS
pinMode(RXO,INPUT); //RECEIVER WIRELESS
pinMode(14,INPUT); //button
pinMode(5,OUTPUT); // GREEN LED
pinMode(10,OUTPUT); // YELLOW LED
pinMode(4,OUTPUT); // RED LED
pinMode(34,INPUT); // POTENTIOMETER
ledcAttachPin(36,1); // IN 1
ledcAttachPin(32,2); // IN 2
ledcAttachPin(33,3); // IN 3
ledcAttachPin(25,4); // IN 4
ledcSetup(1, 20000, 8); // 20mS PWM, 8-bit resolution
ledcSetup(2, 20000, 8);
ledcSetup(3, 20000, 8);
ledcSetup(4, 20000, 8);
}

void loop() {
 
 unsigned long currentMillis = millis();
 button = digitalRead(14);
 if(button == HIGH) // the motor runs only if switch is on
 {
  ledcWrite(1,Speed); // 
  ledcWrite(2,Speed); //
  ledcWrite(3,Speed); //
  ledcWrite(4,Speed); //
 }
 reqIntensity = map(analogRead(34), 0, 100, 0, 4095);
 intensity = map(analogRead(RXO), 0, 100, 0, 4095);
 if (intensity> (1.1*reqIntensity))
 {
  Speed = Speed - 10;
  digitalWrite(4,HIGH); //
  digitalWrite(5,LOW); //
  digitalWrite(10,LOW); //
 }
 else if( intensity < (0.9*reqIntensity))
 {
  Speed = Speed - 10;
  digitalWrite(10,HIGH); //
  digitalWrite(5,LOW); //
  digitalWrite(4,LOW); //
 }
 else
 {
  digitalWrite(5,HIGH); //
  digitalWrite(4,LOW); //
  digitalWrite(10,LOW); //
 }

}
