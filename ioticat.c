/* 
 * File:   ioticat.c
 * Author: xoselolo
 *
 * Created on 3 de abril de 2020, 11:10
 */


#include "ioticat.h"

static IoticatDatabase database;
static User swappy;

/**
 * void IOTICAT_init()
 * @details: initializes the empty database
 *      cuantos = 0
 *      cuantos_in = 0
 */
void IOTICAT_init(){
    database.cuantos = 0;
    database.cuantos_in = 0;
}

/**
 * char IOTICAT_register(User user)
 * @details: registers a new user to the database
 * @returns:
 *      @return 0 = NO_ERROR
 *      @return 1 = ERROR (MAX_REGISTERED_USERS reached)
 */
char IOTICAT_register(User user){
    if(database.cuantos < MAX_REGISTERED_USERS){
        database.users[database.cuantos++] = user;
        return 0;
    }else{
        return 1;
    }
}

/**
 * Makes a swap from two elements on the database
 * @param i : index of the first element
 * @param j : index of the second element
 */
void swap(unsigned char i, unsigned char j){
    strcpy(swappy.name, database.users[i].name);
    strcpy(swappy.uid, database.users[i].uid);
    //swappy.name = database.users[i].name;
    //swappy.uid = database.users[i].uid;
    swappy.min_permanence_time.value[0] = database.users[i].min_permanence_time.value[0];
    swappy.min_permanence_time.value[1] = database.users[i].min_permanence_time.value[1];
    swappy.in_min_hour = database.users[i].in_min_hour;
    swappy.in_min_minute = database.users[i].in_min_minute;
    swappy.in_max_hour = database.users[i].in_max_hour;
    swappy.in_max_minute = database.users[i].in_max_minute;

    strcpy(database.users[i].name, database.users[j].name);
    strcpy(database.users[i].uid, database.users[j].uid);
    //database.users[i].name = database.users[j].name;
    //database.users[i].uid = database.users[j].uid;
    database.users[i].min_permanence_time.value[0] = database.users[j].min_permanence_time.value[0];
    database.users[i].min_permanence_time.value[1] = database.users[j].min_permanence_time.value[1];
    database.users[i].in_min_hour = database.users[j].in_min_hour;
    database.users[i].in_min_minute = database.users[j].in_min_minute;
    database.users[i].in_max_hour = database.users[j].in_max_hour;
    database.users[i].in_max_minute = database.users[j].in_max_minute;

    strcpy(database.users[j].name, swappy.name);
    strcpy(database.users[j].uid, swappy.uid);
    //database.users[j].name = swappy.name;
    //database.users[j].uid = swappy.uid;
    database.users[j].min_permanence_time.value[0] = swappy.min_permanence_time.value[0];
    database.users[j].min_permanence_time.value[1] = swappy.min_permanence_time.value[1];
    database.users[j].in_min_hour = swappy.in_min_hour;
    database.users[j].in_min_minute = swappy.in_min_minute;
    database.users[j].in_max_hour = swappy.in_max_hour;
    database.users[j].in_max_minute = swappy.in_max_minute;

    printf("\nuid I: %s\n", database.users[i].uid);
    printf("uid J: %s\n", database.users[j].uid);
    printf("uid sw: %s\n", swappy.uid);
}


/**
 * char IOTICAT_login(User user)
 * @details: user enters to work (if there's space in the institute)
 * @param uid : user ID
 * @return :
 *      @return 0 = NO_ERROR
 *      @return 1 = ERROR (MAX_WORKING_USERS reached)
 *      @return 2 = USER_NOT_RECOGNIZED
 */
char IOTICAT_login(const char uid[6]){
    if(database.cuantos_in < MAX_WORKING_USERS){
        // search the user with the same uid
        for(unsigned char i = database.cuantos_in; i < database.cuantos; i++){
            printf("[INFO] ------------ Checking %s with %s\n", database.users[i].uid, uid);
            if (strcmp(database.users[i].uid, uid) == 0){
                // user is registered
                swap(i, database.cuantos_in); // make the swap
                database.cuantos_in++;
                return 0;
            }
        }
        return 2;
    }else{
        return 1;
    }
}


/**
 * void IOTICAT_show()
 * @details: shows the content of the database
 */
void IOTICAT_show(){
    printf("\n-- WORKING EMPLOYEES --\n");
    for (int i = 0; i < database.cuantos_in; i++) {
        printf("Employee: %s - %s\n", database.users[i].name, database.users[i].uid);
    }

    printf("\n-- REGISTERED EMPLOYEES --\n");
    for (int i = database.cuantos_in; i < database.cuantos; i++) {
        printf("Employee: %s - %s\n", database.users[i].name, database.users[i].uid);
    }
}


/**
 * char IOTICAT_exists(char uid[6])
 * @param uid : ID from the user we a re checking
 * @returns :
 *      @return 0 = not exists
 *      @return 1 = exists and is working
 *      @return 2 = exists and not working
 */
char IOTICAT_exists(char uid[6]){
    for(unsigned char i = 0; i < database.cuantos; i++){
        if (strcmp(database.users[i].uid, uid) == 0){
            // user is registered
            if (i < database.cuantos_in){
                return 1;
            }else{
                return 2;
            }
        }
    }
    // user not found
    return 0;
}