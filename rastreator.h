/*
 * File:   rastreator.h
 * Author: xoselolo
 *
 * Created on 6 de abril de 2020, 12:31
 */

#ifndef _RASTREATOR_H
#define _RASTREATOR_H

#include <string.h>
#include "ioticat.h"

// Interficie 23
/**
 * Activates the RASTREATOR motor
 * @param user_id
 */
void RASTREATOR_find(char user_id[6]);

/**
 * RASTREATOR's motor
 */
void RASTREATOR_motor();

#endif //_RASTREATOR_H
