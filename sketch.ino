#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pins za keypad kuri ESP32
byte rowPins[ROWS] = {14, 27, 26, 25}; 
byte colPins[COLS] = {33, 32, 4, 16};  

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LCD setup (I2C address ishobora kuba 0x27 cyangwa 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Buzzer pin
int buzzer = 12;

void setup() {
  Serial.begin(115200);

  // Buzzer setup
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sarah");   // Izina rigaragara kuri LCD

  // Buzzer isakuze nk’alert
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    // LCD yerekana key
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sarah");
    lcd.setCursor(0,1);
    lcd.print("Key: ");
    lcd.print(key);

    // Buzzer isakuze nk’alert
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
  }
}
