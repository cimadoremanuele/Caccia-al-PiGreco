#include <LiquidCrystal_I2C.h>

String simbolo;
int posizione;
int tempo;
int vite;
int punti;
int record;
int btnStart;
int btn1;
int btn2;
int btn3;
int btn4;
int btn5;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(btnStart, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(btnStart) == HIGH)
  {
    delay(tempo)
    posizione = random(1, 5);
  }
}
