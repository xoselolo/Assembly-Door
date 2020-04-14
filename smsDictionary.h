/*
 * File:   smsDictionary.h
 * Author: xoselolo
 *
 * Created on 8 de abril de 2020, 18:49
 */
#ifndef _SMSDICTIONARY_H
#define _SMSDICTIONARY_H

typedef struct{
    char numValues;
    char values[5];
}DictionaryEntry;

/**
 * Procedure that initializes the structure
 */
void SMSDICTIONARY_init();

/**
 * Function called when a key on the keyboard is pressed
 * @param actualKey : key that has been pressed
 *                      between [1 - 12]
 * @param pressedTimes : how many times has been pressed
 * @return the char associated
 */
char SMSDICTIONARY_getChar(char actualKey, char pressedTimes);

#endif //_SMSDICTIONARY_H