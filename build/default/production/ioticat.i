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
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 2 3
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 122 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 137 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 168 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 246 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 12 "./ioticat.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 1 3
# 25 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
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
# 13 "./ioticat.h" 2








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
# 60 "./ioticat.h"
typedef struct{
    User users[5];
    TimeInMinutes times[2];
    unsigned char cuantos;
    unsigned char cuantos_in;
}IoticatDatabase;
# 75 "./ioticat.h"
void IOTICAT_init();
# 85 "./ioticat.h"
char IOTICAT_register(User user);






void swap(unsigned char i, unsigned char j);
# 102 "./ioticat.h"
char IOTICAT_login(const char uid[2]);





void IOTICAT_show();
# 119 "./ioticat.h"
char IOTICAT_exists(char uid[6]);
# 9 "ioticat.c" 2


static IoticatDatabase database;
static User swappy;







void IOTICAT_init(){
    database.cuantos = 0;
    database.cuantos_in = 0;
}
# 32 "ioticat.c"
char IOTICAT_register(User user){
    if(database.cuantos < 5){
        database.users[database.cuantos++] = user;
        return 0;
    }else{
        return 1;
    }
}






void swap(unsigned char i, unsigned char j){
    strcpy(swappy.name, database.users[i].name);
    strcpy(swappy.uid, database.users[i].uid);


    swappy.min_permanence_time.value[0] = database.users[i].min_permanence_time.value[0];
    swappy.min_permanence_time.value[1] = database.users[i].min_permanence_time.value[1];
    swappy.in_min_hour = database.users[i].in_min_hour;
    swappy.in_min_minute = database.users[i].in_min_minute;
    swappy.in_max_hour = database.users[i].in_max_hour;
    swappy.in_max_minute = database.users[i].in_max_minute;

    strcpy(database.users[i].name, database.users[j].name);
    strcpy(database.users[i].uid, database.users[j].uid);


    database.users[i].min_permanence_time.value[0] = database.users[j].min_permanence_time.value[0];
    database.users[i].min_permanence_time.value[1] = database.users[j].min_permanence_time.value[1];
    database.users[i].in_min_hour = database.users[j].in_min_hour;
    database.users[i].in_min_minute = database.users[j].in_min_minute;
    database.users[i].in_max_hour = database.users[j].in_max_hour;
    database.users[i].in_max_minute = database.users[j].in_max_minute;

    strcpy(database.users[j].name, swappy.name);
    strcpy(database.users[j].uid, swappy.uid);


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
# 95 "ioticat.c"
char IOTICAT_login(const char uid[6]){
    if(database.cuantos_in < 2){

        for(unsigned char i = database.cuantos_in; i < database.cuantos; i++){
            printf("[INFO] ------------ Checking %s with %s\n", database.users[i].uid, uid);
            if (strcmp(database.users[i].uid, uid) == 0){

                swap(i, database.cuantos_in);
                database.cuantos_in++;
                return 0;
            }
        }
        return 2;
    }else{
        return 1;
    }
}






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
# 139 "ioticat.c"
char IOTICAT_exists(char uid[6]){
    for(unsigned char i = 0; i < database.cuantos; i++){
        if (strcmp(database.users[i].uid, uid) == 0){

            if (i < database.cuantos_in){
                return 1;
            }else{
                return 2;
            }
        }
    }

    return 0;
}
