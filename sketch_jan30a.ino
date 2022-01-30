
#define len(arr) sizeof (arr)/sizeof (arr[0])

const int leds[] = {5,6,7};
int currentLed = leds[0];

void setup() 
{
  Serial.begin(9600);
  
  for (int i = leds[0]; i <= leds[len(leds)-1]; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
    if(i == leds[0]) {
      digitalWrite(i, HIGH);
    }
  }
  currentLed = 5;
}

void loop() {
  for (int i = leds[0]; i <= leds[len(leds)-1]; i++) {
    if(i == currentLed) {
      digitalWrite(currentLed, HIGH);
      Serial.println("Turned on");
      Serial.println(currentLed);
    } else {
      digitalWrite(i, LOW);
      Serial.println("Turned off");
    }

    if(currentLed == 6) {
      digitalWrite(currentLed, LOW);
      delay(500);
      digitalWrite(currentLed, HIGH);
      delay(500);
      digitalWrite(currentLed, LOW);
    }
  }
  if(currentLed == 6) {
    digitalWrite(currentLed+1, HIGH);
    digitalWrite(currentLed, LOW);
    currentLed = leds[0];
  } else {
    currentLed = currentLed == leds[len(leds)-1] ? leds[0] : currentLed+1;
  }

    delay(2000);
}
