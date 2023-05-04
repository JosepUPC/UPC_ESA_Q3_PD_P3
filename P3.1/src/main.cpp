#include <Arduino.h>

void setup()
{
    Serial.begin(112500);

    /* Delarem una tasca. Els parametres que  entrarem serà el nom, el tamañ de la memoria que ocupara per al core, nivell de prioritat respecte a altres tasques i una variable per
    controlar-ho. */
    xTaskCreate
    (
      anotherTask,
      "another Task",
      10000, 
      NULL, 
      1, /
      NULL 
      ); 
}
 
/* La funció void loop es la tasca per default de la placa Esp32 per a un format de treball Arduino, que ve controlat per el core numero '0' */
void loop()
{
  Serial.println("this is ESP32 Task"); /* Mostrem per pantalla un missatge */
  delay(1000);  /* esperem 1s per a reiniciar el loop */
}
 
/* funció que cridaras per activar la tasca. Es pot manipular amb parametres d'entrada */
void anotherTask( void * parameter )
{
  
  /* escribim 'for(;;)' per tal de generar un loop dintre la funció */
  for(;;)
  {
    Serial.println("this is another Task");  /* Mostrem per pantalla un missatge */
    delay(1000); /* esperem 1s per a reiniciar el loop */
  }

  vTaskDelete( NULL ); /* parem la tasca. Es possible utilitzar un parametre declarat en la setup per tal de manipular l'apagada */
}