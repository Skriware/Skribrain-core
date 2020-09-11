#include "Skribot_main.h"

void Skribot::AddDCRotor(int SpeedPin,int DirectionPin, String Side){
    Rotor *dcrotor = new Rotor(SpeedPin,DirectionPin);
     if(Side == "Left"){
      LeftDCRotors[NLeftDCRotors] = dcrotor;
      NLeftDCRotors++;
      Serial.println("Rotor Added!");
      if(user_config){
        if(!EEPROM_EMPTY(left_invert))Invert_Left_Rotors(left_invert);
        if(!EEPROM_EMPTY(left_scale))Scale_Left_Rotors(left_scale);
      }
     }else if(Side == "Right"){
      RightDCRotors[NRightDCRotors] = dcrotor;
      NRightDCRotors++;
      Serial.println("Rotor Added!");
      if(user_config){
        if(!EEPROM_EMPTY(right_invert))Invert_Right_Rotors(right_invert);
        if(!EEPROM_EMPTY(right_scale))Scale_Right_Rotors(right_scale);
      }
     }
  }

  void Skribot::AddDistSensor(int EchoPin,int TrigPin,String name){
    DistSensor *dsensor = new DistSensor(EchoPin,TrigPin,name);
    DistSensors[NDistSensors] = dsensor;
    NDistSensors++;
  }

  void Skribot::AddDistSensor(int EchoPin,int TrigPin,int id){
    DistSensor *dsensor = new DistSensor(EchoPin,TrigPin,id);
    DistSensors[NDistSensors] = dsensor;
    NDistSensors++;
  }

  void Skribot::AddLineSensor(int pinL,String Name){
    LineSensor *lsensor = new LineSensor(pinL,Name);
    LineSensors[NLineSensors] =  lsensor;
    NLineSensors++;
    Set_Line_Sensor_Logic_Border(L1_b,L2_b,L3_b);
  }

  void Skribot::AddLineSensor(int pinL,int id){
    LineSensor *lsensor = new LineSensor(pinL,id);
    LineSensors[NLineSensors] =  lsensor;
    NLineSensors++;
    Set_Line_Sensor_Logic_Border(L1_b,L2_b,L3_b);
  }

