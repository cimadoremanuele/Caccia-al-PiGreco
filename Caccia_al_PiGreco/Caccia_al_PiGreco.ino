#include <LiquidCrystal_I2C.h>

String simbolo;
int a; //attribuisco un valore da 0 a 6 a questa variabile con un random, per decidere se metto bonus, malus oppure niente
int posizione;
int tempo;
int tempo2;
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
  btn1 = 1;
  btn2 = 2;
  btn3 = 3;
  btn4 = 4;
  btn5 = 5;
  tempo2 = 1500;
  simbolo = "";
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
    tempo = 1500;
    delay(tempo);
    int Array[] = {2, 5, 8, 11, 14};
    posizione = random(0, 4);
    lcd.setCursor(1, Array[posizione]);
    a = random(0,6);
    if (a == 0)
    {
      //simbolo = m; //malus
      lcd.print(simbolo);
    }
    else if (a == 1)
    {
      //simbolo = b; //bonus
      lcd.print(simbolo);
    }
    else
    {
      //simbolo = π; //piGreco
      lcd.print(simbolo);
    }
    int var = 0;
    while (var < tempo2)
    {
      if (a == 0)
      {
        ControllaBottoni();
      }
      else if ()
    }
  }
}
void ControllaBottoni()
{
  int b = 1;
  while (b < 6)
  {
    String s = "btn" + b;
    int btn = s.toInt();
    if (digitalRead(btn) == HIGH)
    {
      vite--;
      tempo2 = tempo2 - 30;
    }
  }
}
