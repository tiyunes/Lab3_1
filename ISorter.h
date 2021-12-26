#ifndef ISORTER_H_INCLUDED
#define ISORTER_H_INCLUDED
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSortLeft.h"
#include "QuickSortRight.h"
#include "QuickSortMiddle.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "SelectionSort.h"


template<typename T>
class ISorter
{
public:
    virtual void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) = 0;
    virtual ~ISorter<T>() = default;
};

template<typename T>
class BubbleSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        BubbleSort(s, cmp);
    }
};

template<typename T>
class InsertionSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
       InsertionSort(s, cmp);
    }
};

template<typename T>
class MergeSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        MergeSort(s, cmp);
    }
};

template<typename T>
class QuickSorterRight: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        QuickSortRight(s, cmp, 0, (s->GetLength() - 1));
    }
};

template<typename T>
class QuickSorterLeft: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        QuickSortLeft(s, cmp, 0, (s->GetLength() - 1));
    }
};

template<typename T>
class QuickSorterMiddle: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        QuickSortMiddle(s, cmp, 0, (s->GetLength() - 1));
    }
};


template<typename T>
class HeapSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        HeapSort(s, cmp);
    }
};

template<typename T>
class ShellSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        ShellSort(s, s->GetLength(), cmp);
    }
};

template<typename T>
class SelectionSorter: public ISorter<T>
{
public:
    void Sorter(Sequence<T>* s, function<bool(T, T)> cmp) override
    {
        SelectionSort(s, cmp);
    }
};




#endif // ISORTER_H_INCLUDED
