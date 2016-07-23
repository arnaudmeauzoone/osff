/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Written by Arnaud Meauzoone

*/
#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"    
#include "keyboard.h"
#include "timer.h"
#include "console.h"

void entry(){	

										//This is the static entry point 
										//It is needed for the assembly
	kernel_Main();						//because kernel_main adress can change but
										//not entry adress
}
										//Declare those value so it will be easier 

void kernel_Main(){

     //kernel_setup();

     setup_timer();

     console_setup();

     //update_cursor(2,2);
     write_String("kernel in c has started :)))");



     int64_t currentNano = 0;

    while(1){

    	timer();

    	if(getNano() - currentNano > 0 ){

           currentNano = getNano();
           

    	getScancode();
    	//kernel_run();

    	}
    }
}