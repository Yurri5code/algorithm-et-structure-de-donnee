//
// Created by claude delcroix on 05/10/2024.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "arrayFunctions.h"
#define TRUE 1
#define FAlSE 0

//insere la valeur dans l'ordre croissant trouve la position selon l'ordre croissant des chose
int* insertInIncreasing(int* arr,int arrSize,const int item,int* returnSize) {
    if(arr[arrSize-1]<=item) {
        *returnSize = arrSize;
        return arr;
    }
    int i = 0;
    while(arr[i]<item) {
        i++;
    }
    if(i == arrSize || i == 0) {
        *returnSize = arrSize;
        return arr;
    }
    int pos = i;
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

char** summaryRanges(const int* nums,int numsSize,int* returnSize) {
    char **charArray = (char **) malloc(numsSize * sizeof(char *));
    if(numsSize == 0) {
        *returnSize = 0;
        return charArray;
    }

    int first = 0,last = 0,count = 0;

    for(int i = 1;i < numsSize;i++) {
        if(nums[i-1] + 1 == nums[i]) {
            last++;
        }else {
            charArray[count] = malloc(25);
            if(first == last) {
                sprintf(charArray[count],"%d",nums[first]);
            }else {
                sprintf(charArray[count],"%d->%d",nums[first],nums[last]);
            }
            count++;
            first = last + 1;
            last++;
        }
    }
    charArray[count] = malloc(25);
    if(first == last) {
        sprintf(charArray[count],"%d",nums[first]);
    }else {
        sprintf(charArray[count],"%d->%d",nums[first],nums[last]);
    }
    count++;
    *returnSize = count;
    return charArray;
}

//cette fonction a 0 ms et est rapide et consomme peu d'espace
void moveZeroes(int* nums,const int numsSize) {
    int noZero = 0;
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] != 0) {
            nums[noZero] = nums[i];
            noZero++;
        }
    }
    for(int i = noZero;i < numsSize;i++) {
        nums[i] = 0;
    }
    for(int i = 0;i < numsSize;i++) {
        printf("%d  ",nums[i]);
    }
}

//voici mon idee de base tres lente
void moveZeroes1(int* nums, const int numsSize) {
    int count = 0;
    for(int i = 0; i<numsSize; i++)
    {
        while(nums[i]==0 && count<numsSize){
            for(int j = i; j<numsSize-1; j++)
            {
                nums[j] = nums[j+1];
            }
            nums[numsSize - 1] = 0;
            count++;
        }
    }
}

int minValue(const int x,const int y) {
    if(x < y) {
        return x;
    }else {
        return y;
    }
}

int maxValue(const int x,const int y) {
    if(x > y) {
        return x;
    }else {
        return y;
    }
}

int maximumStrongPairXor(const int* nums,const int numsSize) {
    int max = 0;
    for(int i = 0; i < numsSize;i++) {
        for(int j = 0;j < numsSize; j++) {
            if(abs(nums[i] - nums[j]) <= minValue(nums[i],nums[j])) {
               if((nums[i] ^ nums[j]) >= max) {
                   max = nums[i] ^ nums[j];
               }
            }
        }
    }
    return max;
}

void tri_a_bulle(int* t,const int n) {
    int en_desordre = 1;

    while(en_desordre) {
        en_desordre = FAlSE;
        for(int j = 0;j < n - 1;j++) {
            if(t[j] > t[j+1]) {
                const int tmp = t[j];
                t[j] = t[j + 1];
                t[j+1] = tmp;
                en_desordre = TRUE;
            }
        }
    }
}

int* intersection(int* nums1, int nums1Size,int* nums2,int nums2Size,int* returnSize) {
    tri_a_bulle(nums1,nums1Size);
    tri_a_bulle(nums2,nums2Size);

    int count = 0,notSame = -1;
    const short size = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* array = (int*)malloc(size*sizeof(int));

    for(int i = 0;i < nums1Size;i++) {
        for(int j = 0;j < nums2Size;j++) {
            if(nums1[i] == nums2[j] && nums1[i] != notSame) {
                array[count++] = nums1[i];
                notSame = nums1[i];
                break;
            }
            if(nums2[j] > nums1[i]) {
                break;
            }
        }
    }
    *returnSize = count;
    return array;
}

/*
 * les programmeurs utilisant C, ont tous eviter d'utiliser cette fonction et on meme
 * changer tout le code
 * voir github GetMax
 */
int* getMax(const int operation_count,char** operations,int* result_count) {
    int* array = (int*)malloc(operation_count*sizeof(int));
    int max = 0,j = 0;

    for(long i = 0;i < operation_count;i++) {
        if(operations[i][0] == '1') {
            const char* suite = strchr(operations[i],operations[i][2]);
            const int value = atoi(suite);
            if(value > max ) {
                max = value;
            }
            array[j] = value;
            j++;
        }
        else if(operations[i][0] == '2') {
            if(j > 0) {
                j--;
            }
        }else {
            printf("%d\n",max);
        }
    }
    *result_count = j;
    return array;
}

