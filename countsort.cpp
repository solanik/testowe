//
// Created by filwo on 03.10.2018.
//

#include <algorithm>
#include "countsort.h"

std::string CountSort::getAlgorithmName()
{
    return "count";
}

void CountSort::sort(std::vector<unsigned>& values)
{
    if (values.size() <= 1)
        return;
    auto max = *std::max_element(values.begin(), values.end());
    std::vector<unsigned> elementsCount(max+1, 0);
    for (auto value : values)
        ++elementsCount[value];
    for (unsigned index=1; index<elementsCount.size(); ++index)
        elementsCount[index] += elementsCount[index-1];
    auto valuesCopy = values;
    for (auto value : valuesCopy)
    {
        values[elementsCount[value]-1] = value;
        --elementsCount[value];
    }
}
