/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

Relay_t relay_1 = {
.Relay_Port = PORTC_INDEX,
.Relay_Pin = PIN0,
.Relay_Status = RELAY_OFF_STATUS,
};

Relay_t relay_2 = {
.Relay_Port = PORTC_INDEX,
.Relay_Pin = PIN1,
.Relay_Status = RELAY_OFF_STATUS,
};


int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();
while(1){
  ret =Relay_Turn_ON(&relay_1);
  ret = Relay_Turn_OFF(&relay_2);
  _delay(5000);
  ret = Relay_Turn_OFF(&relay_1);
  ret =Relay_Turn_ON(&relay_2);
  _delay(5000); 

  }
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = Relay_Initialize(&relay_1);
ret = Relay_Initialize(&relay_2);
}