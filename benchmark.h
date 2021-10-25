#ifndef BENCHMARK_H_INCLUDED
#define BENCHMARK_H_INCLUDED
#include <chrono>
#include <fstream>
#include <iostream>
#include <functional>
#include <utility>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSortF.h"
#include "QuickSortM.h"

const int n = 9;
int size[n] = {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000};

using namespace std;

bool comp(int a, int b)
{
    if(a < b)
    {
        return 1;
    }
    else return 0;
}

function<bool(int, int)>compInteger = comp;

void RandomBenchmark()
{
    srand(time(NULL));
    vector<Sequence<int>*> sRand;
    vector<Sequence<pair<int, int>>*> sRand2;
    //Sequence<pair<int, int>>* sRand2 = (Sequence<pair<int, int>>*) new ArraySequence<pair<int, int>>();
    pair<int, int> p;
    int r;
    for (int i = 0; i < n; i++)
    {
        sRand.push_back((Sequence<int>*)new ArraySequence<int>(size[i]));
        sRand2.push_back((Sequence<pair<int, int>>*)new ArraySequence<int>(size[i]));
        for (int j = 0; j < size[i]; j++)
        {
            r = rand() % size[i];
            sRand[i]->Append(r);
            p.first = r; p.second = r;
            sRand2[i]->Append(p);
        }
    }
    ofstream fout("time.csv");
    for (int i = 0; i < n; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s6 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s7 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        ISorter<int>* isort1 = new BubbleSorter<int>();
        auto start1 = chrono::steady_clock::now();
        s1 = isort1->Sorter(sRand[i], compInteger);
        auto end1 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration1 = end1 - start1;
        double time1 = duration1.count();

        ISorter<int>* isort2 = new InsertionSorter<int>();
        auto start2 = chrono::steady_clock::now();
        s2 = isort2->Sorter(sRand[i], compInteger);
        auto end2 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration2 = end2 - start2;
        double time2 = duration2.count();

        ISorter<int>* isort3 = new MergeSorter<int>();
        auto start3 = chrono::steady_clock::now();
        s3 = isort3->Sorter(sRand[i], compInteger);
        auto end3 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration3 = end3 - start3;
        double time3 = duration3.count();

        ISorter<int>* isort4 = new QuickSorter<int>();
        auto start4 = chrono::steady_clock::now();
        s4 = isort4->Sorter(sRand[i], compInteger);
        auto end4 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration4 = end4 - start4;
        double time4 = duration4.count();

        ISorter<int>* isort5 = new QuickSorterF<int>();
        auto start5 = chrono::steady_clock::now();
        s5 = isort5->Sorter(sRand[i], compInteger);
        auto end5 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration5 = end5 - start5;
        double time5 = duration5.count();

        ISorter<int>* isort6 = new QuickSorterM<int>();
        auto start6 = chrono::steady_clock::now();
        s6 = isort6->Sorter(sRand[i], compInteger);
        auto end6 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration6 = end6 - start6;
        double time6 = duration6.count();

        auto start7 = chrono::steady_clock::now();
        s7 = CountingSort(sRand2[i], size[i]);
        auto end7 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration7 = end7 - start7;
        double time7 = duration7.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << ";" << time6 << ";" << time7 << endl;
    }
    //fin.close();
}

