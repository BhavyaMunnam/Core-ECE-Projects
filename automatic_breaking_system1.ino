#include<Servo.h> //servo motor library

const int trigPin = 4;//DEFINE Trigger pin
const int echoPin = 5;//DEFINE Echo pin

long duration;// variable for travel time
int distance;// variable for distance

Servo servo; // naming the servo motor


int potPina = 0;//potentiometer connected to Analog pin 0
int vala; // variable to read the value from the analog pin 0
int valb = 179;// variable to hold maximum value of the servo motor

int potPinb = 1;//potentiometer to A1
int valx; // variable to read the value from the analog pin 1
 

// LED pin
 int led = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(10);// servo pin 
  pinMode(led, OUTPUT);// led as output
  Serial.begin(9600);// Serial communication to see the results on serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);// Trig pin is clear
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);// Generating the ultrasound wave
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// reading the travel time
duration = pulseIn(echoPin, HIGH);//put travel time value in variable duration
distance = duration * 0.034/2;//store the value of the distance 
// Printing the distance in the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance); 
Serial.println(" cm");
  // servo motor controlled by the potentiometer
vala = analogRead(potPina);   // reads the value of the
          // potentiometer (value between
          // 0 and 1023)
 vala = map(vala, 0, 1023, 0, 179);  // scale it to use it with
          // the servo (value between 0 and 179)
   // sets the servo position according
                        // to the scaled value
     // waits for the servo to get there
 Serial.print("Vala: ");
 Serial.print(vala);//vala = braking force or servo rotation
 Serial.print("; ");

 valx = analogRead(potPinb);   // reads the value of the
          // potentiometer (value between
          // 0 and 1023)
 valx = map(valx, 0, 1023, 0, 100);  // scale it to use it with
          // as the speed (value between 0 and 100)

 Serial.print("CarSpeed: ");
 Serial.print(valx);// valx = Carspeed
 Serial.print("; ");
 
switch(valx)// CarSpeed
{ 
  
  //1m = (0.5m) obstacle distance and speed of 5 Kmh
  case 1 ... 5   :// SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if ( distance <= 50 && vala == 0 && valx <= 5){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
   
  else if ( distance <= 50 && vala > 0 && valx <= 5 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
    //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
           break;
           
  //12m = (1.2m)obstacle distance and speed of 30 Kmh 
  case 6 ... 30  :   // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 120 && vala == 0 && valx <= 30){
   digitalWrite(led,HIGH);
   servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if(distance <= 120  && vala > 0 && valx <= 30 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
    //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
          break;
           
  //24m = (1.6m)obstacle distance and speed of 50 Kmh 
  case 31 ... 50  :   // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 160 && vala == 0 && valx <= 50){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if (distance <= 160 && vala > 0 && valx <= 50 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
    //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
          break;
  
  //37m = (2m)obstacle distance and speed of 65 Kmh
 
  case 51 ... 65  :  
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 200 && vala == 0 && valx <= 65){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if (distance <= 200 && vala > 0 && valx <= 65 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
     //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  } 
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
  break;
  
  //54m =(2.4m)obstacle distance and speed of 80 Kmh
  case 66 ... 80  : 
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 240 && vala == 0 && valx <= 80){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if (distance <= 240 && vala > 0 && valx <= 80 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
   //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }   
           break; 
  
  // 74m = (2.7m)obstacle distance and speed of 90 Kmh
  case 81 ... 90  : 
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 275 && vala == 0 && valx <= 90){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if (distance <= 275 && vala > 0 && valx <= 90 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
   //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
           break;
  
  // 97m  = (3m)obstacle distance and speed of 100 Kmh
  case 91 ... 100 : 
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS NOT APPLIED
  if (distance <= 300 && vala == 0 && valx <= 100){
    digitalWrite(led,HIGH);
    servo.write(valb);
  }
  // SIMULATING AUTOMATIC BRAKE SYSTEM IF THE BRAKE IS APPLIED BUT NOT TO THE MAXIMUM
  else if (distance <= 300 && vala > 0 && valx <= 100 ){
    for(int i = vala; i<= valb; i++){
      servo.write(valb);// servo to 179 degrees
    } 
    //BLYNK LED
    digitalWrite(led,HIGH);
    delay(300);
    digitalWrite(led,LOW); 
    delay(300);
  }  
  else
  {
     servo.write(vala);
     digitalWrite(led,LOW);
  }  
            break;
           
  default  : servo.write(vala);
             digitalWrite(led,LOW);
           break;                                                      
}
}