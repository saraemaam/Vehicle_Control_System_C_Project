/*
 * variables.c
 *
 *  Created on: Mar 8, 2023
 *      Author: Sarah
 */

#include "data_types.h"
#include "Variables.h"

uint8 user_input;
uint8 sesnor_input;
uint8 traffic_light_sensor;
uint16 room_temperature_sensor;
uint16 set_vehicle_speed = 25;
uint16 current_room_temperature = 35;
uint16 Engine_temperature = 95;


Engine_temperature_controller_t Engine_temperature_controller = ENGINE_TEMP_CONTROLLER_OFF;
Engine_state_t engine_state = ON ;
AC_STATE_t AC_STATUS = AC_OFF;







