//
// Created by jwvan on 2019-04-10.
//

#ifndef ROGUEGAME_MAPUTILS_H
#define ROGUEGAME_MAPUTILS_H

template <typename T>
struct identity { typedef T type; };

template <typename A, typename B>
inline bool contains(const std::map<A, B>& m
        , const typename identity<A>::type& str)
{
    return m.find(str) != m.end();
}

#endif //ROGUEGAME_MAPUTILS_H
