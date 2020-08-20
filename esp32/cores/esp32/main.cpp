#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"
#include "Arduino.h"
#include "SkriBotApp.h"

TaskHandle_t loopTaskHandle = NULL;

#if CONFIG_AUTOSTART_ARDUINO

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

bool loopTaskWDTEnabled;

void loopTask(void *pvParameters)
{
    pinMode(32,INPUT_PULLUP);
    if(digitalRead(32) == HIGH){
    setup();
    for(;;) {
        if(loopTaskWDTEnabled){
            esp_task_wdt_reset();
        }
        loop();
    }
    }else{
    skribot_setup();
    for(;;) {
        if(loopTaskWDTEnabled){
        esp_task_wdt_reset();
        }
        skribot_loop();

    }
}
  /*setup();
    for(;;) {
        if(loopTaskWDTEnabled){
            esp_task_wdt_reset();
        }
        loop();
    }  
    */
}

extern "C" void app_main()
{
    loopTaskWDTEnabled = false;
    initArduino();
    xTaskCreatePinnedToCore(loopTask, "loopTask", 8192, NULL, 1, &loopTaskHandle, ARDUINO_RUNNING_CORE);
}

#endif
