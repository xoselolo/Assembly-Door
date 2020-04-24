/* 
 * File:   door.c
 * Author: xoselolo
 *
 * Created on 24 de abril de 2020, 16:40
 */
#include "door.h"

static char door = 0; // Initially door is closed

/**
 * Checks if the door is opened
 * @return 1 id open and 0 if closed
 */
char DOOR_isOpen(){
    return door;
}

/**
 * Opens the door
 */
void DOOR_open(){
    door = 1;
}

/**
 * Closes the door
 */
void DOOR_close(){
    door = 0;
}