void swap(int* xp,int* yp) {
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int* arr,const int n) {
    for(int i = 0; i < n-1;i++) {
        for(int j = 0; j < n-i-1;j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[],int n) {
    for(int i = 1;i < n;i++) {
        const int key = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

int majorityElement(int* nums,const int numsSize) {
    int maj = 0,el = 0,max = 0;
    insertionSort(nums,numsSize);
    int first = nums[0];

    for(int i = 0;i < numsSize;i++) {
        if(nums[i] == first) {
            el++;
        }else {
            first = nums[i];
            if(el > maj) {
                max = nums[i-1];
                maj = el;
            }
            el = 1;
        }
    }
    if(el > maj) {
        max = nums[numsSize - 1];
    }

    return max;
}

//le code suivant resout le probleme sans tri avec une intelligence
//particuliere . 11.11.2024
int majorityElement1(const int* nums, const int numsSize) {
    int sel = 0, cnt = 0;
    for(int i = 0; i < numsSize; i++) {
        if(cnt == 0) {
            sel = nums[i];
            cnt++;
        } else if(nums[i] == sel) {
            cnt++;
        } else {
            cnt--;
        }
    }
    return sel;
}
/*
 * le code suivant est a mediter dessus il resout le probleme
 * de majorityElement avec 3ms
* int compare(const void* a, const void* b)
{
    return(*(int*)a-*(int*)b);
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),compare);
    return nums[numsSize / 2];
}
 */

//table de hachage sur tableau pour exo contains duplicat ||

int hash(const int key) {
    return key % TABLE_SIZE;
}

hashTable* createTable() {
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if(table == NULL) {
        fprintf(stderr,"l'allocation sur table a echouee\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < TABLE_SIZE;i++) {
        table->table[i] = NULL;
    }
    return table;
}

hashTable* createTableOptimisation() {
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    if (table == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memset(table->table, 0, sizeof(table->table));
    return table;
}

void insert(hashTable* table,const int index,const int value,int* ok,const int k) {
    const int hashIndex = hash(value);
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL) {
        fprintf(stderr,"l'allocation de newNode a echouee\n");
        exit(EXIT_FAILURE);
    }
    newNode->index = index;
    newNode->value = value;
    if(table->table[hashIndex] != NULL) {
        node* current = table->table[hashIndex];
        while(current != NULL) {
            if((current->value == value) && abs(current->index - index) <= k) {
                *ok = 1;
                free(newNode);
                return;
            }
            current = current->next;
        }
    }
    newNode->next = table->table[hashIndex];
    table->table[hashIndex] = newNode;
}

void deleteHashTable(hashTable* table) {
    for(int i = 0;i < TABLE_SIZE;i++) {
        node* temp = table->table[i];
        while(temp != NULL) {
            node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(table);
}
/*
 * sans la fonction delete dans la fonction contains Duplicate
 * le code ne fait que 39 et 73 mb
 */

//le code suivant resolut le probleme avec 0ms et que 14.4 mb soit la meilleure solution de toue

/*
* #define MAX 300000
    bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int record[MAX];

    memset(record, -1, sizeof(record));

    for(int i = 0, tmp; i < numsSize; i++){
        tmp = ((nums[i] % MAX) + MAX) % MAX;

        if(record[tmp] != -1 && i - record[tmp] <= k){
            return true;
        }

        record[tmp] = i;
    }
    return false;
}
 */

int missingNumber(int* nums,const int numsSize) {
    bubbleSort(nums,numsSize);

    if(nums[numsSize - 1] != numsSize) {
        return numsSize;
    }
    for(int i = 0;i < numsSize;i++) {
        if(i != nums[i]) {
            return i;
        }
    }
    return 0;
}

//meilleure solution de missingNumber
int missingNumber1(const int* nums,const  int numsSize) {

    const int tot=(numsSize*(numsSize+1))/2;
    int sum=0;
    for(int i=0;i<numsSize;i++)
        sum+=nums[i];
    const int res=tot-sum;
    return res;

}

// 350. intersection of two array 2

void insertIntersect(hashTable* table, const int value){
    const int hashIndex = hash(value);
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    newNode->value = value;
    newNode->nbrFois = 1; // Initialisation correcte
    newNode->next = table->table[hashIndex];
    table->table[hashIndex] = newNode;
}

void printTable(const hashTable* table) {
    for(int i = 0;i < TABLE_SIZE;i++) {
        if(table->table[i] != NULL) {
            node* current = table->table[i];
            while(current != NULL) {
                printf("(%d,%d,%d)->",current->index,current->value,current->nbrFois);
                current = current->next;
            }
        }
    }
    printf("NULL\n");
}

void insertWithHash(const hashTable* table, const int value, int* array, int* sizeArr) {
    const int hashIndex = hash(value);
    node* current = table->table[hashIndex];
    while (current != NULL) {
        if (current->value == value && current->nbrFois > 0) {
            array[(*sizeArr)++] = value;
            current->nbrFois -= 1;
            return;
        }
        current = current->next;
    }
}

int* intersect(const int* nums1, int nums1Size,const  int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0; // Initialisation correcte de returnSize
    hashTable* table = createTable();
    const short sizeArray = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* array = (int*)malloc(sizeArray * sizeof(int));
    if(array == NULL){
        fprintf(stderr,"allocation failed\n");
        exit(1);
    }

    for(int i = 0; i < nums1Size; i++){
        insertIntersect(table, nums1[i]);
    }
    for(int i = 0; i < nums2Size; i++){
        insertWithHash(table, nums2[i], array, returnSize);
    }

    deleteHashTable(table);
    return array;
}
