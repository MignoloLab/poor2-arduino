  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Ipotizzo una linea bianca su sfondo nero larga quando due sensori ravvicinati
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 10
  //Indieto   PIN 9   ---- Integrato 11
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 7
  //Sensore di linea destra           PIN 4
  //Sensore di linea centrodestra     PIN 2
  //Sensore di linea sinistra         PIN 7
  //Sensore di linea centrosinistra   PIN 8
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 25/09/2015
  //Web: www.mignololab.org     www.ivotek.it
  //Email: info@mignololab.org      ivotek@gmail.com
  //***************************************************************************

  //Dichiaro le variabili per utilizzare i nomi al posto dei numeri
  //Spreco memoria ma il codice risulta leggibile al principiante
  int Destra = 5;
  int Sinistra = 6;
  int Avanti = 10;
  int Indietro = 9;
  int LineaDx = 4;
  int LineaSx = 7;
  int LineaCDx = 2;
  int LineaCSx = 8;


  //Variabili per contenere i valori dei sensori
  int vLineaDx; 
  int vLineaSx; 
  int vLineaCDx;
  int vLineaCSx;
  
void setup() {

  //Setto i PIN come out o in per pilotare i motori e i sensori di linea del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita
  pinMode(LineaDx, INPUT);      //Setto la porta LineaDx come ingresso
  pinMode(LineaSx, INPUT);      //Setto la porta LineaSx come ingresso
  pinMode(LineaCDx, INPUT);      //Setto la porta LineaCDx come ingresso
  pinMode(LineaCSx, INPUT);      //Setto la porta LineaCSx come ingresso
  
}

void loop() {
  //Prelevo i valori dai sensori di linea
  vLineaDx = digitalRead(LineaDx);
  vLineaSx = digitalRead(LineaSx);
  vLineaCDx = digitalRead(LineaCDx);
  vLineaCSx = digitalRead(LineaCSx);

    
  //Controllo costantemente i sensori di linea
  //In base a quale è attivo effettuo un azione

  //I sensori sono tutte e due sulla linea bianca
  if (vLineaCDx == HIGH and vLineaCSx == HIGH) 
  {
    //Il robot va avanti, cambiare il numero 255 per variare la velocità
    analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
    analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità  
    //Lo sterzo è dritto
    digitalWrite(Destra, LOW);     
    digitalWrite(Sinistra, LOW);   
    
  }
  else if (vLineaCDx == HIGH and vLineaCSx == LOW) // La linea si trova sotto il sensore centrale destro
    {
      //Il robot gira a destra andando sempre avanti
        digitalWrite(Destra, HIGH);   // Il robot gira tutto a destra  
        digitalWrite(Sinistra, LOW);   
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità   
    }
  else if (vLineaCSx == HIGH and vLineaCDx == LOW) // La linea si trova sotto il sensore centrale sinistro
    {
      //Il robot gira a sinistra andando sempre avanti
        digitalWrite(Sinistra, HIGH);   // Il robot gira tutto a sinistra
        digitalWrite(Destra, LOW);   
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità
    }
  else if (vLineaSx == LOW and vLineaDx == HIGH) // La linea si trova sotto il sensore  destro
    {
      //Il robot gira a destra andando sempre avanti
        digitalWrite(Destra, HIGH);   // Il robot gira tutto a destra 
        digitalWrite(Sinistra, LOW);    
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità
    }
  else if (vLineaSx == HIGH and vLineaDx == LOW) // La linea si trova sotto il sensore  sinistro
    {
      //Il robot gira a sinistra andando sempre avanti
        digitalWrite(Sinistra, HIGH);   // Il robot gira tutto a sinistra 
        digitalWrite(Destra, LOW);   
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 0);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità
    }
  else
    {
      // Il robot si è perso
        //Lo sterzo è dritto
        digitalWrite(Destra, LOW);    
        digitalWrite(Sinistra, LOW);   
        // lo faccio fermare
        digitalWrite(Indietro, 0);   
        digitalWrite(Avanti, 0);
    }   
}
