/*******************************************************************************
* nipa
* Linux port
*******************************************************************************/

#ifndef NIPA_H
#define NIPA_H

#include <stddef.h>

int my_crypt(int, int);
int my_crypt2(int, char*);
int newid();

void addentry(char *, char *, int, int, int);
void createnpa(int, char **, int);
void extractnpa(int, int, char *);
void parsedir(char*);
void parsenpa(char *, int);

typedef struct _npahead
{
    char head[7];       /* MUST start with NPA\x01\x00 or it gets flagged as not an NPA archive. */
    int key1;           /* Keys required for decryption purposes */
    int key2;
    int encrypt;        /* 1 if encrypted */
    int compress;       /* 1 if compressed */
    int filecount;      /* Before folders */
    int foldercount;
    int totalcount;     /* File count + folder count */
    long null;          /* These 8 bytes appear unused */
    int start;          /* Starting offset for data. Filetable - 0x29 (header) usually */
    int gameid;         /* Game ID used for encryption */
} NPAHEAD;

typedef struct _npaentry
{
    int nlength;        /* Name length */
    char *filename;     /* Size based on nlength */
    int type;           /* 1 = folder, 2 = file */
    int fileid;
    int offset;
    int compsize;       /* Compressed filesize */
    int origsize;       /* Original filesize */
} NPAENTRY;

/*
* All keys listed are the generated form and not the original form.
*/

extern char games[][20];
enum { CHAOSHEAD = 0, CHAOSHEADTR1, CHAOSHEADTR2, MURAMASATR, MURAMASA, SUMAGA, DJANGO, DJANGOTR,
    LAMENTO, LAMENTOTR, SWEETPOOL, SUMAGASP, DEMONBANE, MURAMASAAD, AXANAEL, KIKOKUGAI, SONICOMITR2,
    SUMAGA3P, SONICOMI, LOSTX, LOSTXTRAILER, DRAMATICALMURDER, TOTONO, DRAMATICALMURDERRC, MURAMASASS};

extern unsigned char keytbl[][0x100];

#endif /* NIPA_H */
