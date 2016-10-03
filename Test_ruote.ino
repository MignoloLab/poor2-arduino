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
  //Porto le porte a livelo logico uno per mandare avanti il motorino
  digitalWrite(Avanti, HIGH);   // Il robot va avanti
  digitalWrite(Indietro, LOW);
  //Attendo un secondo
  delay(1000);                  
  //Porto le porte a livello logico zero per fermare il motorino
  digitalWrite(Avanti, LOW);    //Il robot si ferma
  digitalWrite(Indietro, LOW); 
  //Attendo due secondo
  delay(2000);


  //Porto le porte a livello logico uno per mandare indietro il motorino
  digitalWrite(Indietro, HIGH);  //Il robot va indietro
  digitalWrite(Avanti, LOW);
  //Attendo un secondo
  delay(1000);
  //Porto le porte a livello logico zero per fermare il motorino
  digitalWrite(Indietro, LOW);    //Il robot si ferma
  digitalWrite(Avanti, LOW);
  //Attendo 2 secondi
  delay(2000);


//Porto le porte a livelo logico uno per mandare avanti il motorino dello sterzo
  digitalWrite(Destra, HIGH);   // Il robot posiziona le ruote a destra
  digitalWrite(Sinistra, LOW);
  //Attendo un secondo
  delay(1000);                  
  //Porto le porte a livello logico zero per fermare il motorino
  digitalWrite(Destra, LOW);    //Il robot posiziona le ruote dritte
  digitalWrite(Sinistra, LOW);
  //Attendo due secondo
  delay(2000);


  //Porto le porte a livello logico uno per mandare indietro il motorino dello sterzo
  digitalWrite(Sinistra, HIGH);  //Il robot posiziona le ruote a sinistra
  digitalWrite(Destra, LOW);
  //Attendo un secondo
  delay(1000);
  //Porto le porte a livello logico zero per fermare il motorino
  digitalWrite(Sinistra, LOW);    //Il robot posiziona le ruote dritte
  digitalWrite(Destra, LOW); 
  //Attendo 2 secondi




  //Attendi 3 secondi prima di ripetere il ciclo
  delay(3000);

}
