#pragma once

#include "SortingFactory.h"

class CountSort : public RegisteredInFactory<CountSort>
{
public:
    static std::string getAlgorithmName();
    static void sort(std::vector<unsigned>& values);
private:
    CountSort()
    {
        (void)RegisteredInFactory<CountSort>::registered;
    }
    static void sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh);
};