#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include "pattern_match.h"
/*

    **********HOW TO USE THIS ALGORITHM IN DIFFERENT CONTAINER*********
    
*/

int main()
{
    // Here we are finding the pattern in all the vector Container .
    std::vector<int> vector1 = {1, 2, 3, 4, 5};
    std::vector<int> vector2 = {6, 7, 3, 4, 10};
    std::vector<int> vector3 = {6, 3, 8, 4, 10};
    std::vector<int> vector4 = {6, 7, 4, 3, 10};

    std::vector<int> pattern = {3, 4};

    // This lambda compares a range starting from 'itr' with a specified pattern.
   // Returns true if the pattern is found in the range, and false otherwise.
 auto customPatternMatch = [](auto itr, auto patternBegin, auto patternEnd)
    {
        for (auto it = itr; it != patternEnd; ++it)
        {
            if (*it <= 3)
            {
                return false; // If any element is less than or equal to 3, the pattern doesn't match.
            }
        }
        return true; // All elements in the pattern are greater than 3.
    };

    if (std::custom_pattern_match(
            pattern,
            customPatternMatch,
            vector1, vector2, vector3, vector4))
    {
        std::cout << "Pattern found in the vector." << std::endl;
    }
    else
    {
        std::cout << "Pattern not found in vector." << std::endl;
    }

    // --------------------------List-------------------------------------

    // Here we are finding the pattern in first 3 list Container .
    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::list<int> list2 = {1, 2, 8, 9, 5};
    std::list<int> list3 = {1, 2, 3, 4, 5};
    std::list<int> list4 = {1, 2, 9, 4, 5};

    std::list<int> pattern1 = {1, 6, 5};

    if (std::custom_pattern_match(
            pattern,
            [](auto itr, auto patternBegin, auto patternEnd)
            {
                return std::equal(patternBegin, patternEnd, itr);
            },
            list1, list2, list3))
    {
        std::cout << "Pattern found in the list." << std::endl;
    }
    else
    {
        std::cout << "Pattern not found in list." << std::endl;
    }

    // --------------------------Map-------------------------------------

    //Here we are finding the pattern in the 1st and 4th Container .
    std::map<int, std::string> map1 = {{1, "apple"}, {2, "banana"}, {3, "cherry"}};
    std::map<int, std::string> map2 = {{1, "apple"}, {5, "carrort"}, {3, "cherry"}};
    std::map<int, std::string> map3 = {{1, "apple"}, {6, "carrort"}, {3, "cherry"}};
    std::map<int, std::string> map4 = {{1, "apple"}, {2, "banana"}, {3, "cherry"}};

    std::map<int, std::string> pattern2 = {{2, "banana"}, {3, "cherry"}};

    if (custom_pattern_match(
            pattern2,
            [](auto itr, auto patternBegin, auto patternEnd)
            {
                return std::equal(patternBegin, patternEnd, itr);
            },
            map1, map4))
    {
        std::cout << "Pattern found in the map." << std::endl;
    }
    else
    {
        std::cout << "Pattern not found in the map." << std::endl;
    }
}
