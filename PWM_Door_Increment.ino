int H1=5;
int ledPin = 10;
int H2 = 9;
int val = 0;
int power;
bool rev;
bool maxpower = false;
bool switchSides = false;
bool lastRev = false;

void doorMove(bool rev) {
  if(rev) {
    if(lastRev != rev) {
      power = 0;
    }
    analogWrite(H2, 0);
    if(power<255) {
      power++;
      delay(20);
    } 
    Serial.println(power);
    analogWrite(H1, power);
    lastRev = rev;
  } else {
    if(lastRev != rev) {
      power = 0;
    }
     if(power<255) {
      power++;
      delay(20);
    } 
    analogWrite(H2, power);
    analogWrite(H1, 0);
    lastRev = rev;
  }

} 


void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, INPUT);
pinMode(H1, OUTPUT);
pinMode(H2, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(ledPin);
if(!val) {
  doorMove(true);
}
else {
  doorMove(false);
}

}
