/*
 * File:   rastreator.c
 * Author: xoselolo
 *
 * Created on 6 de abril de 2020, 12:31
 */

#include "rastreator.h"

static char state = 0;

static char work = 0;
static char uid[6];

static unsigned char allUsers = 0;
static unsigned char workingUsers = 0;

static unsigned char index = 0;
static User user;

static char result = 0;
static unsigned char user_index = 0;

void RASTREATOR_find(char user_id[6]){
    strcpy(uid, user_id);
    work = 1;
}

void RASTREATOR_motor(){
    switch (state){
        case 0:
            if(work > 0){
                index = 0;
                workingUsers = IOTICAT_workingUsers();
                allUsers = IOTICAT_allUsers();
            }
            break;
        case 1:
            user = IOTICAT_getUser(index);
            if(index < workingUsers){
                state = 2;
            }else{
                state = 4;
            }
            break;
        case 2:
            if(strcmp(user.uid, uid) == 0){
                result = 1;
                work = 0;
                user_index = index;
                state = 0;
            }else{
                index++;
                state = 1;
            }
            break;
        case 3:
            if (index < allUsers){
                state = 4;
            }else{
                result = 3;
                work = 0;
                state = 0;
            }
            break;
        case 4:
            if(strcmp(user.uid, uid) == 0){
                result = 2;
                work = 0;
                user_index = index;
                state = 0;
            }else{
                index++;
                state = 3;
            }
            break;
    }
}
