#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
void InsertionSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    //Sequence<T>* sortedSequence = (Sequence<T>*)new ArraySequence<T>(s->GetLength());
    //for (int i = 0; i < s->GetLength(); i++)
    //{
    //    sortedSequence->Set(i, s->Get(i));
    //}
    T buff;
    int prevIndex;
    for (int j = 0; j < s->GetLength(); j++)
    {
        buff = s->Get(j);
        prevIndex = j - 1;
        while (prevIndex >= 0 && !(cmp(s->Get(prevIndex), buff)))
        {
            s->Set((prevIndex + 1), s->Get(prevIndex));
            s->Set(prevIndex, buff);
            prevIndex--;
        }
    }
}


#endif // INSERTIONSORT_H_INCLUDED
