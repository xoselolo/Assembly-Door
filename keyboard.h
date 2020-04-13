/*
 * File:   keyboard.c
 * Author: xoselolo
 *
 * Created on 12 de abril de 2020, 11:11
 */

#ifndef KEYBOARD_KEYBOARD_H
#define KEYBOARD_KEYBOARD_H

#include <xc.h>
#include "timer.h"

/**
 * Initializes the KEYBOARD tad
 */
void KEYBOARD_init();

/**
 * Motor of the KEYBOARD tad
 */
void KEYBOARD_motor();

/**
 * Indicates which column has been pressed
 * @return the column or 0 if has not been pressed
 */
char KEYBOARD_pressed();

/**
 * From fila and column, it stores the key (tecla) that has been pressed
 */
char KEYBOARD_descifraTecla();

#endif //KEYBOARD_KEYBOARD_H
