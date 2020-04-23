/* 
 * File:   timer.h
 * Author: xoselolo
 *
 * Created on 23 de abril de 2020, 15:20
 */

#ifndef _TIMER_H
#define _TIMER_H

// Si anem justos de memoria, aquest define indica el
// nombre de timers d'aquest TAD i es pot modificar sense
// problemes.
#define         TI_NUMTIMERS                    32


// El seg?ent define marca la dist?ncia temporal m?xima
// entre un gettics i un resettics
//#define         TI_MAXTICS                      8640000000L //Suficient per aprox. 100 dies
#define         TI_MAXTICS                      30000 //Suficient per aprox. 30 o 40 segons

void RSI_Timer0(void);
//La RSI
void TIMER_init (void);
/*********************************************************************
//Postcondicions: Inicialitza el T.A.D. ?s precondici? global haver cridat
//                aquesta funci? quan es cridi qualsevol altra funci?.
\\*********************************************************************/

int TIMER_getTimer (void);
/*********************************************************************
//Precondicions: Hi ha algun timer lliure. Maxim TI_NUMTIMERS
//Postcondicions: Retorna un handle per usar les funcions TiGetTics i
//TiResetTics. Retorna -1 si no hi ha cap timer disponible.
\\*********************************************************************/

void TIMER_resetTics (unsigned char timer_id);
/*********************************************************************
//Precondicions: Handle ha estat retornat per Ti_OpenTimer.
//Postcondicions: Engega la temporitzaci? associada a 'Handle'.
//              i agafa la referencia temporal del sistema
\\*********************************************************************/

unsigned int  TIMER_getTics (unsigned char timer_id);
/*********************************************************************
//Precondicions: Handle ha estat retornat per TiGetTimer.
// La dist?ncia temmporal entre GetTics i ResetTics ha de ser menor
// de TI_MAXTICS ms (actualment, 30 segons)
//Postcondicions: Retorna els milisegons transcorreguts des de la crida
//                a l'StartTimer del 'Handle'.
\\*********************************************************************/


#endif //MITJANAJOAN_TIMER_H
