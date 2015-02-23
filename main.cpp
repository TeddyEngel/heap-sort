//
//  main.cpp
//  HeapSort
//
//  Created by Teddy Engel on 23/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>

void PrintVector(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i != values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }
}

/*
** Manipulation related
*/
void Swap(std::vector<int>& values, const int& n1, const int& n2)
{
    int nTmp = values[n1];
    values[n1] = values[n2];
    values[n2] = nTmp;
}

/*
** Binary tree related
*/
int Parent(const int& position)
{
    return ((position + 1) / 2) - 1;
}

int Left(const int& position)
{
    return ((position + 1) * 2) - 1;
}

int Right(const int& position)
{
     return ((2 * (position + 1)) + 1) - 1;
}

/*
** Heap related
*/
void Heapify(std::vector<int>& heap, const int& nIndex, const int& nHeapSize)
{
    int nLeft = Left(nIndex);
    int nRight = Right(nIndex);
    int nLargest = -1;

    if (nLeft < nHeapSize && heap[nLeft] > heap[nIndex])
        nLargest = nLeft;
    else
        nLargest = nIndex;
    if (nRight < nHeapSize && heap[nRight] > heap[nLargest])
        nLargest = nRight;
    if (nLargest != nIndex)
    {
        // Swap both
        Swap(heap, nIndex, nLargest);
        // Recursively call heapify
        Heapify(heap, nLargest, nHeapSize);
    }

}

void BuildHeap(std::vector<int>& heap)
{
    int nHeapSize = heap.size();

    for (int i = (nHeapSize / 2) - 1; i > -1; i--)
    {
        Heapify(heap, i, nHeapSize);
    }
}

void HeapSort(std::vector<int>& values)
{
    // Getting the heap size
    int nHeapSize = values.size();

    // We build the heap from the collection of values
    BuildHeap(values);

    // Then we sort the heap
    for (int i = values.size() - 1; i > 0; i--)
    {
        Swap(values, 0, i);
        nHeapSize = nHeapSize - 1;
        Heapify(values, 0, nHeapSize);
    }
}

int main(int argc, const char * argv[]) {
    std::vector<int> values = {10, 0, 2, 5, -4, 3, 2};
    
    std::cout << "Unsorted collection:" << std::endl;
    PrintVector(values);
    HeapSort(values);
    std::cout << "Sorted collection:" << std::endl;
    PrintVector(values);

    values.clear();
    return 0;
}
