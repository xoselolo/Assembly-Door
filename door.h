/* 
 * File:   door.h
 * Author: xoselolo
 *
 * Created on 24 de abril de 2020, 16:40
 */

#ifndef DOOR_H
#define	DOOR_H

/**
 * Checks if the door is opened
 * @return 1 id open and 0 if closed
 */
char DOOR_isOpen();

/**
 * Opens the door
 */
void DOOR_open();

/**
 * Closes the door
 */
void DOOR_close();

#endif	/* DOOR_H */

