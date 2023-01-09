//
// Created by lenovo on 16.12.2022.
//

#ifndef DATABASES_PROJECT_HYBRID_H
#define DATABASES_PROJECT_HYBRID_H
#include "quicksort.h"
#include "insertion.h"

int div(std::vector<int> &array, int startIndex, int endIndex) { //we need start and end index
    int pivotIndex = (startIndex + endIndex) / 2;
    int pivot = array[pivotIndex];

    while (true) {
        while (array[startIndex] < pivot) {
            startIndex++;
        }
        while (array[endIndex] > pivot) {
            --endIndex;
        }
        if (startIndex >= endIndex) {
            return endIndex;
        }
        std::swap(array[startIndex],array[endIndex]);

    }

}

void hybridSort(std::vector<int> &array,int startIndex,int endIndex){
    int pivot;
        if(endIndex-startIndex < 50) {
            for (int i = startIndex+1 ; i <= endIndex ; i++) {
                int val = array[i];
                int current = i;
                while ( (current > 0) && array[current - 1] > val ) {
                    array[current] = array[current - 1];
                    current--;
                }
                array[current] = val;
            }

            }
         else{
            pivot = div(array,startIndex,endIndex);
            hybridSort(array,startIndex,pivot);
            hybridSort(array,pivot+1,endIndex);
        }

    }




#endif //DATABASES_PROJECT_HYBRID_H
