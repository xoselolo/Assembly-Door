/*
 * File:   main.c
 * Author: xoselolo
 *
 * Created on 3 de abril de 2020, 11:09
 */


#include <xc.h>
//#include "ioticat.h"
#include "timer.h"
#include "accessController.h" 
// accessContr ya incluye keybContr, que ya incluye smsDicc y keyboard
#include "lcd.h"

void main(void) {
    
    TIMER_init();
    ACCESS_CONTROLLER_init();
    KEYBOARD_CONTROLLER_init();
    KEYBOARD_init();
    SMSDICTIONARY_init();
    
    while(1){
        KEYBOARD_motor();
        KEYBOARD_CONTROLLER_motor();
        ACCESS_CONTROLLER_motor();
    }
    
    return;
}
