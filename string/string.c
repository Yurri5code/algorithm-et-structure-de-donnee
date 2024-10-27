#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

void InitStr(string1 st,unsigned n){
    st = (string1)malloc(n*sizeof(string1));
}

void writeToStr(string1 st,char* s){
    strcpy(st,s);
}

void writeFromStr(char* s,string1 st){
    strcpy(st,s);
}

void inputStr(string1 st){
    scanf("%s",st);
}

void OutputStr(string1 st){
    printf("%s",st);
}

int Comp(string1 s1,string1 s2){
    return strcmp(s1,s2);
}

void Delete(string1 s,unsigned index, unsigned count){
    unsigned len = strlen(s);
    if(index >= len){
        return;
    }

    unsigned new_len = len - count;
    if(new_len < index){
        new_len = index;
    }

    for(unsigned i = index;i <= new_len;i++){
        s[i] = s[i + count];
    }
    s[new_len] = '\0';
}

void Insert(string1 Subs,string1 s,unsigned Index){
    unsigned len_s = strlen(s),len_Subs = strlen(Subs);

    if(Index > len_s){
        Index = len_s;
    }
    for(unsigned i = len_s; i >= Index; i--){
        s[i + len_Subs] = s[i];
    }
    for(unsigned i = 0;i < len_Subs;i++){
        s[Index + 1] = Subs[i];
    }
}

void Concat(string1 s1,string1 s2,string1 srez){
    if(srez == NULL){
        printf("Memory allocation for srez failed\n");
        return;
    }
    strcpy(srez,s1);
    strcat(srez,s2);
}

void Copy(string1 s,unsigned Index, unsigned Count, string1 Subs){
    if(Index + Count > strlen(s)){
        printf("Index and Count out of bounds\n");
        return;
    }

    strncpy(Subs,s+Index,Count);
    Subs[Count] = '\0';
}

unsigned Length(string1 s){
    return strlen(s);
}

unsigned Pos(string1 Subs,string1 s){
    string1 pos = strstr(s,Subs);
    if(pos != NULL){
        return (unsigned)(pos - s);
    }else{
        return -1;
    }
}

char* pangrams(char* s) {
    if(strlen(s) < 26){
        return "not pangram";
    }
    char* example = {"abcdefghijklmnopqrstuvwxyz"};
    int verif = 0;
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < strlen(s);j++){
            char c = s[j];
            if(s[j]>= 'A' && s[j]<='Z'){
                c = tolower(s[j]);
            }
            if(example[i] == c){
                verif++;
            }
        }
        if(verif == 0){
            return "not pangram";
        }
        verif = 0;
    }
    
    return "pangram";
}
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);

}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);

}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = 0, count_b = 0;
    int char_count[26] = {0};

    for (const char* p = a; *p; p++) {
        if (!char_count[*p - 'a']) {
            char_count[*p - 'a'] = 1;
            count_a++;
        }
    }

    memset(char_count, 0, sizeof(char_count));

    for (const char* p = b; *p; p++) {
        if (!char_count[*p - 'a']) {
            char_count[*p - 'a'] = 1;
            count_b++;
        }
    }

    if (count_a == count_b) {
        return strcmp(a, b);
    } else {
        return count_a - count_b;
    }
    
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a == len_b) {
        return strcmp(a, b);
    } else {
        return len_a - len_b;
    }
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
            for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int giveTHeNumbers(const char s) {
    switch (s) {
        case 'a' :
            return 1;
        case 'b' :
            return 2;
        case 'c' :
            return 3;
        case 'd' :
            return 4;
        case 'e' :
            return 5 ;
        case 'f' :
            return 6;
        case 'g' :
            return 7;
        case 'h' :
            return 8;
        case 'i' :
            return 9;
        case 'j' :
            return 10;
        case 'k' :
            return 11;
        case 'l' :
            return 12;
        case 'm' :
            return 13;
        case 'n' :
            return 14;
        case 'o' :
            return 15;
        case 'p' :
            return 16;
        case 'q' :
            return 17;
        case 'r' :
            return 18;
        case 's' :
            return 19;
        case 't' :
            return 20;
        case 'u' :
            return 21;
        case 'v' :
            return 22;
        case 'w' :
            return 23;
        case 'x' :
            return 24;
        case 'y' :
            return 25;
        case 'z' :
            return 26;
        default:
            return 0;
    }
}

int* returnArray(char* s) {
    int* value = (int*)malloc(strlen(s)*sizeof(int));
    int fois = 2,c = 0;

    //remplicage des valeurs dans le tableau
    value[0] = giveTHeNumbers(s[0]);
    for(int i = 1 ; i < strlen(s);i++) {
        if(s[i] == s[i - 1]) {
            value[i] = value[i - 1 - c] * fois;
            fois++;
            c++;
        }else {
            value[i] = giveTHeNumbers(s[i]);
            fois = 2;
            c = 0;
        }
    }
    return value;
}

char** weightedUniformStrings(char* s, int queries_count, int* queries, int* result_count) {
    //tableau d'entier
    int* array = returnArray(s);
    char** reponse = (char**)malloc(queries_count*sizeof(char*));

    for(int i = 0;i < queries_count;i++) {
        reponse[i] = (char*)malloc(3*sizeof(char));
        int count = 0;
        for(int j = 0; j < strlen(s);j++) {
            if(queries[i] == array[j]) {
                count++;
                break;
            }
        }
        if(count != 0) {
            reponse[i] = "Yes";
        }else {
            reponse[i] = "No";
        }
    }
    free(array);
    *result_count = queries_count;
    return reponse;
}

void DoneStr(string1 s){
    if(s != NULL){
        free(s);
        s = NULL;
    }
}
