//
// Created by filwo on 02.10.2018.
//

#pragma once

#include <vector>
#include <functional>
#include <unordered_map>

template <typename T>
class RegisteredInFactory
{
protected:
    RegisteredInFactory()
    {
        (void)registered;
    }
    static const bool registered;
};

class SortingFactory
{
public:
    struct SortingNotFound : std::runtime_error
    {
        SortingNotFound(std::string what)
                : std::runtime_error(std::move(what))
        {}
    };
    struct SortingAlreadyRegistered : std::runtime_error
    {
        SortingAlreadyRegistered(std::string what)
                : std::runtime_error(std::move(what))
        {}
    };

    using SortingFunction = std::function<void (std::vector<unsigned>&)>;

    static SortingFunction getSortingAlgorithm(std::string name);
    static bool addSortingAlgorithm(std::string name, SortingFunction algorithm);
private:
    static std::unordered_map<std::string, SortingFactory::SortingFunction> soringAlgorithms;
};

template <typename T>
const bool RegisteredInFactory<T>::registered =
        SortingFactory::addSortingAlgorithm(T::getAlgorithmName(), T::sort);
