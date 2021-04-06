int button;
int reqIntensity;
int Speed = 100;  // setting a starting speed
int intensity;
void setup() {
pinMode(TXO, OUTPUT); //TRANSMITTER WIRELESS
pinMode(RXO,INPUT); //RECEIVER WIRELESS
pinMode(14,INPUT); //button
pinMode(5,OUTPUT); // GREEN LED
pinMode(10,OUTPUT); // YELLOW LED
pinMode(4,OUTPUT); // RED LED
pinMode(34,INPUT); // POTENTIOMETER
ledcAttachPin(36,1); // IN 1 assigning pins to channels
ledcAttachPin(32,2); // IN 2
ledcAttachPin(33,3); // IN 3
ledcAttachPin(25,4); // IN 4
ledcSetup(1, 20000, 8); // 20mS PWM, 8-bit resolution
ledcSetup(2, 20000, 8);
ledcSetup(3, 20000, 8);
ledcSetup(4, 20000, 8);
}

void loop() {
 
 button = digitalRead(14);
 if(button == HIGH) // the motor runs only if switch is on
 {
  ledcWrite(1,Speed); // all the channels are running in the same direction at same speed
  ledcWrite(2,Speed); // assuming treadmills motors wont be required to run at different directions
  ledcWrite(3,Speed); //
  ledcWrite(4,Speed); //
 }
 reqIntensity = map(analogRead(34), 0, 100, 0, 4095); // the required intensity is set through the potentiometer
 intensity = map(analogRead(RXO), 0, 100, 0, 4095); //the intensity is read by the wireless transmitter
 if (intensity> (1.1*reqIntensity)) // if the intensity is 10 percent greater than required intensity
 {
  Speed = Speed - 10; //speed lowered by 10 units
  digitalWrite(4,HIGH); // red light on
  digitalWrite(5,LOW); //
  digitalWrite(10,LOW); //
 }
 else if( intensity < (0.9*reqIntensity)) // intensity is less than 10 percent of required intensity
 {
  Speed = Speed + 10; //increase speed
  digitalWrite(10,HIGH); // yellow light on
  digitalWrite(5,LOW); //
  digitalWrite(4,LOW); //
 }
 else // otherwise the intensity has to be within 10 percent of the required intensity, no changes to speed
 {
  digitalWrite(5,HIGH); // green light on
  digitalWrite(4,LOW); //
  digitalWrite(10,LOW); //
 }

}
