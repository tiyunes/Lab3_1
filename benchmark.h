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

int size[9] = {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000};

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
    for (int i = 0; i < 9; i++)
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
    //ofstream fout("text.txt");
    for (int i = 0; i < 9; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        auto start1 = chrono::high_resolution_clock::now();
        s1 = BubbleSort(sRand[i], compInteger);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration1 = end1 - start1;
        float time1 = duration1.count();

        auto start2 = chrono::high_resolution_clock::now();
        s2 = InsertionSort(sRand[i], compInteger);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration2 = end2 - start2;
        float time2 = duration2.count();

        auto start3 = chrono::high_resolution_clock::now();
        s3 = MergeSort(sRand[i], compInteger);
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration3 = end3 - start3;
        float time3 = duration3.count();

        auto start4 = chrono::high_resolution_clock::now();
        s4 = QuickSort(sRand[i], compInteger);
        auto end4 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration4 = end4 - start4;
        float time4 = duration4.count();

        auto start5 = chrono::high_resolution_clock::now();
        s5 = CountingSort(sRand2[i], size[i]);
        auto end5 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration5 = end5 - start5;
        float time5 = duration5.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << endl;
    }
    //fin.close();
}

void SortedBenchmark()
{
    vector<Sequence<int>*> v1;
    vector<Sequence<pair<int, int>>*> v2;
    pair<int, int> p;
    int r;
    for (int i = 0; i < 9; i++)
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
    for (int i = 0; i < 9; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        auto start1 = chrono::high_resolution_clock::now();
        s1 = BubbleSort(v1[i], compInteger);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration1 = end1 - start1;
        float time1 = duration1.count();

        auto start2 = chrono::high_resolution_clock::now();
        s2 = InsertionSort(v1[i], compInteger);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration2 = end2 - start2;
        float time2 = duration2.count();

        auto start3 = chrono::high_resolution_clock::now();
        s3 = MergeSort(v1[i], compInteger);
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration3 = end3 - start3;
        float time3 = duration3.count();

        auto start4 = chrono::high_resolution_clock::now();
        s4 = QuickSort(v1[i], compInteger);
        auto end4 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration4 = end4 - start4;
        float time4 = duration4.count();

        auto start5 = chrono::high_resolution_clock::now();
        s5 = CountingSort(v2[i], size[i]);
        auto end5 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration5 = end5 - start5;
        float time5 = duration5.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << endl;
    }
    //fin.close();
}

void ReverseBenchmark()
{
    vector<Sequence<int>*> v1;
    vector<Sequence<pair<int, int>>*> v2;
    pair<int, int> p;
    int r;
    for (int i = 0; i < 9; i++)
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
    for (int i = 0; i < 9; i++)
    {
        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s2 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s3 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s4 = (Sequence<int>*)new ArraySequence<int>(size[i]);
        Sequence<int>* s5 = (Sequence<int>*)new ArraySequence<int>(size[i]);

        auto start1 = chrono::high_resolution_clock::now();
        s1 = BubbleSort(v1[i], compInteger);
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration1 = end1 - start1;
        float time1 = duration1.count();

        auto start2 = chrono::high_resolution_clock::now();
        s2 = InsertionSort(v1[i], compInteger);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration2 = end2 - start2;
        float time2 = duration2.count();

        auto start3 = chrono::high_resolution_clock::now();
        s3 = MergeSort(v1[i], compInteger);
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration3 = end3 - start3;
        float time3 = duration3.count();

        auto start4 = chrono::high_resolution_clock::now();
        s4 = QuickSort(v1[i], compInteger);
        auto end4 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration4 = end4 - start4;
        float time4 = duration4.count();

        auto start5 = chrono::high_resolution_clock::now();
        s5 = CountingSort(v2[i], size[i]);
        auto end5 = chrono::high_resolution_clock::now();
        chrono::duration<float, milli> duration5 = end5 - start5;
        float time5 = duration5.count();

        fout << time1 << ";" << time2 << ";" << time3 << ";" << time4 << ";" << time5 << endl;
    }
}

#endif // BENCHMARK_H_INCLUDED