void SortedBenchmark()
{
    vector<Sequence<int>*> v1;
    vector<Sequence<pair<int, int>>*> v2;
    pair<int, int> p;
    int r;
    for (int i = 0; i < n; i++)
    {
        v1.push_back((Sequence<int>*)new ArraySequence<int>(size[i]));
        v2.push_back((Sequence<pair<int, int>>*)new ArraySequence<int>(size[i]));
        for (int j = 0; j < size[i]; j++)
        {
            v1[i]->Append(j);
            p.first = j; p.second = j;
            v2[i]->Append(p);
        }
    }
    ofstream fout("timeSorted.csv");
    for (int i = 0; i < n; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s6 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s7 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        ISorter<int>* isort1 = new BubbleSorter<int>();
        auto start1 = chrono::steady_clock::now();
        s1 = isort1->Sorter(v1[i], compInteger);
        auto end1 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration1 = end1 - start1;
        double time1 = duration1.count();

        ISorter<int>* isort2 = new InsertionSorter<int>();
        auto start2 = chrono::steady_clock::now();
        s2 = isort2->Sorter(v1[i], compInteger);
        auto end2 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration2 = end2 - start2;
        double time2 = duration2.count();

        ISorter<int>* isort3 = new MergeSorter<int>();
        auto start3 = chrono::steady_clock::now();
        s3 = isort3->Sorter(v1[i], compInteger);
        auto end3 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration3 = end3 - start3;
        double time3 = duration3.count();

        ISorter<int>* isort4 = new QuickSorter<int>();
        auto start4 = chrono::steady_clock::now();
        s4 = isort4->Sorter(v1[i], compInteger);
        auto end4 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration4 = end4 - start4;
        double time4 = duration4.count();

        ISorter<int>* isort5 = new QuickSorterF<int>();
        auto start5 = chrono::steady_clock::now();
        s5 = isort5->Sorter(v1[i], compInteger);
        auto end5 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration5 = end5 - start5;
        double time5 = duration5.count();

        ISorter<int>* isort6 = new QuickSorterM<int>();
        auto start6 = chrono::steady_clock::now();
        s6 = isort6->Sorter(v1[i], compInteger);
        auto end6 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration6 = end6 - start6;
        double time6 = duration6.count();

        auto start7 = chrono::steady_clock::now();
        s7 = CountingSort(v2[i], size[i]);
        auto end7 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration7 = end7 - start7;
        double time7 = duration7.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << ";" << time6 << ";" << time7 << endl;
    }
    //fin.close();
}

void ReverseBenchmark()
{
    vector<Sequence<int>*> v1;
    vector<Sequence<pair<int, int>>*> v2;
    pair<int, int> p;
    int r;
    for (int i = 0; i < n; i++)
    {
        v1.push_back((Sequence<int>*)new ArraySequence<int>(size[i]));
        v2.push_back((Sequence<pair<int, int>>*)new ArraySequence<int>(size[i]));
        for (int j = 0; j < size[i]; j++)
        {
            v1[i]->Append(size[i] - j);
            p.first = size[i] - j; p.second = size[i] - j;
            v2[i]->Append(p);
        }
    }
    ofstream fout("timeReverse.csv");
    for (int i = 0; i < n; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s6 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s7 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        ISorter<int>* isort1 = new BubbleSorter<int>();
        auto start1 = chrono::steady_clock::now();
        s1 = isort1->Sorter(v1[i], compInteger);
        auto end1 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration1 = end1 - start1;
        double time1 = duration1.count();

        ISorter<int>* isort2 = new InsertionSorter<int>();
        auto start2 = chrono::steady_clock::now();
        s2 = isort2->Sorter(v1[i], compInteger);
        auto end2 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration2 = end2 - start2;
        double time2 = duration2.count();

        ISorter<int>* isort3 = new MergeSorter<int>();
        auto start3 = chrono::steady_clock::now();
        s3 = isort3->Sorter(v1[i], compInteger);
        auto end3 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration3 = end3 - start3;
        double time3 = duration3.count();

        ISorter<int>* isort4 = new QuickSorter<int>();
        auto start4 = chrono::steady_clock::now();
        s4 = isort4->Sorter(v1[i], compInteger);
        auto end4 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration4 = end4 - start4;
        double time4 = duration4.count();

        ISorter<int>* isort5 = new QuickSorterF<int>();
        auto start5 = chrono::steady_clock::now();
        s5 = isort5->Sorter(v1[i], compInteger);
        auto end5 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration5 = end5 - start5;
        double time5 = duration5.count();

        ISorter<int>* isort6 = new QuickSorterM<int>();
        auto start6 = chrono::steady_clock::now();
        s6 = isort6->Sorter(v1[i], compInteger);
        auto end6 = chrono::steady_clock::now();
        chrono::duration<double, micro> duration6 = end6 - start6;
        double time6 = duration6.count();

        auto start7 = chrono::steady_clock::now();
        s7 = CountingSort(v2[i], size[i]);
        auto end7 = chrono::steady_clock::now();
        chrono::duration<double, milli> duration7 = end7 - start7;
        double time7 = duration7.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << ";" << time6 << ";" << time7 << endl;
    }
}

#endif // BENCHMARK_H_INCLUDED
