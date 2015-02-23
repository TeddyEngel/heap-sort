//
//  main.cpp
//  HeapSort
//
//  Created by Teddy Engel on 23/02/2015.
//  Copyright (c) 2015 Teddy Engel. All rights reserved.
//

#include <iostream>

void PrintVector(std::vector<int>& values)
{
    int i;
    
    for(i = 0; i != values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    std::vector<int> values = {10, 0, 2, 5, -4, 3, 2};
    std::vector<int> result;
    
    std::cout << "Unsorted collection:" << std::endl;
    PrintVector(values);
    MergeSort(values, result);
    std::cout << "Sorted collection:" << std::endl;
    PrintVector(result);
    return 0;
}
