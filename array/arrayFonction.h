//
// Created by claude delcroix on 05/10/2024.
//

#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H
#include <stdbool.h>

int* replaceValueAtIndex(int* array,int index,int value);
bool isValueArray(const int* array,int arrSize,int value);
int returnIndexOf(const int* array,int arrSize,int value);
int* deleteLast(int* array,int arrSize,int* returnSize);
int* deleteFirste(int* array,int arrSize,int* returnSize);
int* deleteAtIndex(int* array,int arrSize,int index,int* returnSize);
int* insertionBeforeTheGivenIndex(int* array,int arrSize,int item,int index,int* returnSize);
int* insertionAfterTheIndex(int* array,int arrSize,int item,int index,int* returnSize);
int* insertAtTheIndex(int* array,int arrSize,int item,int index,int* returnSize);
int* insertInIncreasing(int* arr,int arrSize,int item,int* returnSize);
char** summaryRanges(const int* nums,int numsSize,int* returnSize) ;
void moveZeroes(int* nums,int numsSize);
int maximumStrongPairXor(const int* nums,const int numsSize);
int maxValue(const int x,const int y);
int minValue(const int x,const int y);
void tri_a_bulle(int* t,const int n);
int* intersection(int* nums1, int nums1Size,int* nums2,int nums2Size,int* returnSize);
int* getMax(const int operation_count,char** operations,int* result_count);
int majorityElement(int* nums,const int numsSize);
void bubbleSort(int* arr,int n);
void swap(int* xp,int* yp);
void insertionSort(int arr[],int n);

#define TABLE_SIZE 1000


typedef struct node node;
struct node {
    int index;
    int value;
    int nbrFois;
    node* next;
};

typedef struct hashTable hashTable;
struct hashTable {
    node* table[TABLE_SIZE];
};

hashTable* createTable();
void insert(hashTable* table,const int index,const int value,int* ok,const int k);
int hash(const int key);
void deleteHashTable(hashTable* table);

int missingNumber(int* nums,const int numsSize);
int missingNumber1(const int* nums,const  int numsSize);
void insertIntersect(hashTable* table,const int value);
void printTable(const hashTable* table);
void insertWithHash(const hashTable* table, const int value, int* array, int* sizeArr);
hashTable* createTableOptimisation();
int* intersect(const int* nums1, int nums1Size,const int* nums2, int nums2Size, int* returnSize);
int* intersectQsort(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int compare(const void* a, const void* b);
int mySqrt(const int x);
bool isPerfectSquare(const int num);
int partition(int arr[],int low,int high);
void quickSort(int arr[],int low,int high);
void printArray(const int arr[],const size_t size);
int* quickSort1(const int arr_count,const int* arr,int* result_count);
void swapShell(int array[],const int a,const int b);
void shellShort(int array[],const int length);
int thirdMax(int* nums,int numsSize);
int* cutTheSticks(int arr_count,int* arr,int* result_count);
int* cutTheSticksOptimisationVersion(int arr_count, int* arr, int* result_count);
bool compareArray(const int* arr1,const int* arr2,const int size1,const int size2);
int* countingSort1(int arr_count,const int* arr,int* result_count);
int* countingSort(int arr_count,const int* arr,int* returnSize);
int* countingSortOptimisation(int arr_count,const int* arr, int* result_count);
unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);
void merge(int array[],int temp[],int left,int right,int rightEndIndex);
void mergeSort(int array[],int temp[],int left,int right);
void sort(int array[],int length);

#endif //ARRAYFUNCTIONS_H
