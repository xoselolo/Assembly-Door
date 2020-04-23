# 1 "ioticat.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ioticat.c" 2








# 1 "./ioticat.h" 1
# 12 "./ioticat.h"
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 2 3
# 25 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 122 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 168 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 411 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 25 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 2 3


void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);
# 65 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 3
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 12 "./ioticat.h" 2








typedef struct {
    unsigned char value[2];
}TimeInMinutes;
# 33 "./ioticat.h"
typedef struct{
    char name[11];
    char uid[6];
    char in_min_hour;
    char in_min_minute;
    char in_max_hour;
    char in_max_minute;
    TimeInMinutes min_permanence_time;
}User;







typedef struct{
    User users[230];
    TimeInMinutes times[100];
    unsigned char cuantos;
    unsigned char cuantos_in;
}IoticatDatabase;
# 65 "./ioticat.h"
void IOTICAT_init();
# 75 "./ioticat.h"
char IOTICAT_register(User user);






void IOTICAT_swap(unsigned char i, unsigned char j);






User IOTICAT_getUser(unsigned char index);





unsigned char IOTICAT_workingUsers();





unsigned char IOTICAT_allUsers();
# 9 "ioticat.c" 2



static IoticatDatabase database;

static User swappy;







void IOTICAT_init(){
    database.cuantos = 0;
    database.cuantos_in = 0;
}
# 34 "ioticat.c"
char IOTICAT_register(User user){
    if(database.cuantos < 230){
        database.users[database.cuantos++] = user;
        return 0;
    }else{
        return 1;
    }
}






void IOTICAT_swap(unsigned char i, unsigned char j){
    swappy = database.users[i];
    database.users[i] = database.users[j];
    database.users[j] = swappy;
# 91 "ioticat.c"
}






User IOTICAT_getUser(unsigned char index){
    return database.users[index];
}





unsigned char IOTICAT_workingUsers(){
    return database.cuantos_in;
}





unsigned char IOTICAT_allUsers(){
    return database.cuantos;
}
