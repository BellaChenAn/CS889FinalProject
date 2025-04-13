const int LED_PIN1 = 47;
const int LED_PIN2 = 2;
const int LED_PIN3 = 42;
const int LED_PIN4 = 41;
const int LED_PIN5 = 40;
const int LED_PIN6 = 38;
const int LED_PIN7 = 4;
const int LED_PIN8 = 5;
const int LED_PIN9 = 6;
const int LED_PIN10 = 7;
const int LED_PIN11 = 15;
const int LED_PIN12 = 39;

const int group1[] = {LED_PIN1, LED_PIN8, LED_PIN11};
const int group2[] = {
  LED_PIN2, LED_PIN3, LED_PIN4, LED_PIN5,
  LED_PIN6, LED_PIN7, LED_PIN9, LED_PIN10, LED_PIN12
};

unsigned long lastGroup1Time = 0;
unsigned long lastGroup2Time = 0;

bool group1State = false;  // Indicates whether group1 LEDs are currently on
const unsigned long group1Interval = 1000;  // Blink every 1 second
const unsigned long group2Interval = 4000;  // Light up once every 4 seconds

void setup() {
  Serial.begin(115200);

  // Set all pins as output
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  pinMode(LED_PIN4, OUTPUT);
  pinMode(LED_PIN5, OUTPUT);
  pinMode(LED_PIN6, OUTPUT);
  pinMode(LED_PIN7, OUTPUT);
  pinMode(LED_PIN8, OUTPUT);
  pinMode(LED_PIN9, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
  pinMode(LED_PIN11, OUTPUT);
  pinMode(LED_PIN12, OUTPUT);

  // Initialize all LEDs to off
  for (int i = 1; i <= 12; i++) {
    digitalWrite(i, LOW);
  }

  randomSeed(analogRead(0));  // Initialize random seed
}

void loop() {
  unsigned long currentTime = millis();

  // group1 blinks every 1 second
  if (currentTime - lastGroup1Time >= group1Interval) {
    group1State = !group1State;
    for (int i = 0; i < 3; i++) {
      digitalWrite(group1[i], group1State ? HIGH : LOW);
    }
    lastGroup1Time = currentTime;
  }

  // group2 randomly lights up one LED every 4 seconds
  if (currentTime - lastGroup2Time >= group2Interval) {
    int randomIndex = random(0, sizeof(group2) / sizeof(group2[0]));
    int selectedPin = group2[randomIndex];

    digitalWrite(selectedPin, HIGH);
    delay(200);  // Stay on for 200 milliseconds
    digitalWrite(selectedPin, LOW);

    lastGroup2Time = currentTime;
  }
}
