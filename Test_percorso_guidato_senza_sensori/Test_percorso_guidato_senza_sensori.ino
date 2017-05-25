  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 11
  //Indieto   PIN 9   ---- Integrato 10
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 5
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
  //Faccio muovere il robot seguente un percorso prestabilito.

  //Avanti
  analogWrite(Avanti, 150);
  analogWrite(Indietro, 0);   
  //Attendo 2 secondi
  delay(1000);
  //Giro lo sterzo a destra
  digitalWrite(Destra,HIGH);    //Il robot gira a destra
  digitalWrite(Sinistra,LOW);
  //Attendo mezzo secondo 
  delay(500);
  //Addrizzo lo sterzo
  digitalWrite(Destra,LOW);     //Il robot torna dritto
  digitalWrite(Sinistra,LOW);
  //Attendo 2 secondi  
  delay(1000);
  //Giro lo sterzo a sinistra
  digitalWrite(Sinistra,HIGH);  //Il roboto va a sinistra
  digitalWrite(Destra,LOW);
  //Attendo mezzo secondo
  delay(500);
  //Addrizzo lo sterzo
  digitalWrite(Sinistra,LOW);   //Il robot va dritto
  digitalWrite(Destra,LOW);
  //Fermo il robot
  analogWrite(Avanti, 0);       //Il robot si ferma
  
  
  
  
  
  //Attendo 3 secondi prima di ripetere il ciclo
  delay(3000);



}
