#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
void ShellSort(Sequence<T>* s, int n, function<bool(T, T)> cmp)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            T temp = s->Get(i);
            int j;
            for (j = i; j >= gap && cmp(temp, s->Get(j - gap)); j -= gap)
            {
                s->Set(j, s->Get(j - gap));
            }
            s->Set(j, temp);
        }
    }
}

#endif // SHELLSORT_H_INCLUDED
