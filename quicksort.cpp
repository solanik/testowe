#include <limits>
#include "quicksort.h"

std::string QuickSort::getAlgorithmName()
{
    return "quick";
}

void QuickSort::sort(std::vector<unsigned>& values)
{
    if (values.size() <= 1)
        return;
    sortImpl(values, 0, values.size() - 1);
}

void QuickSort::sortImpl(std::vector<unsigned>& values, unsigned indexLow, unsigned indexHigh)
{
    if (indexHigh <= indexLow || indexHigh == std::numeric_limits<unsigned>::max())
        return;
    auto indexMiddle = indexLow;
    auto pivot = values[indexHigh];
    for (unsigned progressIndex=indexLow; progressIndex<indexHigh; ++progressIndex)
    {
        if (values[progressIndex] < pivot)
        {
            std::iter_swap(values.begin()+indexMiddle, values.begin()+progressIndex);
            ++indexMiddle;
        }
    }
    std::iter_swap(values.begin()+indexMiddle, values.begin()+indexHigh);
    sortImpl(values, indexLow, indexMiddle-1);
    sortImpl(values, indexMiddle+1, indexHigh);
}