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

int main(void) {
    testIntersection2();
    return 0;
}