#ifndef _VARIANT_BBC_MICROBIT_
      
    void Skribot::AddDistSensor(String SHIELD_SLOT){
      #ifndef ESP_H 
      if(SHIELD_SLOT == "D1"){
        AddDistSensor(EDU_ECHO_PIN_1,EDU_TRIG_PIN_1,"D1");  
      }else if(SHIELD_SLOT == "D2"){
        AddDistSensor(EDU_ECHO_PIN_2,EDU_TRIG_PIN_2,"D2");
      }
      #else
       if(SHIELD_SLOT == "D1"){
        AddDistSensor(SKRIBRAIN_ECHO_PIN_1,SKRIBRAIN_TRIG_PIN_1,"D1");  
      }else if(SHIELD_SLOT == "D2"){
        AddDistSensor(SKRIBRAIN_ECHO_PIN_2,SKRIBRAIN_TRIG_PIN_2,"D2");
      }
      #endif
    }
    void Skribot::AddLineSensor(String SHIELD_SLOT){
      #ifndef ESP_H 
       if(SHIELD_SLOT == "L1"){
        AddLineSensor(EDU_LINE_SENSOR_1,"L1");
      }else if(SHIELD_SLOT == "L2"){
        AddLineSensor(EDU_LINE_SENSOR_2,"L2");
      }else if(SHIELD_SLOT == "L3" ){
        AddLineSensor(EDU_LINE_SENSOR_3,"L3");
      }
      #else
      if(SHIELD_SLOT == "L1"){
        AddLineSensor(SKRIBRAIN_ANALOG_PIN_1,"L1");
      }else if(SHIELD_SLOT == "L2"){
        AddLineSensor(SKRIBRAIN_ANALOG_PIN_2,"L2");
      }else if(SHIELD_SLOT == "L3" ){
        AddLineSensor(SKRIBRAIN_ANALOG_PIN_3,"L3");
      }
      #endif
    }
    void Skribot::AddDCRotor(String SHIELD_SLOT){
      #ifndef ESP_H 
      Serial.println("Adding rotor!");
      if(SHIELD_SLOT == "LEFT"){
        AddDCRotor(EDU_ROTOR_SPEED_PIN_L,EDU_ROTOR_DIR_PIN_L,"Left");          
      }else if(SHIELD_SLOT == "RIGHT"){
        AddDCRotor(EDU_ROTOR_SPEED_PIN_R,EDU_ROTOR_DIR_PIN_R,"Right");
      }
      #else
       Serial.println("Adding rotor!");
       if(SHIELD_SLOT == "LEFT"){
        AddDCRotor(SKRIBRAIN_MOTOR_L_DIR2_PIN,SKRIBRAIN_MOTOR_L_DIR1_PIN,"Left");          
      }else if(SHIELD_SLOT == "RIGHT"){
        AddDCRotor(SKRIBRAIN_MOTOR_R_DIR2_PIN,SKRIBRAIN_MOTOR_R_DIR1_PIN,"Right");
      }
      #endif
    }
   void Skribot::AddLED(String SHIELD_SLOT){
    #ifndef ESP_H 
      if(SHIELD_SLOT == "LED1"){
        AddLED(EDU_LED_DATA_PIN_1,"LED1");
      }else if(SHIELD_SLOT == "LED2"){
        AddLED(EDU_LED_DATA_PIN,"LED2");
      }
      #else
      if(SHIELD_SLOT == "LED1"){
        AddLED(SKRIBRAIN_LED_PIN_1,"LED1");
      }else if(SHIELD_SLOT == "LED2"){
        AddLED(SKRIBRAIN_LED_PIN_2,"LED2");
      }
      #endif
    }

     void Skribot::AddClaw(){
      #ifndef ESP_H 
        AddClaw(EDU_CLAW_PIN1,EDU_CLAW_PIN2);
      #else
      Check_Board_Version();
       switch (Board_type){
          case 1:
            AddClaw(SKRIBRAIN_SERVO_PIN_1,SKRIBRAIN_SERVO_PIN_2);
          break;
          case 2:
            AddClaw(SKRIBRAIN_SERVO_PIN_1,SKRIBRAIN_SERVO_PIN_3);
          break;
          default:
          break;
          }
      #endif
    } 

    void Skribot::AddDistSensor(byte SHIELD_SLOT){
          #ifdef ESP_H 
    if(SHIELD_SLOT == D1_PORT){
        AddDistSensor(SKRIBRAIN_ECHO_PIN_1,SKRIBRAIN_TRIG_PIN_1,D1_PORT);  
    }else if(SHIELD_SLOT == D2_PORT){
        AddDistSensor(SKRIBRAIN_ECHO_PIN_2,SKRIBRAIN_TRIG_PIN_2,D2_PORT);
    }
          #endif
    }

  void Skribot::AddAbstractDevice(byte pin,byte device_type, byte device_id){
          Abstract_Device *tmp = new Abstract_Device(pin,device_type,device_id);
          Devices[NABSDevices] = tmp;
          NABSDevices++;
    }

   
   bool Skribot::AddSPIDevice(uint8_t MOSI_PIN,uint8_t MISO,uint8_t CLK_PIN,uint8_t CS_PIN){
    bool tmp = SPIHandler::used_spi_bus<2;
    if(NSPIDevices < 2){
      SPIcomm[NSPIDevices] = new SPIHandler(MOSI_PIN,MISO,CLK_PIN,CS_PIN);
      NSPIDevices++;
    }
    return(tmp);
   }

   bool Skribot::AddI2CDevice(byte _SDA_PIN,byte _CLK_PIN,byte addr,uint32_t freq){
    bool tmp = I2CHandler::used_i2c_bus<2;
    if(NI2CDevices < 2){
      I2Ccomm[NI2CDevices] = new I2CHandler(_SDA_PIN,_CLK_PIN,freq);
      NI2CDevices++;
      tmp = I2Ccomm[NI2CDevices]->I2Cscan(addr);
   }
   return(tmp);
  }

  bool Skribot::Add_Mono_LED_matrix(byte SPI_PORT){
    if(SPI_PORT <2){
      SPIcomm[SPI_PORT] = new SPIHandler(SPI_PORT);
      LED_Matrixes[SPI_PORT] = new Mono_LED_Matrix(SPIcomm[SPI_PORT]);
    }
    SPIcomm[SPI_PORT]->set_SPI_Settings(4000000, MSBFIRST, SPI_MODE0);
    SPIcomm[SPI_PORT]->set_SPI_bit_format(16);

    LED_Matrixes[SPI_PORT]->Init();
    LED_Matrixes[SPI_PORT]->SetIntensity(8);
    LED_Matrixes[SPI_PORT]->Update();

         
  }
  void Skribot::AddBuzzer(byte BUZZER_PIN){
  #ifdef ESP_H 
    if(BUZZER_PIN == SERVO_1){
        Buzzers[SERVO_1] = new Buzzer(SKRIBRAIN_SERVO_PIN_1);
    }else if(BUZZER_PIN == SERVO_2){
        switch(Board_type){
        case 1: Buzzers[SERVO_2] = new Buzzer(SKRIBRAIN_SERVO_PIN_2); break;
        case 2: Buzzers[SERVO_2] = new Buzzer(SKRIBRAIN_SERVO_PIN_3); break;
        }
    }
  #else
    Buzzers[0] = new Buzzer(13);
  #endif
}

