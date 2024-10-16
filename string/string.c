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

void DoneStr(string1 s){
    if(s != NULL){
        free(s);
        s = NULL;
    }
}
