#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);
    Serial.println("setup");
vw_set_tx_pin(12);
vw_set_rx_pin(11);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
     vw_rx_start();
}
void loop()
{
    const char *msg = "hello";

    digitalWrite(13, true);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    digitalWrite(13, false);
    delay(200);
uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen))
    {
 int i;

        digitalWrite(13, true);
 Serial.print("Got: ");
 
 for (i = 0; i < buflen; i++)
 {
     Serial.print(buf[i], HEX);
     Serial.print(" ");
 }
 Serial.println("");
        digitalWrite(13, false);


   }
}



