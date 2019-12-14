//
// Created by aknight on 12/7/19.
//

#ifndef EX05_HASHTABLE_ALGORITHM_H
#define EX05_HASHTABLE_ALGORITHM_H

//#include <algorithm>
#include "../include/algorithm.h"
#include <iostream>
using namespace std;

namespace edu { namespace vcccd { namespace vc { namespace csv15 {
template <typename UnidirectionalIterator, typename Type>
UnidirectionalIterator partition(UnidirectionalIterator first, UnidirectionalIterator last, const Type &pivot) {
    // Put your partitioning code here
    if (first == last) {
        return first;
    }

    for (UnidirectionalIterator i = next(first); i != last; ++i) {
        if (*i <= pivot) {
            iter_swap(i, first);
            ++first;
        }
    }
    return first;
}
}}}}
#endif //EX05_HASHTABLE_ALGORITHM_H
