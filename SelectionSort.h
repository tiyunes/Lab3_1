#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

//template<typename T>
//void swap(T* x, T* y)
//{
//    T temp = *x;
//    *x = *y;
//    *y = temp;
//}

template<typename T>
void SelectionSort(Sequence<T>* s, function<bool(T, T)> cmp)
{
    int minIndex;

    for (int i = 0; i < s->GetLength(); i++)
    {
        minIndex = i;
        for (int j = i + 1; j < s->GetLength(); j++)
        {
            if (cmp(s->Get(j), s->Get(minIndex)))
            {
                minIndex = j;
            }
        }
        swap(s->GetP(minIndex), s->GetP(i));
    }
}


#endif // SELECTIONSORT_H_INCLUDED
