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

static char previousKey = -1;
static char pressedTimes = 0;

/**
 * Procedure that initializes the TAD
 */
void KEYBOARD_CONTROLLER_init(){
    state = 0;
    option = 0;

    timer_id = TIMER_getTimer();
    time = 0;

    actualKey = -1;
    previousKey = -1;
    pressedTimes = 0;
    toSend = -1;
}


/**
 * Motor of the TAD
 */
void KEYBOARD_CONTROLLER_motor(){
    switch (state){
        case 0:
            actualKey = KEYBOARD_getTecla();

            if(actualKey != 0){
                KEYBOARD_keyReceived();

                if(option == 0){
                    toSend = actualKey;
                    state = 1;
                }else{
                    time = TIMER_resetTics(timer_id);
                    TIMER_resetTics(timer_id);
                    state = 2;
                }
            }
            break;

        case 1:
            sent = 0;
            switch (actualKey){
                case 10:
                    type = state = 3;
                    break;
                case 12:
                    type = state = 4;
                    break;
                default:
                    type = 0;
                    state = 5;
                    break;
            }
            break;

        case 2:
            switch (actualKey){
                case 10:
                    type = 3;
                    sent = 0;
                    state = 6;
                    break;
                case 12:
                    type = 4;
                    sent = 0;
                    state = 7;
                    break;
                default:
                    if(actualKey != previousKey){
                        pressedTimes = 1;
                        toSend = SMSDICTIONARY_getChar(actualKey, pressedTimes);
                        type = 1;
                        sent = 0;
                    }else{
                        state = 9;
                    }
                    break;
            }
            break;

        case 3:
        case 4:
        case 5:
            if(sent == 1) state = 0;
            break;

        case 6:
        case 7:
        case 8:
        case 10:
            if(sent == 1){
                previousKey = actualKey;
                state = 0;
            }
            break;

        case 9:
            if(time < 500){
                pressedTimes++;
                toSend = SMSDICTIONARY_getChar(actualKey, pressedTimes);
                state = 11;
            }else{
                pressedTimes = 1;
                toSend = SMSDICTIONARY_getChar(actualKey, pressedTimes);
                type = 1;
                sent = 0;
                state = 10;
            }
            break;

        case 11:
            if(toSend == -1){
                pressedTimes = 1;
                toSend = SMSDICTIONARY_getChar(actualKey, pressedTimes);
            }
            if(toSend != -1){
                type = 2;
                sent = 0;
                state = 10;
            }
            break;

        default:
            // Error, nunca deberia entrar a este caso
            KEYBOARD_CONTROLLER_init();
            break;
    }
}

/**
 * gets the type:
 *      0 - New option (1 or 2)
 *      1 - New char added
 *      2 - Last char modified
 *      3 - * (main menu)
 *      4 - # (master reset)
 * @return the type
 */
char KEYBOARD_CONTROLLER_getType(){
    return type;
}

/**
 * sets the sent variable to 1
 * @return the 'toSend' char
 */
char KEYBOARD_CONTROLLER_read(){
    sent = 1;
    return actualKey;
}
