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
bool corretto;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  var = 0;
  vite = 5;
  punti = 0;
  btnStart = 5;
  btnRecord = 6;
  btn1 = 9;
  btn2 = 10;
  btn3 = 11;
  btn4 = 12;
  btn5 = 13;
  a = 0;
  corretto = false;
  simbolo = "";
  lcd.init();
  lcd.backlight();
  //pinMode(btnStart, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Premi il bottone");
  lcd.setCursor(0, 1);
  lcd.print("blu per iniziare");
  vite = 5;
  punti = 0;
  tempo = 1500;
  if (digitalRead(btnRecord) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Record : " + String(record));
    delay(4000);
    loop();
  }
  if (digitalRead(btnStart) == HIGH)
  {
    lcd.clear();
    PrimaRiga(vite, punti);
    while (vite > 0)
    {
      corretto = false;
      delay(1500);
      int Array[] = {2, 5, 8, 11, 14};
      posizione = random(0, 5);
      lcd.setCursor(Array[posizione], 1);
      a = random(0, 10);
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
      var = 0;
      if (a == 0)
      {
        while (var < tempo)
        {
          if (BottoniErrati(0) == true)
          {
            vite--;
            tempo = tempo - 30;
            var = tempo;
          }
          delay(1);
          var++;
        }
        delay(1);
        PrimaRiga(vite, punti);
      }
      else if (a == 1)
      {
        while (var < tempo)
        {
          int btn = posizione + 9;
          if (digitalRead(btn) == HIGH)
          {
            vite++;
            tempo = tempo + 30;
            var = tempo;
          }
          else if (BottoniErrati(posizione) == true)
          {
            vite--;
            var = tempo;
            tempo = tempo - 30;
          }
          else
          {
            var += 1;
          }
          delay(1);
        }
        PrimaRiga(vite, punti);
      }
      else
      {
        while (var < tempo)
        {
          if (digitalRead(posizione + 9) == HIGH)
          {
            punti++;
            tempo = tempo - 30;
            var = tempo;
            corretto = true;
          }
          else if (BottoniErrati(posizione) == true)
          {
            var = tempo;
            tempo = tempo - 30;
          }
          else
          {
            var += 1;
          }
          delay(1);
        }
        if (corretto == false)
        {
          vite--;
          tempo = tempo - 30;
        }
        PrimaRiga(vite, punti);
      }
      lcd.clear();
      PrimaRiga(vite, punti);
    }
    if (vite == 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Game Over");
      delay(3000);
    }
    if (punti > record)
    {
      record = punti;
    }
  }
}
bool BottoniErrati(int a)
{
  bool sbagliato = false;
  for (int b = 9; b < 14; b++)
  {
    if (a != b)
    {
      if (digitalRead(b) == HIGH)
      {
        sbagliato = true;
      }
    }
  }
  return sbagliato;
}
void PrimaRiga(int vita, int Punti)
{
  lcd.setCursor(0, 0);
  lcd.print("Vite=" + String(vita));
  lcd.setCursor(8, 0);
  lcd.print("Punti=" + String(Punti));
}
