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
  //Il protocollo di trasmisione delle informazioni inizia
  //con un [ e termina con un  ] divide i campi con un segno tilde |
  //esempio [34|5|34]
  //L'ordine dei sensori è sinistro cento destro
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 04/03/2016
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
  //Apro la seriale a 9600
  Serial.begin(9600);
  
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
  //Controllo se la seriale è connessa
  while (!Serial) {;}
  
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


  
  //Converto il tempo in  centimetri
  centimetriD = 0.034 * TempoechoDx / 2;
  centimetriS = 0.034 * TempoechoSx / 2;
  centimetriC = 0.034 * TempoechoCx / 2;

  //Invio i dati alla seriale usando un protocollo semplice
  //*centrimetriS-centimetriC-centimetriD
  Serial.print("[");
  Serial.print(centimetriS);
  Serial.print("|");
  Serial.print(centimetriC);
  Serial.print("|");
  Serial.print(centimetriD);
  Serial.print("]");
  //Torno a capo per una facile lettura sul terminale
  Serial.println("");
    
}
