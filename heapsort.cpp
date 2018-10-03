//
// Created by filwo on 03.10.2018.
//

#include <iostream>
#include "heapsort.h"

std::string HeapSort::getAlgorithmName()
{
    std::cout << "Heap name called" << std::endl;
    return "heap";
}

void HeapSort::sort(std::vector<unsigned>& values)
{
    for (unsigned heapifyPosition=values.size()/2; heapifyPosition>0; --heapifyPosition)
        heapify(values.begin(), values.end(), heapifyPosition-1);
    for (unsigned heapHead=0; heapHead<values.size(); ++heapHead)
        heapify(values.begin()+heapHead, values.end(), 0);
}

void HeapSort::heapify(std::vector<unsigned>::iterator begin, std::vector<unsigned>::iterator end, unsigned index)
{
    auto valuesSize = std::distance(begin, end);
    if (valuesSize <= 1) return;
    auto largestIndex = index;
    auto leftIndex = index*2 + 1;
    auto rightIndex = leftIndex + 1;
    if (leftIndex < valuesSize && *(begin + leftIndex) < *(begin + largestIndex))
        largestIndex = leftIndex;
    if (rightIndex < valuesSize && *(begin + rightIndex) < *(begin + largestIndex))
        largestIndex = rightIndex;
    if (largestIndex == index)
        return;
    std::iter_swap(begin + index, begin + largestIndex);
    heapify(begin, end, largestIndex);
}
