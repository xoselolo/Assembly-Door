/* 
 * File:   ioticat.h
 * Author: xoselolo
 *
 * Created on 3 de abril de 2020, 11:10
 */

#ifndef IOTICAT_H
#define	IOTICAT_H


#include <stdio.h>
#include <string.h>

#define MAX_REGISTERED_USERS    5
#define MAX_WORKING_USERS       2

//#define MAX_REGISTERED_USERS    230
//#define MAX_WORKING_USERS       100

typedef struct {
    unsigned char value[2]; // [2]
}TimeInMinutes;

/**
 * name                 : nombre del usuario
 * uid                  : uid
 * in_min_hour          : hora minima de entrada
 * in_max_hour          : hora maxima de entrada
 * min_permanence_time  : tiempo minimo que el usuario debe estar dentro del IoTiCAT
 */

typedef struct{
    char name[11];
    char uid[6];
    char in_min_hour;
    char in_min_minute;
    char in_max_hour;
    char in_max_minute;
    TimeInMinutes min_permanence_time;//in minutes
}User;

/*
typedef struct{
    char* name; // [10]
    char* uid; // [2]
    char in_min_hour;
    char in_min_minute;
    char in_max_hour;
    char in_max_minute;
    TimeInMinutes min_permanence_time; //in minutes // [2]
}User;
*/
/**
 * users                : usuarios que tienen permisos en el sistema
 * times                : timepo que lleva trabajando cada uno de los usuarios que estan trabajando
 * cuantos              : indica cuantos usuarios tienen permiso
 * cuantos_in           : indica cuantos usuarios estan trabajando
 */
typedef struct{
    User users[MAX_REGISTERED_USERS];
    TimeInMinutes times[MAX_WORKING_USERS];
    unsigned char cuantos;
    unsigned char cuantos_in;
}IoticatDatabase;


/**************************** TAD METHODS ***************************/
/**
 * void IOTICAT_init()
 * @details: initializes the empty database
 *      @code cuantos = 0
 *      @code cuantos_in = 0
 */
void IOTICAT_init();

/**
 * char IOTICAT_register(User user)
 * @details: registers a new user to the database
 * @param user : new user to register
 * @returns:
 *      @return 0 = NO_ERROR
 *      @return 1 = ERROR (MAX_REGISTERED_USERS reached)
 */
char IOTICAT_register(User user);

/**
 * Makes a swap from two elements on the database
 * @param i : index of the first element
 * @param j : index of the second element
 */
void swap(unsigned char i, unsigned char j);

/**
 * char IOTICAT_login(User user)
 * @details: user enters to work (if there's space in the institute)
 * @returns:
 *      @return 0 = NO_ERROR
 *      @return 1 = ERROR (MAX_WORKING_USERS reached)
 *      @return 2 = USER_NOT_RECOGNIZED
 */
char IOTICAT_login(const char uid[2]);

/**
 * void IOTICAT_show()
 * @details: shows the content of the database
 */
void IOTICAT_show();


/**
 * char IOTICAT_exists(char uid[6])
 * @param uid : ID from the user we a re checking
 * @returns :
 *      @return 0 = not exists
 *      @return 1 = exists and is working
 *      @return 2 = exists and not working
 */
char IOTICAT_exists(char uid[6]);


#endif	/* IOTICAT_H */

