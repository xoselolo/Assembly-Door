/* 
 * File:   accessController.c
 * Author: xoselolo
 *
 * Created on 23 de abril de 2020, 15:31
 */

#include "accessController.h"

static char state = 0;
static char tecla;

void ACCESS_CONTROLLER_init(){
    // inicializar estructuras y variables
    state = 0;
}

void ACCESS_CONTROLLER_motor(){
    switch(state){
        case 0:
            if(KEYBOARD_CONTROLLER_isReady() == 1){
                state = 1;
            }
            break;
        case 1:
            tecla = KEYBOARD_CONTROLLER_read();
            state = 2;
            break;
        case 2:
            // todo: show character on LCD
            break;
    }
}