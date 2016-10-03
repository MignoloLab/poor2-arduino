  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 10
  //Indieto   PIN 9   ---- Integrato 11
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 7
  //Sensore ultrasuoni destra           PIN 13
  //Sensore ultrasuoni centro           PIN 12
  //Sensore ultrasuoni sinistra         PIN 11
  //Trigger ultrasuoni                  PIN 3
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 07/12/2015
  //Web: www.mignololab.org     www.ivotek.it
  //Email: info@mignololab.org      ivotek@gmail.com
  //***************************************************************************

  //Dichiaro le variabili per utilizzare i nomi al posto dei numeri
  //Spreco memoria ma il codice risulta leggibile al principiante
  int Destra = 5;
  int Sinistra = 6;
  int Avanti = 10;
  int Indietro = 9;
  int UltrasDx = 13;
  int UltrasSx = 11;
  int UltrasCx = 12;
  int UltrasTr = 3;
  
  //Variabili per contenere i valori dei sensori
  int vUltrasDx; 
  int vUltrasSx; 
  int vUltrasCx;
  int vLineaCSx;

  //Variabili per contenee il tempo dell'eco
  long TempoechoDx;
  long TempoechoSx;
  long TempoechoCx;


  //Variabili per la conversione in centimetri
  long centimetriD;
  long centimetriS;
  long centimetriC;
  
void setup() {

  //Setto i PIN come out o in per pilotare i motori e i sensori di linea del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita
  pinMode(UltrasDx, INPUT);      //Setto la porta UltrasDx come ingresso
  pinMode(UltrasSx, INPUT);      //Setto la porta UltrasSx come ingresso
  pinMode(UltrasCx, INPUT);      //Setto la porta UltrasCx come ingresso
  pinMode(UltrasTr, OUTPUT);      //Setto la porta UltrasT come uscita

}

void loop() {
  
  //Genero un impulso di 10 micro secondi per il trigger
  digitalWrite(UltrasTr, LOW );     //Azzero l'uscita
  delayMicroseconds(3);		    //Attendo 3 microsecondis
  digitalWrite(UltrasTr, HIGH );    //Alzo il livello a uno
  delayMicroseconds( 10 );          //Attendo 10 microsecondi
  digitalWrite(UltrasTr, LOW );     //Azzero l'uscita
  //Prelevo il tempo dai sensori
  TempoechoDx = pulseIn( UltrasDx, HIGH,38000 );
  delay(10);  

  
  //Genero un impulso di 10 micro secondi per il trigger
  digitalWrite(UltrasTr, HIGH );    //Alzo il livello a uno
  delayMicroseconds( 10 );          //Attendo 10 microsecondi
  digitalWrite(UltrasTr, LOW );     //Azzero l'uscita
  TempoechoSx = pulseIn( UltrasSx, HIGH,38000 );
  delay(10);

   
  //Genero un impulso di 10 micro secondi per il trigger
  digitalWrite(UltrasTr, HIGH );    //Alzo il livello a uno
  delayMicroseconds( 10 );          //Attendo 10 microsecondi
  digitalWrite(UltrasTr, LOW );     //Azzero l'uscita
  TempoechoCx =  pulseIn( UltrasCx, HIGH,38000 );
  //delay(100);


  
  //Converto il tempo in  centimetri
  centimetriD = 0.034 * TempoechoDx / 2;
  centimetriS = 0.034 * TempoechoSx / 2;
  centimetriC = 0.034 * TempoechoCx / 2;

    
  
  //I sensori sono tutte e tre senza ostacoli
  if (centimetriD > 15 and centimetriS > 15 and centimetriC > 15 ) 
  {
    //Il robot va avanti, cambiare il numero 255 per variare la velocità
    analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
    analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità  
    //Lo sterzo è dritto
    digitalWrite(Destra, LOW);    
    digitalWrite(Sinistra, LOW);   
    
  }
  else if (centimetriD < 15 and centimetriD > 0) // C'è un ostacolo a destra
    {
      //Il robot gira a sinistra andando sempre avanti
        digitalWrite(Destra, LOW);   
        digitalWrite(Sinistra, HIGH);   // Il robot gira tutto a sinistra  
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità   
    }
  else if (centimetriS < 15 and centimetriS > 0) // C'è un ostacolo a sinistra
    {
      //Il robot gira a destra andando sempre avanti
        digitalWrite(Sinistra, LOW);   
        digitalWrite(Destra, HIGH);   // Il robot gira tutto a destra
        //Il robot va avanti, cambiare il numero 255 per variare la velocità
        analogWrite(Avanti, 255);   // Il robot cammina alla massima velocità 
        analogWrite(Indietro, 0);   // Il robot cammina alla massima velocità
    }
  else if (centimetriC < 15 and  centimetriC > 0) // C'è un ostacolo al centro
    {
      //Il robot si ferma
        digitalWrite(Destra, LOW);   // Il robot ha lo sterzo diritto 
        digitalWrite(Sinistra, LOW);     
        //Il robot si ferma
        analogWrite(Avanti, 0);   
        analogWrite(Indietro, 0);   
    } 

    
}
