#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED
#include "SEQUENCE.H"
#include "ArraySequence.h"
#include <functional>

template<typename T>
void BubbleSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    //Sequence<T>* sortedSequence = (Sequence<T>*)new ArraySequence<T>(s->GetLength());
    //for (int i = 0; i < s->GetLength(); i++)
    //{
    //    sortedSequence->Set(i, s->Get(i));
    //}
    T buff;
    for(int i = 0; i < (s->GetLength() - 1); i++)
    {
        for(int j = (s->GetLength() - 1); j > i; j--)
        {
            if(!(cmp(s->Get(j - 1), s->Get(j))))
            {
                buff = s->Get(j - 1);
                s->Set((j - 1), s->Get(j));
                s->Set(j, buff);
            }
        }
    }
}


#endif // BUBBLESORT_H_INCLUDED
