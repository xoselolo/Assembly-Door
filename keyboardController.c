/*
 * File:   keyboardController.c
 * Author: xoselolo
 *
 * Created on 9 de abril de 2020, 12:09
 */

#include "keyboardController.h"

static char state = 0;
static char option = 0;

static unsigned char timer_id = -1;
static unsigned int time = 0;

static char newChar = 0;

static char previousKey = -1;
static char actualKey = -1;
static char pressedTimes = 0;

/**
 * Procedure that initializes the TAD
 */
void KEYBOARD_CONTROLLER_init(){
    state = 0;
    option = 0;

    timer_id = TIMER_getTimer();
    time = 0;

    newChar = 0;

    actualKey = -1;
    previousKey = -1;
    pressedTimes = 0;
}


/**
 * Motor of the TAD
 */
void KEYBOARD_CONTROLLER_motor(){
    switch (state){
        case 0:
            if(option > 0){
                newChar = 0;
                TIMER_resetTics(timer_id);
                previousKey = -1;
                pressedTimes = 0;
                state = 2;
            } else if (newChar == 1){
                state = 1;
            }
            break;

        case 1:
            if(actualKey == 1){
                ACCESS_CONTROLLER_option1();
                option = 1;
            }else if(actualKey == 2){
                ACCESS_CONTROLLER_option2();
                option = 2;
            }else{
                state = 0;
                break;
            }
            newChar = pressedTimes = 0;
            previousKey = -1;
            TIMER_resetTics(timer_id);
            state = 2;
            break;

        case 2:
            if(option == 0){
                TIMER_resetTics();
                state = 0;
            }
            else if(newChar == 1){
                time = TIMER_getTics(timer_id);
                newChar = 0;
                state = 3;
            }
            break;

        case 3:
            if(actualKey != previousKey || time > 500){
                previousKey = actualKey;
                pressedTimes = 1;
                state = 4;

            }else{
                pressedTimes++;
                actualKey = SMSDICTIONARY_getChar(actualKey, pressedTimes);
                if(actualKey == -1){
                    pressedTimes = 1;
                }else{
                    state = 5;
                }
            }
            break;

        case 4:
            actualKey = SMSDICTIONARY_getChar(actualKey, pressedTimes);
            ACCESS_CONTROLLER_newChar(actualKey);
            state = 2;
            break;

        case 5:
            ACCESS_CONTROLLER_modifyLast(actualKey);
            state = 2;
            break;
    }
}

