#include <Adafruit_CircuitPlayground.h>


int sensorValue;
float voltage;
int stretch;
int lights;

int wait = 200;
int curTime = 0;
int lastChange = 0;

int r = 0;
int g = 0;
int b = 0;

void setup() {
  CircuitPlayground.begin();

  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop() {
  curTime = millis();
 

  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A3);
  Serial.println("sensorValue: " );
  Serial.println(sensorValue);
  Serial.println();
  Serial.println("stretch: " );
  Serial.println(stretch);
  Serial.println(lastChange);
 Serial.println("-------------------------");
 
  voltage = sensorValue * (3.3 / 1023);

  r = map(sensorValue, 350, 750, 0, 255);
  g = map(sensorValue, 350, 550, 255, 0);
  b = map(sensorValue, 650, 750, 0, 255);
  //lights = map(sensorValue, 320, 750, 0, 9);

  stretch = constrain(sensorValue, 350, 750);
  
  if (sensorValue >= 350 ) {
    // forloop igennem Neolys for at ændre alle
    for (int i = 0; i < 9; i++) {
      //sat tid på for at give animationseffekt
   // if (curTime >= lastChange + wait) {
      CircuitPlayground.setPixelColor(i, r, g, b);
      lastChange = curTime;
    }
      
    
  } else {
    CircuitPlayground.clearPixels();
  }
  CircuitPlayground.clearPixels();
  
 

}
