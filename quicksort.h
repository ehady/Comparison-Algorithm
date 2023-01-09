//
// Created by lenovo on 8.12.2022.
//

#ifndef DATABASES_PROJECT_QUICKSORT_H
#define DATABASES_PROJECT_QUICKSORT_H

#include <iostream>
#include <vector>


int partition(std::vector<int> &array, int startIndex, int endIndex) { //we need start and end index
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

void quickSort(std::vector<int> &array,int startIndex,int endIndex){
    int pivot;
    if(startIndex<endIndex){
        pivot = partition(array,startIndex,endIndex);
        quickSort(array,startIndex,pivot);
        quickSort(array,pivot+1,endIndex);
    }


}


#endif //DATABASES_PROJECT_QUICKSORT_H
