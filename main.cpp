#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL,"Russian");
    char IN[80], OUT[80];
    cout << "Введите файл с которого будеи считана строка: ";
    gets(IN);
    FILE *in = fopen(IN, "r");
    cout << "Введите файл, в который будет записана строка: ";
    gets(OUT);
    FILE *out = fopen(OUT, "w");
    char c[256], t;
    int s = 0, space = 0, d = 0;
    while((t = (char)fgetc(in)) == ' ') {
        continue;
    }
    c[s++] = t;
    while((t = (char) fgetc(in)) != EOF && t != '\n' && t != '\r') {
        if(t == '.')
        {
            if(space == 0)
            {
                c[s++] = t;
                space = 0;
            }
            else
            {
                c[s - 1] = '.';
                space = 0;
            }
        }
        else if(t == ' ')
        {
            if(space == 0)
            {
                c[s++] = t;
                space=1;
            }
            else
                c[s] = t;
        }
        else
        {
            c[s++]=t;
            space=0;
        }
    }
    if(c[s-1]==' ') {
        c[--s]='\0';
    }
    else {
        c[s]='\0';
    }
    fprintf(out, "Задание 1: %s\n", c);
    char p[256];
    p[0] = p[1] = 0;
    char h = c[s - 1];
    int l = s - 1;
    while (h == '.') {
        h = c[l--];
    }
    int f = l;
    while (h != ' ') {
        h = c[f--];
    }
    int len = l - ++f + 1;
    char PS[256];
    for (int i = f; i <= l; i++) {
        PS[i - f] = c[i + 1];
    }
    PS[len] = '\0';
    char *pch = strtok(c, " ");
    while (pch != NULL) {
        if (strcmp(PS, pch) != 0)
        {
            strcat(p, pch);
            strcat(p, " ");
        }
        pch = strtok(NULL, "  .");
    }
    fprintf(out, "Задание 2: %s\n", p);
    fprintf(out, "Задание 3: ");
    char PZ[256];
    PZ[0] = PZ[1] = 0;
    unsigned long long y, ind;
    int m;
    char *rew=strtok(p, " .");
    while (rew != NULL){
        y = strlen(rew);
        m = 1;
        for (ind = 1; ind < y; ind++){
            if(rew[0] == rew[ind]) {
                m++;
            }
        }
        if (m == 2) {
            strcat(PZ, rew);
            strcat(PZ, " ");
        }
        rew = strtok(NULL, " .");
    }
    fprintf(out,"%s", PZ);
}
