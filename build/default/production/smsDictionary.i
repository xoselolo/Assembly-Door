# 1 "smsDictionary.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "smsDictionary.c" 2







# 1 "./smsDictionary.h" 1
# 10 "./smsDictionary.h"
typedef struct{
    char numValues;
    char values[5];
}DictionaryEntry;




void SMSDICTIONARY_init();
# 27 "./smsDictionary.h"
char SMSDICTIONARY_getChar(char actualKey, char pressedTimes);
# 8 "smsDictionary.c" 2








static DictionaryEntry dictionary[12];




void SMSDICTIONARY_init(){
    for (int i = 0; i < 12; i++) {
        switch (i){
            case 0:
                dictionary[i].numValues = 1;
                dictionary[i].values[0] = '1';
                break;
            case 1:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'A';
                dictionary[i].values[1] = 'B';
                dictionary[i].values[2] = 'C';
                dictionary[i].values[3] = '2';
                break;
            case 2:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'D';
                dictionary[i].values[1] = 'E';
                dictionary[i].values[2] = 'F';
                dictionary[i].values[3] = '3';
                break;
            case 3:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'G';
                dictionary[i].values[1] = 'H';
                dictionary[i].values[2] = 'I';
                dictionary[i].values[3] = '4';
                break;
            case 4:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'J';
                dictionary[i].values[1] = 'K';
                dictionary[i].values[2] = 'L';
                dictionary[i].values[3] = '5';
                break;
            case 5:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'M';
                dictionary[i].values[1] = 'N';
                dictionary[i].values[2] = 'O';
                dictionary[i].values[3] = '6';
                break;
            case 6:
                dictionary[i].numValues = 5;
                dictionary[i].values[0] = 'P';
                dictionary[i].values[1] = 'Q';
                dictionary[i].values[2] = 'R';
                dictionary[i].values[3] = 'S';
                dictionary[i].values[4] = '7';
                break;
            case 7:
                dictionary[i].numValues = 4;
                dictionary[i].values[0] = 'T';
                dictionary[i].values[1] = 'U';
                dictionary[i].values[2] = 'V';
                dictionary[i].values[3] = '8';
                break;
            case 8:
                dictionary[i].numValues = 5;
                dictionary[i].values[0] = 'W';
                dictionary[i].values[1] = 'X';
                dictionary[i].values[2] = 'Y';
                dictionary[i].values[3] = 'Z';
                dictionary[i].values[4] = '9';
                break;
            case 9:
                dictionary[i].numValues = 1;
                dictionary[i].values[0] = '*';
                break;
            case 10:
                dictionary[i].numValues = 1;
                dictionary[i].values[0] = '0';
                break;
            case 11:
                dictionary[i].numValues = 1;
                dictionary[i].values[0] = '#';
                break;
        }
    }
}
# 109 "smsDictionary.c"
char SMSDICTIONARY_getChar(char actualKey, char pressedTimes){
    if(pressedTimes > dictionary[actualKey - 1].numValues){
        return -1;
    }else{
        return dictionary[actualKey - 1].values[pressedTimes - 1];
    }
}
