# 1 "timer.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "timer.c" 2







# 1 "./timer.h" 1
# 22 "./timer.h"
void RSI_Timer0(void);

void TIMER_init (void);





int TIMER_getTimer (void);






void TIMER_resetTics (unsigned char timer_id);






unsigned int TIMER_getTics (unsigned char timer_id);
# 8 "timer.c" 2
# 23 "timer.c"
struct Timer {
    unsigned int h_TicsInicials;
    unsigned char b_busy;
} s_Timers[32];

static unsigned int h_Tics=0;
static int counter;
# 38 "timer.c"
void RSI_Timer0 (void) {


    INTCONbits.TMR0IF = 0;
    TMR0L=6;
    h_Tics++;

    if (h_Tics>=30000) {

        for (counter=0;counter<32;counter++)
            if (s_Timers[counter].b_busy==1)
                s_Timers[counter].h_TicsInicials -= h_Tics;
        h_Tics=0;
    }

}
# 62 "timer.c"
void TIMER_init () {
    unsigned char counter;
    for (counter=0;counter<32;counter++) {
        s_Timers[counter].b_busy=0;
    }
    h_Tics=0;

    T0CONbits.T08BIT=1;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 1;

    TMR0L=6;
    T0CONbits.TMR0ON = 1;

    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
}

int TIMER_getTimer() {
    unsigned char counter=0;
    while (s_Timers[counter].b_busy==1) {
        counter++;
        if (counter == 32) return -1;
    }
    s_Timers[counter].b_busy=1;
    return (counter);
}

void TIMER_resetTics (unsigned char timer_id) {

    s_Timers[timer_id].h_TicsInicials=h_Tics;

}


unsigned int TIMER_getTics (unsigned char timer_id) {
    volatile unsigned int actual;
    actual=h_Tics;
    return (actual-(s_Timers[timer_id].h_TicsInicials));
}
