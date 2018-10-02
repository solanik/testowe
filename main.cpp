//
// Created by filwo on 02.10.2018.
//

#include "mergesort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

std::vector<unsigned> getValues(const std::string& line)
{
    std::vector<unsigned> values;
    std::istringstream stringStream(line);
    unsigned value;
    while (stringStream >> value)
        values.push_back(value);
    return values;
}

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned>& values)
{
    std::string prefix;
    for (auto value : values)
    {
        std::cout << prefix << value;
        prefix = " ";
    }
    return os;
}

int main() {
    std::string algorithmName;
    std::cout << "Which sort you want to test" << std::endl;
    std::getline(std::cin, algorithmName);

    auto sort = SortingFactory::getSortingAlgorithm(algorithmName);

    std::string testDataFile{"../test.data"};
    std::ifstream file(testDataFile);
    if (file.bad())
    {
        std::cout << testDataFile << " not found";
        return -1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        auto testValues = getValues(line);
        std::cout << std::setw(13) << "Not sorted: " << testValues << std::endl;
        sort(testValues);
        std::cout << std::setw(13) << "Sorted: " << testValues << std::endl << std::endl;
    }

    return 0;
}