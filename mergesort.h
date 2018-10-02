//
// Created by filwo on 02.10.2018.
//

#pragma once

#include "SortingFactory.h"

class MergeSort : public RegisteredInFactory<MergeSort>
{
public:
    static std::string getAlgorithmName();
    static void sort(std::vector<unsigned>& values);
private:
    MergeSort()
    {
        (void)RegisteredInFactory<MergeSort>::registered;
    }
    static void sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh);
};
