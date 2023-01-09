//
// Created by lenovo on 8.12.2022.
//

#ifndef DATABASES_PROJECT_MERGESORT_H
#define DATABASES_PROJECT_MERGESORT_H
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

std::vector<int> mergesort(std::vector<int> &array);
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);



std::vector<int> mergesort(std::vector<int> &array) {
    if (array.size() == 0 or array.size() == 1) {
        return array;
    }
    //divide in two vectors
    std::vector<int> left;
    std::vector<int> right;
    left.reserve(array.size()/2);
    right.reserve(array.size()/2);

    for (int i = 0; i < array.size(); ++i) {
        if (i < array.size() / 2) {
            left.push_back(array[i]);
        } else {
            right.push_back(array[i]);
        }
    }
    std::vector<int> merge1 = mergesort(left);
    std::vector<int> merge2 = mergesort(right);
    std::vector<int> mergedArray = merge(merge1, merge2);
    return mergedArray;

}

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right) {
    //check the first elements, see which one is smaller
    int refIndexL = 0;
    int refIndexR = 0;
    std::vector<int> output; //output should be the size of the two vectors combined
    output.reserve(left.size() + right.size());
    while (refIndexL < left.size() and refIndexR < right.size()) { //while left and right is not empty

        if (left[refIndexL] <= right[refIndexR]) { //if left size is smaller than right size
            output.push_back(left[refIndexL]); //push back
            refIndexL++;

            // left.erase(left.begin()); //we erase it, we can keep checking the first element
        } else {
            output.push_back(right[refIndexR]);
            //right.erase(refIndexR); //erase doesn't work we have to change it reference point index and move the index until it reaches the size of the array
            refIndexR++;
        }
    }
    for(int i=refIndexL; i < left.size(); ++i) {
        output.push_back(left[i]);
    }

    for(int i=refIndexR; i<right.size(); ++i) {
        output.push_back(right[i]);
    }

    return output;

}



#endif //DATABASES_PROJECT_MERGESORT_H

