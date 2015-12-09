#include <VirtualWire.h> 
#define ledPin 9 

void setup() {
  // put your setup code here, to run once:

    vw_set_tx_pin(4);               // nadajnik RF podłączamy do pinu 12
    vw_setup(2000);        // ustawiamy prędkość transmisji
    vw_set_rx_pin(11);
     vw_rx_start();                            // Rozpoczynamy odbiór danych
      pinMode(ledPin, OUTPUT);
      Serial.begin(9600);
} 



void loop() {
  

 char wl[2] = {'W','1'};            //utworz tablice dwuznakową wl
 char wyl[2] = {'W','0'};           //utworz tablice dwuznakową wyl
 vw_send((uint8_t *)wl, 2);      //wysylamy w postaci znaków 8-bitowych zawartosc tablicy wl o wielkosci 2
   vw_wait_tx();                   // poczekaj az cala zawartosc tablicy zostanie wyslana
   delay(1000);                    //odczekaj 1s
   uint8_t buf[VW_MAX_MESSAGE_LEN];          //definicja buforu odbioru danych
    uint8_t buflen = VW_MAX_MESSAGE_LEN;      //oraz dlugości otrzymanych danych
  
    if (vw_get_message(buf, &buflen))         // jeżeli do buforu danych dotarły dane oraz
                                              // transmisja została zakończona i długość danych nie przekracza 8-bitów
    {
 String dane;   
 int i;
 //utwórz zmienną string dane  
    
      for (i = 0; i < buflen; i++)            //jeżeli wartość i < 0 to odbieraj znaki
          {
        
         dane +=char(buf[i]);                 //do zmiennej string wprowadź wszystkie otrzymane znaki i je połącz
         
          }
           if(dane == "W1")                             //jeżeli odebrane dane są równe W1
      {
        
     Serial.println(dane);
       digitalWrite(ledPin, HIGH);    //przypisz zielonej diodzie stan jako wartość zmiennej boolowskiej
       delay(1000);               
    }
 }
}
