#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
Sequence<T>* BubbleSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    Sequence<T>* sortedSequence = (Sequence<T>*)new ArraySequence<T>(s->GetLength());
    for (int i = 0; i < s->GetLength(); i++)
    {
        sortedSequence->Set(i, s->Get(i));
    }
    T buff;
    for(int i = 0; i < (sortedSequence->GetLength() - 1); i++)
    {
        for(int j = 0; j < (sortedSequence->GetLength() - i - 1); j++)
        {
            if(!(cmp(sortedSequence->Get(j), sortedSequence->Get(j+1))))
            {
                buff = sortedSequence->Get(j);
                sortedSequence->Set(j, sortedSequence->Get(j+1));
                sortedSequence->Set(j + 1, buff);
            }
        }
    }
    return sortedSequence;
}


#endif // BUBBLESORT_H_INCLUDED
