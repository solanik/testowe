//
// Created by filwo on 03.10.2018.
//

#pragma once

#include "SortingFactory.h"

class HeapSort : public RegisteredInFactory<HeapSort>
{
public:
    static std::string getAlgorithmName();
    static void sort(std::vector<unsigned>& values);
private:
    HeapSort()
    {
        (void)RegisteredInFactory<HeapSort>::registered;
    }
    static void heapify(std::vector<unsigned>::iterator begin, std::vector<unsigned>::iterator end, unsigned index);
};
