#include <LiquidCrystal_I2C.h>

String simbolo;
String simbolo2;
int a; //attribuisco il valore 0 o 1 o 2 a questa variabile con un random, per decidere se metto bonus, malus oppure niente
int posizione;
int posizione2;
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
  simbolo = π;
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
    tempo = random(1000, 3000);
    delay(tempo);
    int Array[] = {2, 5, 8, 11, 14};
    posizione = random(0, 4);
    posizione = Array[posizione];
    lcd.setCursor(1, posizione);
    lcd.print(simbolo)
    int c = 0;
    int Array2[4];
    for (int i = 0; i < 5; i++)
    {
      if (posizione != Array[i])
      {
        Array2[c] = Array[i];
        c++;
      }
      else
      {
        
      }
    }
    a = random(0,2);
    if (a == 0)
    {
      //no simbolo extra
    }
    else if (a == 1)
    {
      simbolo2 = b; //bonus
      posizione2 = random(Array2);
      lcd.setCursor(1, posizione2);
      lcd.print(simbolo2);
    }
    else
    {
      simbolo2 = m; //malus
      posizione2 = random(Array2);
      lcd.setCursor(1, posizione2);
      lcd.print(simbolo2);
    }
  }
}
