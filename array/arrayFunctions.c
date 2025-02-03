//
// Created by claude delcroix on 05/10/2024.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

//solution avec qsort une maniere generique de trier
int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int* intersectQsort(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int)*1001);
    if(result == NULL) {
        perror("error allocation \n");
        exit(EXIT_FAILURE);
    }
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int length = 0, i, j;

    for(i = 0, j = 0; i < nums1Size && j < nums2Size; i++, j++){
        if(nums1[i] == nums2[j])
            result[length++] = nums1[i];
        else if(nums1[i] < nums2[j])
            j--;
        else
            i--;
    }

    *returnSize = length;
    //result = realloc(result, sizeof(int)*length);
    return result;
}
// il a utiliser realloc pour reamenager la menoire c'est ingenieux.

int mySqrt(const int x) {
    if(x == 1)return 1;
    if(x < 2){
        return 0;
    }

    int start = 0, end = x / 2, result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long sqr = (long)mid * mid;

        if (sqr == x) {
            return mid;
        } else if (sqr < x) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    return result;
}

bool isPerfectSquare(const int num) {
    if(num == 1) {
        return true;
    }

    int start = 0,end = num / 2;

    while(start <= end) {
        long long mid = (start + end)/2;
        long long sqrt = mid*mid;

        if(sqrt == num) {
            return true;
        }else if(sqrt < num) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return false;
}

int partition(int arr[],int low,int high) {
    const int pivot = arr[high];
    int i = (low - 1);

    for(int j = low;j < high;j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
}

void quickSort(int arr[],int low,int high) {
    if(low < high) {
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi -1);
        quickSort(arr,pi + 1,high);
    }
}

void printArray(const int arr[],const size_t size) {
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    printf("         end of array\n");
}

//quickSort sans recursion n'effectue que la premiere etape
int* quickSort1(const int arr_count,const int* arr,int* result_count) {
    *result_count = arr_count;
    int j = 0,pivot = arr[0];
    int* ar = (int*)malloc(arr_count*sizeof(int));

    for(int i = 0;i < arr_count;i++) {
        if(arr[i] < pivot) {
            ar[j++] = arr[i];
        }
    }

    ar[j++] = pivot;
    for(int i = 0;i < arr_count;i++) {
        if(arr[i] > pivot) {
            ar[j++] = arr[i];
        }
    }

    return ar;
}

void swapShell(int array[],const int a,const int b){
    array[a] = array[a] + array[b];
    array[b] = array[a] - array[b];
    array[a] = array[a] - array[b];
}

void shellShort(int array[],const int length){
    for(int gap = length/2;gap>0;gap = gap /2){
        for(int i = gap;i < length;i++){
            int j = i;
            while(j - gap >= 0 && array[j] < array[j - gap]){
                swapShell(array,j,j - gap);
                j = j - gap;
            }
        }
    }
}

int thirdMax(int* nums, int numsSize) {
    if(numsSize == 1){
        return nums[0];
    }else if(numsSize == 2){
        if(nums[0] > nums[1]){
            return nums[0];
        }else{
            return nums[1];
        }
    }

    quickSort(nums,0,numsSize -1);
    int max = nums[numsSize - 1],i = numsSize -1;
    while(max == nums[i] && i > 0){
        i--;
    }
    max = nums[i];
    while(max == nums[i] && i>0){
        i--;
    }
    if(max == nums[0]){
        i--;
    }
    if(i < 0){
        return nums[numsSize - 1];
    }

    return nums[i];
}

int* cutTheSticks(int arr_count,int* arr,int* result_count) {
    quickSort(arr,0,arr_count -1);

    int final = 0,k = 0,size = 1;
    int* t = (int*)malloc(arr_count*sizeof(int));
    int* result = (int*)malloc(arr_count*sizeof(int));
    result[0] = arr_count;

    while(final != 1) {
        const int min = arr[0];
        for(int i = 0;i < arr_count;i++) {
            if((arr[i] - min)>0) {
                t[k] = arr[i] - min;
                k+=1;
            }
        }

        for(int i = 0;i <= k;i++) {
            arr[i] = t[i];
        }
        final = k;
        arr_count = k;
        printf("k = %d \n",k);
        if(k > 0) {
            result[size++] = k;
        }
        k = 0;
    }
    result = (int*)realloc(result,size*sizeof(int));
    *result_count = size;
    free(t);
    return result;
}

int* cutTheSticksOptimisationVersion(int arr_count, int* arr, int* result_count) {
    quickSort(arr, 0, arr_count - 1);

    int size = 0;
    int* result = (int*)malloc(arr_count * sizeof(int));
    result[size++] = arr_count;

    int current_length = arr_count;
    int min = arr[0];

    for (int i = 0; i < arr_count;) {
        int count = 0;
        while (i < arr_count && arr[i] == min) {
            count++;
            i++;
        }
        current_length -= count;
        if (current_length > 0) {
            result[size++] = current_length;
            if (i < arr_count) {
                min = arr[i];
            }
        }
    }

    result = (int*)realloc(result, size * sizeof(int));
    *result_count = size;

    return result;
}

bool compareArray(const int* arr1,const int* arr2,const int size1,const int size2) {
    if(size1 != size2) {
        return false;
    }

    for(int i = 0;i < size1;i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

//la fonction countingSort1 compte pour 100 element
int* countingSort1(int arr_count,const int* arr,int* result_count) {
    int* result = (int*)calloc(100,sizeof(int));
    if(result == NULL) {
        fprintf(stderr,"allocation failled\n");
        exit(EXIT_FAILURE);
    }
    *result_count = 100;

    for(int i = 0;i < arr_count;i++) {
        result[arr[i]]++;
    }
    return result;
}

int* countingSort(int arr_count,const int* arr,int* returnSize) {
    int* result = (int*)calloc(100,sizeof(int));
    if(result == NULL) {
        fprintf(stderr,"allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0;i < arr_count;i++) {
        result[arr[i]]++;
    }
    printArray(result,arr_count);
    int* newArray = (int*)calloc(arr_count,sizeof(int));
    if(newArray == NULL) {
        fprintf(stderr,"allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for(int i = 0;i < 100;i++) {
        if(result[i] == 1) {
            newArray[j] = i;
            j++;
        }else if(result[i] > 1) {
            int c = result[i];
            while(c > 0) {
                newArray[j] = i;
                j++;
                c--;
            }
        }
    }
    printf("affiche newArray\n");
    printArray(newArray,j);
    *returnSize = arr_count;
    free(result);
    return newArray;
}

int* countingSortOptimisation(int arr_count,const int* arr, int* result_count) {
    // Trouver la valeur maximale dans le tableau pour optimiser la taille de "result"
    int max_val = 0;
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Allouer de la mémoire pour le tableau de comptage
    int* result = (int*)calloc(max_val + 1, sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Remplir le tableau de comptage
    for (int i = 0; i < arr_count; i++) {
        result[arr[i]]++;
    }

    // Allouer de la mémoire pour le tableau trié
    int* sortedArray = (int*)malloc(arr_count * sizeof(int));
    if (sortedArray == NULL) {
        fprintf(stderr, "allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Remplir le tableau trié en fonction des occurrences
    int j = 0;
    for (int i = 0; i <= max_val; i++) {
        while (result[i] > 0) {
            sortedArray[j++] = i;
            result[i]--;
        }
    }

    *result_count = arr_count;
    free(result);
    return sortedArray;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int square = 0;
    for(unsigned int i = 0;i <= number;i++) {
        square +=i;
    }
    square = pow(square,2);

    return square;
}

unsigned int sum_of_squares(unsigned int number){
    unsigned int square = 0;
    for(unsigned int i = 1;i <= number;i++) {
        square += pow(i,2);
    }
    return square;
}

unsigned int difference_of_squares(unsigned int number) {
    return (unsigned int)(square_of_sum(number) - sum_of_squares(number));
}
/*
 * meilleure solution en evitant les boucles
* unsigned int square_of_sum(unsigned int number)
{
   unsigned int sum = (number * (number + 1)) / 2;
   return sum * sum;
}

unsigned int sum_of_squares(unsigned int number)
{
   return (number * (number + 1) * ((number * 2) + 1)) / 6;
}

unsigned int difference_of_squares(unsigned int number)
{
   return square_of_sum(number) - sum_of_squares(number);
}
 */

void mergeSort(int array[],int temp[],int left,int right){
    if(left < right){
        int center = (left + right)/2;
        mergeSort(array,temp,left,center);//left merge sort
        mergeSort(array,temp,center+1,right);//right merge sort
        merge(array,temp,left,center+1,right);//merge two ordered arrays
    }
}

void merge(int array[],int temp[],int left,int right,int rightEndIndex){
    int leftEndIndex = right - 1;
    int tempIndex = left;
    int elementNumber = rightEndIndex - left + 1;

    while(left <= leftEndIndex && right <= rightEndIndex){
        if(array[left] <= array[right]){
            temp[tempIndex++] = array[left++];
        }else{
            temp[tempIndex++] = array[right++];
        }
    }

    while(left <= leftEndIndex){
        temp[tempIndex++] = array[left++];
    }

    while(right <= rightEndIndex){
        temp[tempIndex++] = array[right++];
    }

    for(int i = 0;i < elementNumber;i++){
        array[rightEndIndex] = temp[rightEndIndex];
        rightEndIndex--;
    }
}

void sort(int array[],int length){
    int temp[length];
    mergeSort(array,temp,0,length - 1);
}

/*
 * la fonction counterBit calcul le nombre de bits d'un nombre
 */
long countBits(long number) {
    long count = 0;

    if (number < 0) {
        number = ~number; // On prend le complément à un
    }

    // Compter les bits
    while (number > 0) {
        count++;
        number >>= 1; // Décaler le nombre vers la droite
    }

    return count;
}

/*la fonction counterGame calcul le vainqueur entre deux
 * joueur Louise et Richard
 *
 */
int countSetBits(unsigned long long n) {
    int count = 0;
    while(n) {
        count += n&1;
        n >>=1;
    }

    return count;
}
char* counterGame(const long n) {
    const int m = countSetBits(n - 1);

    return m % 2 == 0? "Richard" : "Louise";
}

int maximunCount(const int* nums,const int numsSize) {
    int minus = 0,plus = 0;
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] < 0) {
            minus++;
        }
        if(nums[i] > 0) {
            plus++;
        }
    }
    return plus >= minus ? plus : minus;
}


void removeDuplicates(int* arr, int* size) {
    if (*size == 0) return;

    int temp[*size];
    int j = 0;

    for (int i = 0; i < *size; i++) {
        int k;
        for (k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                break;
            }
        }

        // If no duplicate is found, add it to the temp array
        if (k == j) {
            temp[j] = arr[i];
            j++;
        }
    }

    // Copy non-duplicate elements back to the original array
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    // Update the size to the new length
    *size = j;
}

/*
 * cette fonction findDissappearedNumber permet de creer a partir d'un tableau existant et de mettre dans le nouvea tableau
 * les elements absents du premier
 * exemple t[] = {1,2,3,5,5,7,5,9,11}
 * le nouveau tab qui sera renvoyer sera tab[] = {4,6,7,8,10}
 * sur leetcode la fonction passe les tests avec 4ms c'est plutot bon
 * il y a des codes avec 23ms
 */
int* findDisappearedNumbers(const int* nums,const int numsSize,int* returnSize) {
    int* result = (int*)calloc(numsSize+1,sizeof(int));
    if(result == NULL) {
        perror("allocation failed \n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i < numsSize;i++) {
        result[nums[i]]++;
    }

    printArray(result,numsSize+1);
    int* solution = (int*)malloc(numsSize*sizeof(int));
    int c = 0;
    for(int i = 1;i < numsSize+1;i++) {
        if(result[i] == 0) {
            solution[c] = i;
            c++;
        }
    }
    *returnSize = c;
    free(result);
    return solution;
}

int jumpingOnClouds(const int c_count,const int* c) {
    if(c_count == 2) {
        return 1;
    }

    int mov = 0;
    for(int i = 0;i < c_count;i++) {
        if((i+1) < c_count && c[i+1] == 1) {
            mov++;
            i++;
        }else if(((i+1) < c_count || (i+2) < c_count ) && c[i+1] == 0 && c[i+2] == 1) {
            mov++;
        }else if(((i+1) < c_count || (i+2) < c_count ) && c[i+1] == 0 && c[i+2] == 0) {
            mov++;
            i+=1;
        }else {
            mov++;
        }
    }
    return mov - 1;
}


// Fonction pour effectuer la recherche binaire
//avec la fonction findsmallOccurrence
int binarySearch(int arr[],const int size,const int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fonction pour trouver la plus petite valeur commune
int findSmallestCommon(int arr1[], int size1, int arr2[], int size2) {
    // Trier les deux tableaux
    qsort(arr1, size1, sizeof(int), compare);
    qsort(arr2, size2, sizeof(int), compare);

    int smallestCommon = -1;

    // Utiliser la recherche binaire pour trouver la plus petite valeur commune
    for (int i = 0; i < size1; i++) {
        if (binarySearch(arr2, size2, arr1[i]) != -1) {
            smallestCommon = arr1[i];
            break;
        }
    }

    return smallestCommon;
}

bool thereAreNumberInArray(const int* arr,const int size,const int value) {
    for(int i = 0;i < size;i++) {
        if(value == arr[i]) {
            return true;
        }
    }
    return false;
}

/*Cette version ne repond pas aux criteres lorsqu'il s'agit de grande donnees d'information
 * pour il faut prend la fonction precedent qui realise cela avec un peu moins de temps
 * findSmallestCommon avec une recherche binaire
 */
int getCommon(int* nums1,const int nums1Size,int* nums2,const int nums2Size) {
    qsort(nums1,nums1Size,sizeof(int),compare);
    qsort(nums2,nums2Size,sizeof(int),compare);

    for(int i = 0;i < nums1Size;i++) {
        if(thereAreNumberInArray(nums2,nums2Size,nums1[i])) {
            return nums1[i];
        }
    }
    return 0;
}

int getCommonSpeed(const int* nums1,const int nums1Size,const int* nums2,const int nums2Size) {
    int i=0,j=0;
    while((i<nums1Size)&&(j<nums2Size))
    {
        if(nums1[i]<nums2[j])
            i++;
        else if(nums1[i]>nums2[j])
            j++;
        else
            return nums1[i];
    }
    return -1;
}

int countKDifference(const int* nums,const int numsSize,const int k) {
    int count = 0;
    for(int i = 0;i < numsSize;i++) {
        for(int j = i + 1;j < numsSize;j++) {
            if(abs(nums[i] - nums[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

/*
 * le code suivant est plus optimiser que le mien et occupe que 0ms a la place de
 * mon code qui occupe 3ms et bat 66,67% des utilisateurs
 * et en memoire bat 90,63% des utilisateurs
 */
int countKDifference(int* nums,const int numsSize,const int k) {
    int freq[101] = {0};
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
        if (nums[i] - k >= 1) {
            res += freq[nums[i] - k];
        }
        if (nums[i] + k <= 100) {
            res += freq[nums[i] + k];
        }
    }
    return res;
}
