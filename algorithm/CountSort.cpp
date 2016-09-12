#include "MyHeader.h"

/**
 * 求最大值
 */
int maxMin(int *array, int size) {
    int max=0;
    for (int curr = 0; curr < size; curr++) {
        if (array[curr] > max) {
            max = array[curr];
        }
    }
    return max;
}

void printArray(int *array, int size) {
    int curr;
    for (curr = 0; curr < size; curr++) {
        printf("%d, ", array[curr]);
    }
    printf("\n");
}

int countSort(int *array, int size) {
    int max = maxMin(array, size);
    int *countArray = new int[max];
    int i=0;
    printArray(countArray,max);
    while (i<=max){
        countArray[i]=0;
        i++;
    }
    int curr;
    for (curr = 0; curr < size; curr++) {
        countArray[array[curr]]++;
    }
    int num = 0;
    curr = 0;
    while (curr < size) {
        while (countArray[num] > 0) {
            array[curr] = num;
            countArray[num]--;
            curr++;
            if (curr > size) { break; }
        }
        num++;
    }
    delete countArray;
    printArray(array, size);
    return 1;
}

int main() {
    int test1[] = {2, 6, 4, 3, 2, 3, 4, 6, 3, 4, 3, 5, 2, 6};
    int size1 = 14;

    countSort(test1, size1);
    return 1;
}

