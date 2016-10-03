  //***************************************************************************
  //Programma test per il robot Poor versione 2
  //Setto le porte di uscita per le funzioni:
  //Integrato trovato sulla macchinetta SM6135W oppure RX2-C
  //Avanti    PIN 10  ---- Integrato 11
  //Indieto   PIN 9   ---- Integrato 10
  //Destra    PIN 5   ---- Integrato 6
  //Sinistra  PIN 6   ---- Integrato 7
  //Seriale TX                  PIN 0
  //Seriale RX                  PIN 1
  //Velocità standard           9600
  //Bit di stop                 1
  //Bit di partità              0
  //PIN standard                1234
  //
  //Realizzato da: Daniele loddo alias Ivotek
  //Data: 03/03/2016
  //Web: www.mignololab.org     www.ivotek.it
  //Email: info@mignololab.org      ivotek@gmail.com
  //
  //
  // Protocollo ricezione dati direzione e velocità
  //
  //Il protocollo inizia con un asterisco *
  //Seguito da 12 numeri interi con valore da 0 a 9
  //Esempio: *255000125000
  //I numeri devono essere divisi in gruppi di tre quindi l'esempio superiore sarà:
  //255 000 125 000
  //La sequenza è avanti indietro destra sinistra, sempre seguendo l'esempio precedente i valori sono:
  //avanti 255 indietro 000 destra 125 sinistra 000
  //
  //Il valore massimo che si può inserire è 255 il minimo è 000
  //
  //
  //
  //Inserita la bussola, modello HMC5883L
  //Scale del sensore 0.88, 1.3, 1.9, 2.5, 4.0, 4.7, 5.6, 8.1 gauss
  //Scala inpostata 1.3
  //SCL PIN A5
  //SDA PIN A4
  //
  //Il giroscopio utilizzato è il modello GY-521 (MPU-6050)
  //Permette di misurare l'accellerazione, l'inclinazione e la temperatura.
  //SCL PIN A5
  //SDA PIN A4
  //***************************************************************************

  //Includo le librerie per gestire il protocollo I2C
  #include <Wire.h>
  
  //Libreria per gestire la bussola
  //ATTENZIONE: Questa libreria non è standard e va aggiunta
  //da Sketch-->Importa libreria-->Add library
  #include <HMC5883L.h>
  
  //Dichiaro le variabili per utilizzare i nomi al posto dei numeri
  //Spreco memoria ma il codice risulta leggibile al principiante
  int Destra = 5;
  int Sinistra = 6;
  int Avanti = 10;
  int Indietro = 9;
 
  //Variabile per contenere il carattere
  char carattere = 0;

  //Variabile per contenere tutta la stringa di informazione
  unsigned int StringaComandi[11];  

  //Variabili di lavoro del ciclo
  byte x;
  
  //Variabili per i valori dei comandi
  unsigned int ValoreAvanti, ValoreIndietro, ValoreDestra, ValoreSinistra;
  
  //funzione per convertire i singoli numeri in intero
  int ConvertiIntero(int, int, int);

  //Creiamo l'instanza per la bussola
  HMC5883L bussola;
  
  //Variabile per i gradi della bussola
  float gradi;
  
  //Indirizzo dell'MPU-6050
  const int MPU=0x68;
  
  //Vatiabili per contenere i valori dell'accellerazione
  //inclinazione e temperatura
  int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
  
void setup() {
  
  //Apro la seriale a 9600
  Serial.begin(9600);

  //Attivo il protocollo I2C per la trasmissione e ricezione
  Wire.begin();

  //Inizializzo la trasmissione con il giroscopio
  Wire.beginTransmission(MPU);
  //Registro di power, mi serve per attivare il giroscopio
  Wire.write(0x6B); 
  //Attivo il giroscopio
  Wire.write(0);
  //Termino la trasmissione
  Wire.endTransmission(true);
  
  //Inizializzo la bussola
  bussola = HMC5883L();
  
  //Setto la scala della bussola 1.3Ga
  //Le misure sono da -8.1 a +8.1Ga
  int errore = bussola.SetScale(8.1);
  //Controllo se il settaggio è andato a buon fine
  if(errore != 0)  
    //Se genera un errore lo stampo sulla seriale
    Serial.println(bussola.GetErrorText(errore));
 
  //Setto la misurazione continua
  errore = bussola.SetMeasurementMode(Measurement_Continuous);
  //Controllo se il settaggio è andato a buon fine
  if(errore != 0)
    //Se genera un errore lo stampo sulla seriale
    Serial.println(bussola.GetErrorText(errore));

  //Setto i PIN come out per pilotare i motori del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita

}

