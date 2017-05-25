  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 11
  //Indieto   PIN 9   ---- Integrato 10
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 7
  //Ultrasuoni sinistro         PIN 11
  //Ultrasuoni destro           PIN 12 
  //Ultrasuoni centro           PIN 13
  //Ultrasuoni trigger          PIN 3
  //
  //Si prende in considerazione la velocità del suono 
  //in aria a 20 c° che è di 343,8 m/s
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 26/11/2015
  //Web: www.mignololab.org     www.ivotek.it
  //Email: info@mignololab.org      ivotek@gmail.com
  //***************************************************************************

  //Dichiaro le variabili per utilizzare i nomi al posto dei numeri
  //Spreco memoria ma il codice risulta leggibile al principiante
  int Destra = 5;
  int Sinistra = 6;
  int Avanti = 10;
  int Indietro = 9;

  int UltrSinitro = 11;
  int UltrDestro = 12;
  int UltrCentro = 13;
  int UltrTrigger = 3;

  //Variabile per memorizzare il tempo di durata
  int Tempdurata;

void setup() {

  //Setto i PIN come out per pilotare i motori del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita

  pinMode(UltrSinitro,INPUT);    //Setto la porta UltrSinitro come ingresso
  pinMode(UltrDestro,INPUT);     //Setto la porta UltrDestro come ingresso
  pinMode(UltrCentro,INPUT);     //Setto la porta UltrCentro come ingresso
  pinMode(UltrTrigger,OUTPUT);   //Setto la porta UltrTrigger come uscita
  

}

void loop() {
  //Il robot parte fermo
  analogWrite(Avanti, 0);  
  analogWrite(Indietro, 0); 

  //Porto il trigger a livello alto per 2 microsecondi
  digitalWrite(UltrTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(UltrTrigger, HIGH); 
  //E poi per 10 microsecondi
  delayMicroseconds(10);     
  digitalWrite(pin_segnale, LOW);

  Tempdurata = pulseIn(UltrSinitro, HIGH); // legge l'eco dell'impulso emesso in microsecondi
  //Ricavo i centimetri
  Distanza = Tempdurata/58;                 
  
  
  //Controllo i sensori
  


}
