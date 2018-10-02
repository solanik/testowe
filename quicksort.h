//
// Created by filwo on 02.10.2018.
//

#pragma once

#include "SortingFactory.h"

class QuickSort : public RegisteredInFactory<QuickSort>
{
public:
    static std::string getAlgorithmName();
    static void sort(std::vector<unsigned>& values);
private:
    QuickSort()
    {
        (void)RegisteredInFactory<QuickSort>::registered;
    }
    static void sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh);
};
