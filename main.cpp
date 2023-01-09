#include <iostream>
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include <chrono>
#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
#include "insertion.h"
#include "hybrid.h"


constexpr int step = 100; //100
constexpr int maxlen = 10000;  //500 /*10000;*/
constexpr int times = 100;
/* constexpr int step = 10; */
/* constexpr int maxlen = 100; */
/* constexpr int times = 10; */

using std::chrono::nanoseconds;



int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::ofstream file("output10000hybridfinal.txt");

    for (int len = step ; len <= maxlen ; len += step) {
        nanoseconds he(0);
        nanoseconds merge(0);
        nanoseconds quick(0);
        nanoseconds insert(0);
        nanoseconds hybrid(0);
        std::vector<int>original(len);
        for (int i = 0 ; i < len ; i++) {
            original[i] = i;
        }

        std::vector<int>arr;
        std::vector<int>sorted;

        for (int t = 0 ; t < times ; t++) {
            std::shuffle(original.begin(), original.end(), gen);//randomly sorted array
            {
            arr = original;
            auto begin = std::chrono::steady_clock::now();
            heapSort(arr);
            auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
            he += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                quickSort(arr,0,arr.size()-1); //its either size or size-1 depends
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                quick += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                mergesort(arr);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                merge += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                insert_sort(arr);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                insert += total;
            }
            {
                arr = original;
                auto begin = std::chrono::steady_clock::now();
                hybridSort(arr,0,arr.size()-1);
                auto end = std::chrono::steady_clock::now();
                nanoseconds total(end - begin);
                hybrid += total;
            }

        }

        file << len << " "<< he.count() / times << " "<< merge.count() / times << " "<< insert.count() / times << " "<< quick.count() / times << " " << hybrid.count() / times << std::endl;

    }

    file.close();
    return 0;
}