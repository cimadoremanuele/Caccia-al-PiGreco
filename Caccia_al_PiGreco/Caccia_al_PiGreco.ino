#include <LiquidCrystal_I2C.h>

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
  btnStart = 5;
  btnRecord = 6;
  btn1 = 9;
  btn2 = 10;
  btn3 = 11;
  btn4 = 12;
  btn5 = 13;
  corretto = false;
  lcd.init();
  lcd.backlight();
  pinMode(btnRecord, INPUT);
  pinMode(btnStart, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Inizio();
  Azzera();
  if (digitalRead(btnRecord) == HIGH)
  {
    Record();
  }
  if (digitalRead(btnStart) == HIGH)
  {
    lcd.clear();
    PrimaRiga(vite, punti);
    while (vite > 0)
    {
      SceltaPosizione();
      if (random(1, 11) == 1)
      {
        malus();
      }
      else if (random(1, 11) == 1)
      {
        bonus();
      }
      else
      {
        piGreco();
      }
    }
    PartitaFinita();
  }
  if (punti > record)
  { //aggiorno il record se necessario
    record = punti;
  }
}
void Inizio() // scritta iniziale
{
  lcd.setCursor(0, 0); lcd.print("Premi il bottone");
  lcd.setCursor(0, 1); lcd.print("blu per iniziare");
}
void Record() //scrivo il record
{
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Record : " + String(record));
  delay(4000);
  loop();
}
void SceltaPosizione() //scelgo
{
  var = 0;
  corretto = false;
  delay(1500);
  int Array[] = {2, 5, 8, 11, 14};
  posizione = random(0, 5); 
  lcd.setCursor(Array[posizione], 1); //posizione dove scrivo il piGreco o il bonus o il malus
}
void malus()
{
  lcd.print("m"); //scrivo il malus
  while (var < tempo)
  {
    if (BottoniErrati(0) == true)
    { //l'utente ha premuto un bottone sbagliato
      vite--;
      tempo = tempo - 30;
      break;
    }
    var++;
    delay(1);
  }
  lcd.clear();
  PrimaRiga(vite, punti);
}
void bonus()
{
  lcd.print("b"); //scrivo il bonus
  while (var < tempo)
  {
    if (digitalRead(posizione + 9) == HIGH)
    { //l'utente ha premuto il bottone corretto
      vite++;
      tempo = tempo + 30;
      break;
    }
    else if (BottoniErrati(posizione + 9) == true)
    { //l'utente ha premuto il bottone sbagliato
      vite--;
      tempo = tempo - 30;
      break;
    }
    var++;
    delay(1);
  }
  lcd.clear();
  PrimaRiga(vite, punti);
}

void piGreco()
{
  lcd.print("π"); //scrivo il piGreco
  while (var < tempo)
  {
    if (digitalRead(posizione + 9) == HIGH)
    { //l'utente ha premuto il bottone corretto
      punti++;
      tempo = tempo - 30;
      corretto = true;
      break;
    }
    else if (BottoniErrati(posizione + 9) == true)
    { //l'utente ha premuto il bottone sbagliato
      corretto = false;
      break;
    }
    var++;
    delay(1);
  }
  if (corretto == false)
  { //se l'utente ha sbagliato o non ha premuto nessun bottone diminuisco le vite e il tempo
    vite--;
    tempo = tempo - 30;
  }
  lcd.clear();
  PrimaRiga(vite, punti);
}
void Azzera()
{
  vite = 5;
  punti = 0;
  var = 0;
  tempo = 1500;
}
bool BottoniErrati(int a) //se l'utente preme il bottone sbagliato intervengo
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
void PrimaRiga(int vita, int Punti) //scrivo vite e punti
{
  lcd.setCursor(0, 0);
  lcd.print("Vite=" + String(vita));
  lcd.setCursor(8, 0);
  lcd.print("Punti=" + String(Punti));
}
void PartitaFinita() //fine partita
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over");
  delay(3000);
}
