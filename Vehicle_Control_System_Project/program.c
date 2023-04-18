
/*
 * program.c
 *
 *  Created on: Mar 7, 2023
 *      Author: Sarah
 */

#include<stdio.h>
#include "data_types.h"
#include "Variables.h"

#define WITH_ENGINE_TEMP_CONTROLLER 1

void print_buffered_msgs (void){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}
void Set_the_traffic_light_color(uint8 traffic_light_sensor)
{

	if ( (traffic_light_sensor == 'G') || (traffic_light_sensor == 'g'))
	{
		set_vehicle_speed =100;
	}

	else if ((traffic_light_sensor == 'O') || (traffic_light_sensor == 'o'))
	{
		set_vehicle_speed=30;
	}

	else if (traffic_light_sensor == 'R' || traffic_light_sensor == 'r')
	{
		set_vehicle_speed=0;
	}

}


void Turn_on_vehicle_engine(void)
{

	if ( engine_state == OFF)
	{
		engine_state = ON ;
	}

}

void Set_the_room_temperature (uint16 set_room_temperature)

{
	current_room_temperature = 	set_room_temperature ;
}

void Turn_ON_AC (void)
{
	AC_STATUS = AC_ON;
}
void Turn_OFF_AC (void)
{
	AC_STATUS = AC_OFF;
}


void OFF_Engine_Temperature_Controller(void)
{
	if (Engine_temperature_controller == ENGINE_TEMP_CONTROLLER_ON)
	{
		Engine_temperature_controller = ENGINE_TEMP_CONTROLLER_OFF ;
	}

}

void ON_Engine_Temperature_Controller(void)
{
	if ( Engine_temperature_controller == ENGINE_TEMP_CONTROLLER_OFF )
	{
		Engine_temperature_controller = ENGINE_TEMP_CONTROLLER_ON ;
	}
}
void Set_the_engine_temperature(uint16 Engine_temp)
{
	Engine_temperature = Engine_temp ;
}

void Quit(void){

	printf("Quit the system\n");

}

void turn_off_the_engine(void){

	printf("Turn off the Engine\n");
}


void Set_vehicle_speed (void)
{

	Turn_ON_AC();
	current_room_temperature = current_room_temperature *5/4 + 1 ;

	ON_Engine_Temperature_Controller();
	Engine_temperature = Engine_temperature *5/4 + 1 ;

}

void display_system_state (void){

	if (engine_state)
	{
		printf("Engine is ON\n");
	}
	else
	{
		printf("Engine is OFF\n");
	}

	if (AC_STATUS)
	{
		printf("AC is ON\n");
	}
	else
	{
		printf("AC is OFF\n");
	}
	if (Engine_temperature_controller == ENGINE_TEMP_CONTROLLER_OFF)
	{
		printf("Engine temperature controller is OFF\n");
	}
	else
	{
		printf("Engine temperature controller is ON\n");
	}

	printf("Vehicle speed is : %d\n",set_vehicle_speed);
	printf("Room Temperature is : %d C\n",current_room_temperature);
	printf("Engine Temperature is : %d C\n",Engine_temperature);
	printf("\n");

}


void Set_room_temp (void)
{

	if ( room_temperature_sensor < 10 )
	{

		Turn_ON_AC();
		Set_the_room_temperature(20);

	}
	else if ( room_temperature_sensor  > 30 )

	{

		Turn_ON_AC();
		Set_the_room_temperature(20);

	}

	else
		Turn_OFF_AC();


}

void Set_Engine_Temp (void){
	if (Engine_temperature < 100)
	{
		Set_the_engine_temperature(125);
		ON_Engine_Temperature_Controller();
	}
	else if (Engine_temperature > 150)
	{
		Set_the_engine_temperature(125);
		ON_Engine_Temperature_Controller();

	}
	else
	{
		OFF_Engine_Temperature_Controller();
	}
}


void Sensor_set_menu (void)
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");


	scanf(" %c",&sesnor_input);
	/* if entered again a turn off the vehicle supposed to display the main menu again */
	if ((sesnor_input == 'a') || (sesnor_input == 'A'))
	{
		turn_off_the_engine();
		main();
	}

	//Set the traffic light color

	else if (( sesnor_input == 'b') || (sesnor_input == 'B'))

	{

		printf("Enter the required color\n");
		fflush(stdout);
		//Take it as input from console, we will assume that this is the sensor read value

		scanf(" %c",&traffic_light_sensor);

		Set_the_traffic_light_color(traffic_light_sensor);


		if ( set_vehicle_speed == 30 )
		{
			Set_vehicle_speed();
		}

		display_system_state();
		Sensor_set_menu();
	}

	else if (( sesnor_input == 'c')||(sesnor_input == 'C'))
	{
		//Set the room temperature (Temperature Sensor)
		//Take it as input from console, we will assume that this is the sensor read value

		printf("Enter the required room temperature:\n");
		fflush(stdout);
		scanf("%hu",&room_temperature_sensor);

		Set_room_temp();

		if ( set_vehicle_speed == 30 )
		{
			Set_vehicle_speed();
		}

		display_system_state();

		Sensor_set_menu();

	}

	else if (( sesnor_input == 'd') || (sesnor_input == 'D'))
	{

		//Take it as input from console, we will assume that this is the sensor read value
		//If temperature less than 100, Turn “Engine Temperature

		printf("Enter the required Engine Temperature\n");

		fflush(stdout);
		scanf("%hu",&Engine_temperature);



#if        (WITH_ENGINE_TEMP_CONTROLLER == 1)

		Set_Engine_Temp();
		if ( set_vehicle_speed == 30 )
		{
			Set_vehicle_speed();
		}

		display_system_state();
		Sensor_set_menu();


#endif


	}
}



void Start_vehicle_control_system (void)
{
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");

	scanf(" %c",&user_input);
	if (user_input == 'c')
	{
		Quit();
		return;
	}
	else if ((user_input == 'b') || (user_input == 'B'))
	{
		turn_off_the_engine();
		Start_vehicle_control_system();
	}

	else if ((user_input == 'a') || (user_input == 'A'))
	{
		//printf("a. Turn on the vehicle engine\n");

		/*If chose to “Turn on the vehicle system will display Sensors set menu
			that simulates the vehicle sensors readings.*/

		Sensor_set_menu();
	}

}





