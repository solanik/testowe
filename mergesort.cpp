//
// Created by filwo on 02.10.2018.
//

#include "mergesort.h"
#include <algorithm>

std::string MergeSort::getAlgorithmName()
{
    return "merge";
}

void MergeSort::sort(std::vector<unsigned>& values)
{
    if (values.size() <= 1)
        return;
    sortImpl(values, 0, values.size() - 1);
}

void MergeSort::sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh)
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
