  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 11
  //Indieto   PIN 9   ---- Integrato 10
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 7
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 22/08/2015
  //Web: www.mignololab.org     www.ivotek.it
  //Email: info@mignololab.org      ivotek@gmail.com
  //***************************************************************************

  //Dichiaro le variabili per utilizzare i nomi al posto dei numeri
  //Spreco memoria ma il codice risulta leggibile al principiante
  int Destra = 5;
  int Sinistra = 6;
  int Avanti = 10;
  int Indietro = 9;

void setup() {

  //Setto i PIN come out per pilotare i motori del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita
  

}

void loop() {
  //Vario il voltaggio per variare la velocità dei motori
  //Il robot parte con la massima velocità e piano piano diminuisce sino a fermarsi
  analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità
  analogWrite(Indietro, 0); 
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Avanti, 200);   
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Avanti, 150);  
  //Attendo 2 secondi 
  delay(2000);
  analogWrite(Avanti, 100); 
  //Attendo 2 secondi  
  delay(2000);
  analogWrite(Avanti, 50);   
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Avanti, 0);   // Il robot si ferma
  //Attendo 3 secondi prima di testare le ruote anteriori
  delay(3000);


  //Vario il voltaggio per variare la levocità del motorino di direzione
  //Non avrò tutta l'escurzione perchè lo sterzo ha la meccanica a frizione

  analogWrite(Destra, 255);   // Il robot gira tutto a destra
  analogWrite(Sinistra, 0);
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Destra, 200);   // La posizione dipende dal motore a delle caratteristiche della macchina
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Destra, 150);   // La posizione dipende dal motore a delle caratteristiche della macchina
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Destra, 100);   // La posizione dipende dal motore a delle caratteristiche della macchina
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Destra, 50);   // La posizione dipende dal motore a delle caratteristiche della macchina
  //Attendo 2 secondi
  delay(2000);
  analogWrite(Destra, 0);   // Il robot ha le ruote dritte

  //Attendi 3 secondi prima di ripetere il ciclo
  delay(3000);

}
