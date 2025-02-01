#include <stdio.h>
#include <stdlib.h>
#include "arrayFunctions.h"

void testMajorityElement() {
    int tab[] = {2,2,1,1,1,2,2};
    
    const int majority = majorityElement(tab,7);

    printf("la valeur la plus repetee est %d \n",majority);
}

void testGetMax() {
    char* operations[] = {"1 83","3","2","1 76"};
    int result_count = 0;
    int* result = getMax(4,operations,&result_count);

    for(int i = 0;i < result_count;i++) {
        printf("%d ",result[i]);
    }
    printf("\n");

    free(result);
}

void testMissingNumber() {
    int nums[] = {3,0,1};
    const int result = missingNumber(nums,3);

    printf("%d le nombre manquant\n",result);
}

void testIntersection2() {
    int t1[] = {4,7,9,7,6,7},t1_size = 6;
    int t2[] = {5,0,0,5,1,6,2,2,4},t2_size = 9;
    int resultSize = 0;
    int* result = intersect(t1,t1_size,t2,t2_size,&resultSize);

    for(int i = 0;i < resultSize;i++) {
        printf("%d -> ",result[i]);
    }

    free(result);
}

void testIsperfetSquart() {
    printf("entrez une valeur nous allons verifier si elle est un perfect square\n");
    printf("x =  ");
    int x = 0;
    scanf("%d",&x);

    if(isPerfectSquare(x)) {
        printf("%d is the perfect square\n",x);
    }else {
        printf("is not a perfect square\n");
    }
}

void testQuickSort() {
    int arr[] = {23,12,34,56,43,23,12,34,67,786,75,455,6545,54};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);

    quickSort(arr,0,size - 1);
    printArray(arr,size);
}

void testQuickSort1() {
    int arr[] = {4,5,3,7,2};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    int ok = 0;
    int *ar = quickSort1(size,arr,&ok);
    printArray(ar,ok);
}

void testShellSort() {
    int scores[] = {9,6,5,8,0,7,4,3,1,2};
    int length = sizeof(scores)/sizeof(scores[0]);
    shellShort(scores,length);
    for(int i = 0;i < length;i++){
        printf("%d ",*(scores + i));
    }
}

void testThirdMax() {
    int arr[] = {1,1,2};
    size_t len = sizeof(arr)/sizeof(arr[0]);
    const int third = thirdMax(arr,len);

    printf("The third max value %d \n",third);
}

void testCutTheSticks() {
    int sticks[] = {5,4,4,2,2,8};
    int size = sizeof(sticks)/sizeof(sticks[0]),returnSize = 0;
    int* result = cutTheSticks(size,sticks,&returnSize);

    printArray(result,returnSize);
}

void testCountingort() {
    int arr[] = {19,10,12,10,24,25,22};
    const size_t size = sizeof(arr)/sizeof(arr[0]);

    int ok = 0;

    int* array = countingSort(size,arr,&ok);

    printArray(array,ok);
    printArray(arr,size);

    free(array);
}

void testBitcounter() {
    const long n = 1620434450;
    printf("nombre de bit de %ld = %ld\n",n,countBits(n));
}

void testCounterGame() {
    printf("Entrez le nombre de depart du jeu :  ");
    printf("\n");
    long initial = 0;
    scanf("%ld",&initial);

    char* winner = counterGame(initial);
    printf("le vainquer est : %s \n",winner);

    //free(winner);
}

void testMaximumCount() {
    const int tab[] = {-3,-2,-1,0,0,1,2};
    const size_t t = sizeof(tab)/sizeof(tab[0]);
    printf("le max est : %d \n",maximunCount(tab,t));
}

void testFindDissapearNUnmber() {
    int arr[] = {4,4,4,5,2,3,4,7,8,11,1};
    size_t t = sizeof(arr)/sizeof(arr[0]);
    int taille = 0;
    int *s = findDisappearedNumbers(arr,t,&taille);

    for(int i = 0;i < taille;i++) {
        printf("(%d)->",s[i]);
    }
}

void testJumpingOnClouds() {
    const int arr[] = {0,0};
    const size_t l = sizeof(arr)/sizeof(arr[0]);

    printf("the minimun jump is : %d \n",jumpingOnClouds(l,arr));
}

int main(void) {

    testJumpingOnClouds();
    /*unsigned int result = difference_of_squares(5);

    printf("difference = %u\n",result);
    printf("square of sum = %u\n",square_of_sum(5));
    printf("sum of square = %u\n",sum_of_squares(5));*/

    return 0;
}
