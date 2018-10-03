//
// Created by filwo on 02.10.2018.
//

#include "SortingFactory.h"
#include <algorithm>

SortingFactory::SortingAlgorithms& SortingFactory::getAlgorithms()
{
    static std::unordered_map<std::string, SortingFactory::SortingFunction> soringAlgorithms;
    return soringAlgorithms;
}

SortingFactory::SortingFunction SortingFactory::getSortingAlgorithm(std::string name)
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    for (const auto& pair : getAlgorithms())
        if (name.find(pair.first) != std::string::npos)
            return pair.second;
    throw SortingNotFound{name + " could not be found in sorting factory"};
}

bool SortingFactory::addSortingAlgorithm(std::string name, SortingFunction algorithm)
{
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    for (const auto& pair : getAlgorithms())
        if (name.find(pair.first) != std::string::npos)
            throw SortingAlreadyRegistered(name + " already registered in sorting factory");
    getAlgorithms().emplace(std::make_pair(std::move(name), algorithm));
    return true;
}
