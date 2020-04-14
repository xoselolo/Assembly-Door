/*
 * File:   keyboard.c
 * Author: xoselolo
 *
 * Created on 12 de abril de 2020, 11:11
 */

#include "keyboard.h"

static unsigned const char T_ESCOMB = 2;
static unsigned const char T_REBOTS = 16;

// falta decir cuantos tics son el tiempo de barrido
// (depende de la Frecuencia a la que funncione nuestra PIC24)
static unsigned char timer_id;

static char state = 0;
static char fila = 1;
static char columna = 0;


/**
 * Initializes the KEYBOARD tad
 */
void KEYBOARD_init(){
    fila = 1;
    timer_id = TIMER_getTimer();
    PORTBbits.RB6 = 1;
    PORTBbits.RB7 = 0;
    PORTBbits.RB8 = 0;
    PORTBbits.RB9 = 0;
    TIMER_resetTics(timer_id);
    state = 0;
    tecla = 0;
}

/**
 * Motor of the KEYBOARD tad
 */
void KEYBOARD_motor(){
    switch (state){
        case 0:
            columna = KEYBOARD_pressed();
            if(columna > 0){
                TIMER_resetTics(timer_id);
                state = 4;
            }else if(TIMER_getTics(timer_id) >= T_ESCOMB){
                fila = 2;
                PORTBbits.RB6 = 0;
                PORTBbits.RB7 = 1;
                state = 1;
            }
            break;

        case 1:
            columna = KEYBOARD_pressed();
            if(columna > 0){
                TIMER_resetTics(timer_id);
                state = 4;
            }else if(TIMER_getTics(timer_id) >= T_ESCOMB){
                fila = 3;
                PORTBbits.RB7 = 0;
                PORTBbits.RB8 = 1;
                state = 2;
            }
            break;

        case 2:
            columna = KEYBOARD_pressed();
            if(columna > 0){
                TIMER_resetTics(timer_id);
                state = 4;
            }else if(TIMER_getTics(timer_id) >= T_ESCOMB){
                fila = 4;
                PORTBbits.RB8 = 0;
                PORTBbits.RB9 = 1;
                state = 3;
            }
            break;

        case 3:
            columna = KEYBOARD_pressed();
            if(columna > 0){
                TIMER_resetTics(timer_id);
                state = 4;
            }else if(TIMER_getTics(timer_id) >= T_ESCOMB){
                fila = 1;
                PORTBbits.RB9 = 0;
                PORTBbits.RB6 = 1;
                state = 0;
            }
            break;

        case 4:
            if(TIMER_getTics() >= T_REBOTS){
                state = 5;
            }
            break;

        case 5:
            tecla = KEYBOARD_descifraTecla();
            state = 6;
            break;

        case 6:
            if(KEYBOARD_pressed() == 0){
                TIMER_resetTics(timer_id);
                state = 7;
            }
            break;

        case 7:
            if(TIMER_getTics() >= T_REBOTS && tecla == 0){
                state = 0;
            }
            break;
    }
}


char KEYBOARD_pressed(){
    if(PORTAbits.RA2 == 1){
        return 1;
    } else if (PORTAbits.RA3 == 1){
        return 2;
    } else if (PORTAbits.RA4 == 1){
        return 3;
    } else{
        return 0;
    }
}

char KEYBOARD_descifraTecla(){
    switch (fila){
        case 1:  // fila 1
            return columna;
        case 2:  // fila 2
            return 3 + columna;
        case 3:  // fila 3
            return 6 + columna;
        case 4:  // fila 4
            return 9 + columna;
    }
}

/**
 * Returns the key pressed or 0 if no there is not any pressed key
 */
char KEYBOARD_getTecla(){
    return tecla;
}

/**
 * sets tecla to 0 to indicate that has been read
 */
void KEYBOARD_keyReceived(){
    tecla = 0;
}