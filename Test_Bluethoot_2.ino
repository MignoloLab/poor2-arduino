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
  //Data: 29/02/2016
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
  //***************************************************************************

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

void setup() {
  
  //Apro la seriale a 9600
  Serial.begin(9600);

  //Setto i PIN come out per pilotare i motori del robot.
  pinMode(Avanti,OUTPUT);        //Setto la porta Avanti come uscita
  pinMode(Indietro,OUTPUT);      //Setto la porta Indietro come uscita
  pinMode(Destra,OUTPUT);        //Setto la porta Destra come uscita
  pinMode(Sinistra,OUTPUT);      //Setto la porta Sinistra come uscita

}

void loop() {
  //Controllo se la seriale è connessa
  while (!Serial) {;}

  //Confermo che il robot è in ascolto
  //Serial.println("Poor is ready");

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

int ConvertiIntero(int uno,int due, int tre){
  //Se i valori sono tutti zero ritorno zero
  if (uno == '0' && due =='0' && tre == '0') return 0;
  
  //Converto i valori
  if (uno != '0') uno = uno * 100;
  if (due != '0') due = due * 10;

  //Sommo i valori e restituisco l'intero
  return uno + due+ tre;
    
}
