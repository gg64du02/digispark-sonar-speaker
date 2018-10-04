 
#include <NewPing.h> //Iclud Arduino Pin Library

#define TRIGGER_PIN 1 //HCR04 Trigger set to pin 3
#define ECHO_PIN 0 // HCR04 Echo set to Pin 5
#define SPEAKER_PIN 2 // HCR04 Echo set to Pin 5
#define LED_PIN 1 // onboard led

#define DISTANCE 60 // Distance value

NewPing sonar(TRIGGER_PIN, SPEAKER_PIN, DISTANCE);

void setup() {
    pinMode(SPEAKER_PIN, OUTPUT); 
    //trigger pin      
    pinMode(LED_PIN, OUTPUT); 
    //trigger pin           
    
    //echo pin
    pinMode(ECHO_PIN, INPUT);  
    //P0, P1, and P4 are capable of hardware PWM (analogWrite).
    //0 is P0, 1 is P1, 4 is P4 - unlike the analog inputs, 
                        //for analog (PWM) outputs the pin number matches the port number.         
    pinMode(TRIGGER_PIN, OUTPUT);   

    // Clears the trigPin
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    
}

void tone_gg(int speaker, int freq){

    int i = 0;
    for(i = 0;i<255 ;i++){
      digitalWrite(speaker, HIGH);   // sets the pin on
      delayMicroseconds(1000000/freq);        // pauses for 50 microseconds
      digitalWrite(speaker, LOW);    // sets the pin off
      delayMicroseconds(1000000/freq);        // pauses for 50 microseconds
      //delayMicroseconds(50);        // pauses for 50 microseconds
    }

    
}

long duration;
int distance;
//
int timer;


void loop() {
  timer = 300;
  int timy = 0;
  while(1){
    
    //1000 works
    //200 works
    //50 works
    //delay(ms)
    delay(1);
    digitalWrite(TRIGGER_PIN, HIGH);
    //delay(ms)
    delay(1);
    digitalWrite(TRIGGER_PIN, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(ECHO_PIN, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    
    if(timy == timer){
      if(distance<10){
        tone_gg(SPEAKER_PIN, 3000);
      }
      timy = 0;
    }
    
    timy++;
  }
}




