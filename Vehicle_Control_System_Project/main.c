
#include <stdio.h>
#include"data_types.h"
#include"Variables.h"
#include"program_interface.h"


void main(void)
{
	//to print the buffered messages

	print_buffered_msgs();

	//Start the system by asking the user if wants to turn on/off the vehicle engine or Exit and start processing

	Start_vehicle_control_system();

}
