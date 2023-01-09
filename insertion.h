//
// Created by lenovo on 15.12.2022.
//

#ifndef DATABASES_PROJECT_INSERTION_H
#define DATABASES_PROJECT_INSERTION_H


#include "lib.h"
#include <vector>

void insert_sort(std::vector<int> &array) {
    for (int i = 1 ; i < array.size() ; i++) {
        int val = array[i];
        int current = i;
        while ( (current > 0) && array[current - 1] > val ) {
            array[current] = array[current - 1];
            current--;
        }
        array[current] = val;
    }
}


#endif //DATABASES_PROJECT_INSERTION_H
