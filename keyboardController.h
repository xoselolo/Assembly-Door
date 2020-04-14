/*
 * File:   keyboardController.h
 * Author: xoselolo
 *
 * Created on 9 de abril de 2020, 12:09
 */
#ifndef _KEYBOARDCONTROLLER_H
#define _KEYBOARDCONTROLLER_H

#include "smsDictionary.h"

static char actualKey = -1;
static char toSend = -1;
static char sent = 0;
static char type = 0;

/**
 * Procedure that initializes the TAD
 */
void KEYBOARD_CONTROLLER_init();

/**
 * Motor of the TAD
 */
void KEYBOARD_CONTROLLER_motor();

/**
 * gets the type:
 *      0 - New option (1 or 2)
 *      1 - New char added
 *      2 - Last char modified
 *      3 - * (main menu)
 *      4 - # (master reset)
 * @return the type
 */
char KEYBOARD_CONTROLLER_getType();

/**
 * sets the sent variable to 1
 * @return the actualKey (it's the real char f.e. 'A' or '9' or maybe 10 or 12 if its * or # )
 */
char KEYBOARD_CONTROLLER_read();

#endif //_KEYBOARDCONTROLLER_H