#ifndef PATTERN_MATCH_H
#define PATTERN_MATCH_H

#include <iostream>
#include <algorithm>

/*Custom Pattern matching algorithum

The function allow pattern matching within the various container like array,vector,list,map.
It take a pattern, a custom comparison function, and one or more container.

*/

namespace std _GLIBCXX_VISIBILITY(default)
{

    template <typename... Container, typename Pattern, typename Compare>
    bool custom_pattern_match(const Pattern &pattern, Compare comp, Container &...containers)
    {
        for (const auto &container : {containers...})
        {
            for (auto it = container.begin(); it != container.end(); ++it)
            {
                if (comp(it, pattern.begin(), pattern.end()))
                {
                    return true;
                }
            }
        }
        return false;
    }
}

#endif // PATTERN_MATCH_H
