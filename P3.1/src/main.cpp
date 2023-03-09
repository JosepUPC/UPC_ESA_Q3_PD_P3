#include <Arduino.h>

void anotherTask( void * parameter );
volatile int sum=0;
void setup()
{
    Serial.begin(112500);
    
    /* we create a new task here */
    xTaskCreate
    (
      anotherTask, /* Task function. */
      "another Task", /* name of task. */
      10000, /* Stack size of task */
      NULL, /* parameter of the task */
      1, /* priority of the task */
      NULL /* Task handle to keep track of created task */
      ); 
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
  Serial.printf("%d. this is the frist task  \n", sum);
  delay(1000);
  sum++;
}
 
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
  
  /* loop forever */
  for(;;)
  {
    delay(500);
    Serial.printf("%d. this is another Task  \n", sum);
    delay(500);
    sum++;
  }

  /* delete a task when finish,
  this will never happen because this is infinity loop */
  vTaskDelete( NULL );
}