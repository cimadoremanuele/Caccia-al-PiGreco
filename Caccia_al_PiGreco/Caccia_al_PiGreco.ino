#include <LiquidCrystal_I2C.h>

String simbolo;
int a; //attribuisco un valore da 0 a 6 a questa variabile con un random, per decidere se metto bonus, malus oppure niente
int posizione;
int tempo;
int vite;
int punti;
int record;
int var;
int btnRecord;
int btnStart;
int btn1;
int btn2;
int btn3;
int btn4;
int btn5;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  var = 0;
  btn1 = 1;
  btn2 = 2;
  btn3 = 3;
  btn4 = 4;
  btn5 = 5;
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
  tempo = 1500;
  while (vite < 0)
  {
    if (digitalRead(btnStart) == HIGH)
    {
      delay(1500);
      int Array[] = {2, 5, 8, 11, 14};
      posizione = random(0, 4);
      lcd.setCursor(1, Array[posizione]);
      a = random(0,6);
      if (a == 0)
      {
        simbolo = "m"; //malus
        lcd.print(simbolo);
      }
      else if (a == 1)
      {
        simbolo = "b"; //bonus
        lcd.print(simbolo);
      }
      else
      {
        simbolo = "π"; //piGreco
        lcd.print(simbolo);
      }
      while (var < tempo)
      {
        int b = 0;
        if (a == 0)
        {
          while (b < 5)
          {
            ControllaBottoni(vite--, punti--, tempo - 30, b);
            b++;
          }
        }
        else if (a == 1)
        {
          b = posizione;
          ControllaBottoni(vite++, punti, tempo + 30, b);
        }
        else
        {
          b = posizione;
          ControllaBottoni(vite, punti++, tempo + 30, b);
        }
        var += 1;
      }
    }
  }
  if (punti > record)
  {
    record = punti;
  }
}
void PrimaRiga(int vita, int Punti)
{
  lcd.setCursor(0,0);
  lcd.print("Vite=" + vita);
  lcd.setCursor(0,9);
  lcd.print("Punti="+ Punti);
}
void ControllaBottoni(int vita, int Punti, int Tempo, int b)
{
  String s = "btn" + b;
  int btn = s.toInt();
  if (digitalRead(btn) == HIGH)
  {
    Punti;
    vita;
    Tempo;
    var = tempo;
  }
}