#endif
  #ifndef _VARIANT_BBC_MICROBIT_

  void Skribot::AddClaw(int Claw_Pin, int Arm_Pin, byte id){
    Claw *claw = new Claw(Claw_Pin,Arm_Pin,id);
    Claws[NClaws] = claw;
    NClaws++;
  }

   void Skribot::AddLED(int pin,String name,byte N_LED){
    RobotLED *led = new RobotLED(pin,name,N_LED);
    LEDs[NLEDs] = led;
    NLEDs++;
  }

   void Skribot::AddLED(int pin,int id,byte N_LED){
    RobotLED *led = new RobotLED(pin,id,N_LED);
    LEDs[NLEDs] = led;
    NLEDs++;
  }



  #endif



void Skribot::Configure_Connections(String predef){
     Check_Board_Version();
    #ifndef ESP_H
    if(predef == "EDU_SHIELD"){
          AddDCRotor(EDU_ROTOR_SPEED_PIN_L,EDU_ROTOR_DIR_PIN_L,"Left");          //adding rotors for movement
          AddDCRotor(EDU_ROTOR_SPEED_PIN_R,EDU_ROTOR_DIR_PIN_R,"Right");
          Stop();
          AddDistSensor(EDU_ECHO_PIN_1,EDU_TRIG_PIN_1,1);   //adding Distance Sensors  and naming them "Left and Right";
          AddDistSensor(EDU_ECHO_PIN_2,EDU_TRIG_PIN_2,2);
          #ifndef _VARIANT_BBC_MICROBIT_
          AddClaw(EDU_CLAW_PIN1,EDU_CLAW_PIN2);
          Claws[0]->SetPositions(BV_0_up,BV_0_down,BV_0_open,BV_0_close);
          #if DISABLED(DEBUG_MODE)
          AddLED(EDU_LED_DATA_PIN_1,1);
          AddLED(EDU_LED_DATA_PIN,0);
          #endif
          #endif
          AddLineSensor(EDU_LINE_SENSOR_1, 1);
          AddLineSensor(EDU_LINE_SENSOR_2, 2);
          AddLineSensor(EDU_LINE_SENSOR_3, 3);
          status = new StatusLED(EDU_SHIELD_STATUS_LED_R_PIN,EDU_SHIELD_STATUS_LED_G_PIN,EDU_SHIELD_STATUS_LED_B_PIN,EDU_SHILED_POWER_READOUT_PIN);
          stausLEDused = true;
          BLE_Set_Module(HM_10);
    }else if (predef == "SKRIBOT_MINI"){
           #ifdef _VARIANT_BBC_MICROBIT_
          AddDCRotor(SKRIBOT_MINI_SHILELD_MOTOR_1_DIR1_PIN,SKRIBOT_MINI_SHILELD_MOTOR_1_DIR2_PIN,"Left");
          AddDCRotor(SKRIBOT_MINI_SHILELD_MOTOR_2_DIR1_PIN,SKRIBOT_MINI_SHILELD_MOTOR_2_DIR2_PIN,"Right");
          AddLineSensor(SKRIBOT_MINI_SHILELD_SENSOR_0, 1);
          AddLineSensor(SKRIBOT_MINI_SHILELD_SENSOR_1, 2);
          AddLineSensor(SKRIBOT_MINI_SHILELD_SENSOR_2, 3);
          #endif
    }else if (predef == "EDU_SHIELD_NO_GRABBER"){
          AddDCRotor(EDU_ROTOR_SPEED_PIN_L,EDU_ROTOR_DIR_PIN_L,"Left");          //adding rotors for movement
          AddDCRotor(EDU_ROTOR_SPEED_PIN_R,EDU_ROTOR_DIR_PIN_R,"Right");
          AddDistSensor(EDU_ECHO_PIN_1,EDU_TRIG_PIN_1,1);   //adding Distance Sensors  and naming them "Left and Right";
          AddDistSensor(EDU_ECHO_PIN_2,EDU_TRIG_PIN_2,2);
          #ifndef _VARIANT_BBC_MICROBIT_
          #if DISABLED(DEBUG_MODE)
          AddLED(EDU_LED_DATA_PIN_1,1);
          AddLED(EDU_LED_DATA_PIN,0);
          #endif
          #endif
          AddLineSensor(EDU_LINE_SENSOR_1, 1);
          AddLineSensor(EDU_LINE_SENSOR_2, 2);
          AddLineSensor(EDU_LINE_SENSOR_3, 3);
          BLE_Set_Module(HM_10);
    }
    #else
    if(predef == "SKRIBRAIN"){
          AddDCRotor(SKRIBRAIN_MOTOR_L_DIR2_PIN,SKRIBRAIN_MOTOR_L_DIR1_PIN,"Left");
          AddDCRotor(SKRIBRAIN_MOTOR_R_DIR2_PIN,SKRIBRAIN_MOTOR_R_DIR1_PIN,"Right");
          AddLED(SKRIBRAIN_LED_PIN_2,1);
          AddLED(SKRIBRAIN_LED_PIN_1,0);
          AddDistSensor(SKRIBRAIN_ECHO_PIN_1,SKRIBRAIN_TRIG_PIN_1,1);   
          AddDistSensor(SKRIBRAIN_ECHO_PIN_2,SKRIBRAIN_TRIG_PIN_2,2);
          AddLineSensor(LINE_PIN_1, 1);
          AddLineSensor(LINE_PIN_2, 2);
          AddLineSensor(LINE_PIN_3, 3);
          BLE_Set_Module(ESP32_BLE); 
          switch (Board_type){
          case 1:
            AddClaw(SKRIBRAIN_SERVO_PIN_1,SKRIBRAIN_SERVO_PIN_2);
            Claws[0]->SetPositions(BV_1_up,BV_1_down,BV_1_open,BV_1_close);
            status = new StatusLED(SKRIBRAIN_STATUS_LED_PIN,SKRIBRAIN_SERVO_PIN_3,1);
          break;
          case 2:
            AddClaw(SKRIBRAIN_SERVO_PIN_1,SKRIBRAIN_SERVO_PIN_3);
            status = new StatusLED(SKRIBRAIN_STATUS_LED_PIN,SKRIBRAIN_SERVO_PIN_2,2);
            Claws[0]->SetPositions(BV_1_up,BV_1_down,BV_1_open,BV_1_close);
          break;
          default:
          break;
          }
          stausLEDused = true;
        }else if(predef == "SKRIBRAIN+LED_MATRIX"){ 
          AddDCRotor(SKRIBRAIN_MOTOR_L_DIR2_PIN,SKRIBRAIN_MOTOR_L_DIR1_PIN,"Left");
          AddDCRotor(SKRIBRAIN_MOTOR_R_DIR2_PIN,SKRIBRAIN_MOTOR_R_DIR1_PIN,"Right");
          AddLED(SKRIBRAIN_LED_PIN_2,1);
          AddDistSensor(SKRIBRAIN_ECHO_PIN_1,SKRIBRAIN_TRIG_PIN_1,1);   
          AddDistSensor(SKRIBRAIN_ECHO_PIN_2,SKRIBRAIN_TRIG_PIN_2,2);
          AddLineSensor(LINE_PIN_1, 1);
          AddLineSensor(LINE_PIN_2, 2);
          AddLineSensor(LINE_PIN_3, 3);
          AddClaw(SKRIBRAIN_SERVO_PIN_1,SKRIBRAIN_SERVO_PIN_2);
          BLE_Set_Module(ESP32_BLE); 
          status = new StatusLED(SKRIBRAIN_STATUS_LED_PIN,SKRIBRAIN_SERVO_PIN_3,1);
          stausLEDused = true;
          Add_Mono_LED_matrix(SPI_PORT_2);
        }else if(predef = "RAW_SKRIBRAIN"){
        BLE_Set_Module(ESP32_BLE); 
        Serial.println("Board type:");
        Serial.println(Board_type);
        switch (Board_type){
          case 1:
            status = new StatusLED(SKRIBRAIN_STATUS_LED_PIN,SKRIBRAIN_SERVO_PIN_3,1);
          break;
          case 2:
            status = new StatusLED(SKRIBRAIN_STATUS_LED_PIN,SKRIBRAIN_SERVO_PIN_2,2);
          break;
          default:
          break;
        }
        stausLEDused = true;
      }
    #endif
   SetSpeed(100);
   Stop();
  }