void loop() {
  //Controllo se la seriale è connessa
  while (!Serial) {;}


  //Leggo gli assi X ed Y della bussola
  MagnetometerRaw raw = bussola.ReadRawAxis();
   float radianti = atan2(raw.YAxis, raw.XAxis);
   //L'angolo ottenuto è in radianti e va covnerto in gradi 
   if(radianti < 0)
      radianti += 2*PI;
   float gradi = radianti * 180/M_PI;
   
   //Inizio la trasmissione con il giroscopio
   Wire.beginTransmission(MPU);
   Wire.write(0x3B);
   Wire.endTransmission(false);
   Wire.requestFrom(MPU,14,true);  
   AcX=Wire.read()<<8|Wire.read();  // Accellerazione asse X     
   AcY=Wire.read()<<8|Wire.read();  // Accellerazione asse Y
   AcZ=Wire.read()<<8|Wire.read();  // Accellerazione asse Z
   GyX=Wire.read()<<8|Wire.read();  // Giroscopio asse X
   GyY=Wire.read()<<8|Wire.read();  // Giroscopio asse Y
   GyZ=Wire.read()<<8|Wire.read();  // Giroscopio asse Z 
   
   //Invio i dati alla seriale, per rispettare il protocollo
   //uso del testo al posto dei valori dei sensori a ultrasuoni
   //voi potete inviare i valori dei sensori
   Serial.print("[");
   Serial.print("US");
   Serial.print("|");
   Serial.print("UC");
   Serial.print("|");
   Serial.print("UD");
   Serial.print("|");
   Serial.print(gradi);
   Serial.print("|");
   Serial.print(AcX);
   Serial.print("|");
   Serial.print(AcY);
   Serial.print("|");
   Serial.print(AcZ);
   Serial.print("|");
   Serial.print(GyX);
   Serial.print("|");
   Serial.print(GyY);
   Serial.print("|");
   Serial.print(GyZ);
   Serial.print("]");
   //Torno a capo per una facile lettura sul terminale
   Serial.println("");
   
   
  //Controllo se sono presenti tutti i caratteri nel buffer
  if (Serial.available() > 12) {  
    //Prelevo il primo carattere
    carattere = Serial.read();
    while (carattere == '*'){   
      //Il primo caratere è l'asterisco inizio la sequenza
      for (x=0;x<12;x++){  
        while (!Serial.available()) {}
        carattere = Serial.read();  //Prelevo il singolo carattere
        StringaComandi[x] = carattere; // Lo inserisco all'interno dell'array
      }

      //Trasformo i numeri singoli presenti nell'array in un numero intero
      ValoreAvanti = ConvertiIntero(StringaComandi[0],StringaComandi[1],StringaComandi[2]);
      ValoreIndietro = ConvertiIntero(StringaComandi[3],StringaComandi[4],StringaComandi[5]);
      ValoreDestra = ConvertiIntero(StringaComandi[6],StringaComandi[7],StringaComandi[8]);
      ValoreSinistra = ConvertiIntero(StringaComandi[9],StringaComandi[10],StringaComandi[11]);
     
      //Assegno i valori ai comandi
      analogWrite(Avanti, ValoreAvanti); 
      analogWrite(Indietro, ValoreIndietro);
      analogWrite(Destra, ValoreDestra);   
      analogWrite(Sinistra, ValoreSinistra); 
          
    }  
  }
}


//Funzioni
int ConvertiIntero(int uno,int due, int tre){
  //Se i valori sono tutti zero ritorno zero
  if (uno == '0' && due =='0' && tre == '0') return 0;
  
  //Converto i valori
  if (uno != '0') uno = uno * 100;
  if (due != '0') due = due * 10;

  //Sommo i valori e restituisco l'intero
  return uno + due+ tre;
    
}
