#include <Arduino.h>

SemaphoreHandle_t interruptSemaphore;
long debouncing_time = 150; 
volatile unsigned long last_micros;

void TaskLed(void *pvParameters);
void TaskBlink(void *pvParameters);
void debounceInterrupt();
void interruptHandler();

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
  xTaskCreate(TaskLed,  "Led", 10000, NULL, 0, NULL );
  xTaskCreate(TaskBlink,  "LedBlink", 10000, NULL, 0, NULL );
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL) {
    attachInterrupt(digitalPinToInterrupt(2), debounceInterrupt, LOW);
  }
}

void loop()
{
  delay(1000);
}

void debounceInterrupt() {
  if((long)(micros() - last_micros) >= debouncing_time * 1000) {
      interruptHandler();
      last_micros = micros();
  }
}

void interruptHandler() {
  xSemaphoreGiveFromISR(interruptSemaphore, NULL);
}

void TaskLed(void *pvParameters)
{
  (void) pvParameters;
  pinMode(25, OUTPUT);
  while(1) {
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS) {
      digitalWrite(25, !digitalRead(25));
    }  
  }
}
void TaskBlink(void *pvParameters)
{
  (void) pvParameters;
  pinMode(13, OUTPUT);
  while(1) {
  digitalWrite(13, HIGH);
  vTaskDelay(200 / portTICK_PERIOD_MS);
  digitalWrite(13, LOW);
  vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}