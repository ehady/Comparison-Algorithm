//
// Created by lenovo on 8.12.2022.
//

#ifndef DATABASES_PROJECT_HEAPSORT_H
#define DATABASES_PROJECT_HEAPSORT_H

#include <iostream>
#include <vector>
#include <algorithm>

void fixHeap(std::vector<int> &heap,int parent,int how_many){ //3 parameters, parent is parent index i think
    //starting from the end of the vector, we'll call fixheap function recursively
    //we'll check if left and right child is a heap
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if(left < how_many && heap[left] > heap[largest]) {
        largest = left;
    }
    if(right < how_many && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != parent) { //might have to add & to arrays here
        std::swap(heap[parent],heap[largest]); //bc largest should be the index of parent, we swap because it means the largest is not at parent
        fixHeap(heap,largest,how_many);//bc if parents index isn't largest it needs we need to fix more, and we move on to the next heap
    }

}

void makeHeap(std::vector<int>&heap){
    for(int i = heap.size()/2-1; i>=0; --i){
        fixHeap(heap,i,heap.size()); //because we will have i+1 times parents in the heap, for example if size is 6 we'll have 3 parents
        //so i will be the indexes of the parents in the heap.
    }
}


void heapSort(std::vector<int>&heap){
    int heapSize = heap.size();
    makeHeap(heap);

    for(int i = heap.size()-1; i>=0; --i){ //we start from the end and keep decreasing i until we reach the beginning of the vector
        std::swap(heap[0],heap[i]); //we swap the first element and the last element, and i starts from the last element so this should work
        heapSize--; //decrese the size, maybe we don't need this and we can just use i ?
        fixHeap(heap,0,heapSize); //call fixheap on the decreased size vector
    }
}






#endif //DATABASES_PROJECT_HEAPSORT_H
