#include <Arduimo.h>
const tombolPin = 2;
const segemenPin = {7,6,5,11,10,8,9,4};

const int ledMerah = 12;
const int ledHijau = 13;

byte angkaPin[10][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}  //9
};

bool lastUpState = HIGH;


void tampilAngka(num){
  for(int i=0; i<8; i++)
  {
    digitalWrite(segemenPin[i], !angkaPin[num][i]);
  }
}
void setup() {
  // put your setup code here, to run once:
   for(int i=0; i<8; i++){
    pinMode(segemenPin[i], OUTPUT);
  }

  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  
  pinMode(tombolPin, INPUT_PULLUP);

  
  digitalWrite(ledMerah, High);
  digitalWrite(ledHijau, LOW);

  tampilAngka(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool upState = digitalRead(tombolPin);

  if(lastUpState == HIGH && upState == LOW){

    digitalWrite(ledMerah, HIGH);

    for(int i=10; i>=0; i--){

      tampilAngka(i);
      digitalWrite(ledHijau, High);
      digitalWrite(ledMerah, LOW);
      delay(1000);
    }

    tampilAngka(0);
  }
    lastUpState = upState;

}
