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

void CountSort::sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh)
{
    if (indexHigh <= indexLow)
        return;
    unsigned indexMiddle = (indexHigh + indexLow) / 2;
    sortImpl(values, indexLow, indexMiddle);
    sortImpl(values, indexMiddle+1, indexHigh);
    for (auto firstScopeIndex=indexLow, secondScopeIndex=indexMiddle+1;
         firstScopeIndex<=indexMiddle && secondScopeIndex<=indexHigh;
         ++firstScopeIndex)
    {
        auto secondScopeValue = values[secondScopeIndex];
        if (values[firstScopeIndex] > secondScopeValue)
        {
            std::rotate(values.rbegin() + values.size() - secondScopeIndex - 1,
                        values.rbegin() + values.size() - secondScopeIndex,
                        values.rbegin() + values.size() - firstScopeIndex);
            ++secondScopeIndex;
            ++indexMiddle;
        }
    }
}
