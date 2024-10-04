//
// Created by claude delcroix on 05/10/2024.
//
#include <stdio.h>
#include <stdbool.h>
#include "arrayFunctions.h"
//insere la valeur dans l'ordre croissant trouve la position selon l'ordre croissant des chose
int* insertInIncreasing(int* arr,int arrSize,int item,int* returnSize) {
    if(arr[arrSize-1]<=item) {
        *returnSize = arrSize;
        return arr;
    }
    int pos = 0,i = 0;
    while(arr[i]<item) {
        i++;
    }
    if(i == arrSize || i == 0) {
        *returnSize = arrSize;
        return arr;
    }
    pos = i;
    arrSize++;
    for(int j = arrSize;j >= i;j--) {
        arr[j+1] = arr[j];
    }
    /*
    int diff = arrSize - i,t= arrSize - 1;
    while(t >= diff) {
        arr[t+1] = arr[t];
        t--;
    }*/
    arr[pos] = item;
    *returnSize = arrSize ;
    return arr;
}

int* insertionAtTheBeginning(int* array,int arrSize,int item,int* returnSize) {
    for(int i = arrSize;i >= 0;i--) {
        array[i + 1] = array[i];
    }
    array[0] = item;
    arrSize++;
    *returnSize = arrSize;
    return  array;
}

int* insertAtTheIndex(int* array,int arrSize,int item,int index,int* returnSize) {
    int i = arrSize;
    while(i>=index) {
        array[i+1] = array[i];
        i--;
    }
    array[index] = item;
    *returnSize = arrSize + 1;
    return array;
}

int* insertionAfterTheIndex(int* array,int arrSize,int item,int index,int* returnSize) {
    int i = arrSize;
    while(i>=index+1) {
        array[i+1] = array[i];
        i--;
    }
    array[index +1] = item;
    *returnSize = arrSize+1;
    return array;
}

int* insertionBeforeTheGivenIndex(int* array,int arrSize,int item,int index,int* returnSize) {
    int i = arrSize;
    while(i>=index - 1) {
        array[i+1] = array[i];
        i--;
    }
    array[index - 1] = item;
    *returnSize = arrSize + 1;
    return array;
}

int* deleteAtIndex(int* array,int arrSize,int index,int* returnSize) {
    int i = index + 1;
    // int i = index , pour que la position soit retirer et int i = index + 1 pour que l'index soit retirer
    while(i<arrSize) {
        array[i-1] = array[i];
        i++;
    }
    *returnSize = arrSize - 1;
    return array;
}

int* deleteFirste(int* array,int arrSize,int* returnSize) {
    int i = 1;
    while(i<arrSize) {
        array[i - 1] = array[i];
        i++;
    }
    *returnSize = arrSize - 1;
    return array;
}

int* deleteLast(int* array,int arrSize,int* returnSize) {
    if(arrSize > 0) {
        *returnSize = arrSize - 1;
    }
    return array;
}

//a optimiser encore
int returnIndexOf(const int* array,int arrSize,int value) {
    for(int i = 0;i<arrSize;i++) {
        if(array[i] == value) {
            return i;
        }
    }
    return value;
}

bool isValueArray(const int* array,int arrSize,int value) {
    for(int i = 0;i<arrSize;i++) {
        if(array[i] == value) {
            return true;
        }
    }
    return false;
}

int* replaceValueAtIndex(int* array,int index,int value) {
    array[index-1] = value;
    return array;
}
