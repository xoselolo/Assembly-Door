/*
 * File:   main.c
 * Author: xoselolo
 *
 * Created on 3 de abril de 2020, 11:09
 */


#include <xc.h>
#include "ioticat.h"

void main(void) {
    IOTICAT_init();

    User user;

    strcpy(user.name, "Lua\0");
    strcpy(user.uid, "13331\0");
    TimeInMinutes permanencia;
    permanencia.value[0] = 0x00;
    permanencia.value[1] = 0x40;
    user.min_permanence_time = permanencia;
    user.in_min_hour = 0x08;
    user.in_min_minute = 0x00;
    user.in_max_hour = 0x09;
    user.in_max_minute = 0x00;
    IOTICAT_register(user);


    strcpy(user.name, "MesaSilla\0");
    strcpy(user.uid, "27653\0");
    permanencia.value[0] = 0x00;
    permanencia.value[1] = 0x40;
    user.min_permanence_time = permanencia;
    user.in_min_hour = 0x08;
    user.in_min_minute = 0x00;
    user.in_max_hour = 0x09;
    user.in_max_minute = 0x00;
    IOTICAT_register(user);


    strcpy(user.name, "Xose\0");
    strcpy(user.uid, "38387\0");
    permanencia.value[0] = 0x00;
    permanencia.value[1] = 0x40;
    user.min_permanence_time = permanencia;
    user.in_min_hour = 0x08;
    user.in_min_minute = 0x00;
    user.in_max_hour = 0x09;
    user.in_max_minute = 0x00;
    IOTICAT_register(user);


    strcpy(user.name, "Paula\0");
    strcpy(user.uid, "17179\0");
    permanencia.value[0] = 0x00;
    permanencia.value[1] = 0x40;
    user.min_permanence_time = permanencia;
    user.in_min_hour = 0x08;
    user.in_min_minute = 0x00;
    user.in_max_hour = 0x09;
    user.in_max_minute = 0x00;
    IOTICAT_register(user);

    IOTICAT_show();

    IOTICAT_login("38387\0");

    IOTICAT_show();

    char state = IOTICAT_exists("38387\0");
    printf("Estado: %c\n", state);

    return;
}
