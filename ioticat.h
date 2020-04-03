/*
 * File:   ioticat.h
 * Author: xoselolo
 *
 * Created on 3 de abril de 2020, 11:10
 */


#ifndef IOTICAT_H
#define IOTICAT_H

#include <string.h>

#define MAX_REGISTERED_USERS    230
#define MAX_WORKING_USERS       100



/******************************** TAD STRUCTURE ********************************/
typedef struct {
    unsigned char value[2]; // [2]
}TimeInMinutes;

/**
 * name                 : user's name
 * uid                  : user personal ID
 * in_min_hour          : minimum hour to enter
 * in_min_minute        : minimum minute to enter
 * in_max_hour          : maximum hour to exit
 * in_max_minute        : maximum minute to exit
 * min_permanence_time  : minimum time
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



/*********************************** TAD METHODS ********************************/
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
 * Makes a IOTICAT_swap from two elements on the database
 * @param i : index of the first element
 * @param j : index of the second element
 */
void IOTICAT_swap(unsigned char i, unsigned char j);

/**
 * User IOTICAT_getUser(unsigned char index)
 * @param index : index from the user we want to extract
 * @return the user in [index] position
 */
User IOTICAT_getUser(unsigned char index);

/**
 * unsigned char IOTICAT_workingUsers()
 * @returns the number of users actually working
 */
unsigned char IOTICAT_workingUsers();

/**
 * unsigned char IOTICAT_allUsers()
 * @returns the number of all users in the system
 */
unsigned char IOTICAT_allUsers();

/**
 * void IOTICAT_show()
 * @details: shows the content of the database
 */
void IOTICAT_show();

#endif //IOTICAT_H
