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
#include "QuickSortMiddle.h"
#include "QuickSortRight.h"
#include "QuickSortLeft.h"

const int n = 8;
vector<int> sizes = {1000, 2500, 5000, 6000, 7000, 8000, 9000, 10000};


double timeSortMilli(ISorter<int>* i, Sequence<int>* s, function<bool(int, int)> cmp)
{
    auto start1 = chrono::steady_clock::now();
    i->Sorter(s, cmp);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double, milli> duration1 = end1 - start1;

    return duration1.count();
}

double timeSortMicro(ISorter<int>* i, Sequence<int>* s, function<bool(int, int)> cmp)
{
    auto start1 = chrono::steady_clock::now();
    i->Sorter(s, cmp);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double, micro> duration1 = end1 - start1;

    return duration1.count();
}
double timeSortNano(ISorter<int>* i, Sequence<int>* s, function<bool(int, int)> cmp)
{
    auto start1 = chrono::steady_clock::now();
    i->Sorter(s, cmp);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double, nano> duration1 = end1 - start1;

    return duration1.count();
}

double timeSortCounting(Sequence<pair<int, int>>* s, vector<int>* v)
{
    Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(s->GetLength());
    auto start1 = chrono::steady_clock::now();
    sSort1 = CountingSort(s, *max_element(v->begin(), v->end()));
    auto end1 = chrono::steady_clock::now();
    chrono::duration<double, milli> duration1 = end1 - start1;

    return duration1.count();
}

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
    vector<Sequence<pair<int, int>>*> sRandPair;
    vector<vector<int>*> v;

    int r;

    for (int i = 0; i < n; i++)
    {
        sRand.push_back((Sequence<int>*)new ArraySequence<int>(sizes[i]));
        sRandPair.push_back((Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>(sizes[i]));
        v.push_back(new vector<int>);
    }

    pair<int, int> p1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            r = rand() % sizes[i];
            v[i]->push_back(r);
            p1.first = r;
            p1.second = r;
            sRand[i]->Set(j, r);
            sRandPair[i]->Set(j, p1);
        }
    }

    ofstream file1("nlogn.txt");
    ofstream file2("n2.txt");

    for (int i = 0; i < n; i++)
    {
        ISorter<int>* isortBS = new BubbleSorter<int>();
        double timeBS = timeSortMilli(isortBS, sRand[i], compInteger);

        ISorter<int>* isortIS = new InsertionSorter<int>();
        double timeIS = timeSortMicro(isortIS, sRand[i], compInteger);

        ISorter<int>* isortMS = new MergeSorter<int>();
        double timeMS = timeSortMicro(isortMS, sRand[i], compInteger);

        ISorter<int>* isortQSL = new QuickSorterLeft<int>();
        double timeQSL = timeSortMilli(isortQSL, sRand[i], compInteger);

        ISorter<int>* isortQSR = new QuickSorterRight<int>();
        double timeQSR = timeSortMilli(isortQSR, sRand[i], compInteger);

        ISorter<int>* isortQSM = new QuickSorterMiddle<int>();
        double timeQSM = timeSortMicro(isortQSM, sRand[i], compInteger);

        ISorter<int>* isortHS = new HeapSorter<int>();
        double timeHS = timeSortMicro(isortHS, sRand[i], compInteger);

        ISorter<int>* isortSelS = new SelectionSorter<int>();
        double timeSelS = timeSortMilli(isortSelS, sRand[i], compInteger);

        ISorter<int>* isortShellS = new ShellSorter<int>();
        double timeShellS = timeSortMicro(isortShellS, sRand[i], compInteger);

        double timeCountS = timeSortCounting(sRandPair[i], v[i]);

        file1 << sizes[i] << " " << timeMS << " " << timeHS << " " << timeQSM <<  " " << timeShellS << " " << timeIS << endl;

        file2 << sizes[i] << " " << timeBS << " " << " " << timeSelS << " " << timeQSR << " " << timeQSL << " " << timeCountS << endl;

        delete isortBS;
        delete isortMS;
        delete isortHS;
        delete isortIS;
        delete isortSelS;
        delete isortShellS;
        delete isortQSL;
        delete isortQSM;
        delete isortQSR;
        delete sRand[i];
        delete sRandPair[i];
        delete v[i];
    }


    FILE *gnuplotP = popen("gnuplot -persist", "w");
    if (gnuplotP)
    {
        fprintf(gnuplotP, "set encoding utf8\n");
        fprintf(gnuplotP, "set terminal windows\n");
        fprintf(gnuplotP, "set output \"plotTime.pdf\" \n");
        fprintf(gnuplotP, "set multiplot\n");
        fprintf(gnuplotP, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP, "set ylabel 'Time (in ms)'\n");
        fprintf(gnuplotP, "set title 'Time of sorting sequences with random elements'\n");
        fprintf(gnuplotP, "plot \"n2.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Bubble sort\", '' using 1:3 w lines lc rgb \"black\" title \"Selection sort\", '' using 1:4 w lines lc rgb \"red\" title \"Quick sort (right)\", '' using 1:5 w lines lc rgb \"green\" title \"Quick sort (left)\", '' using 1:6 w lines lc rgb \"yellow\" title  \"Counting sort\" \n");
        fprintf(gnuplotP, "unset multiplot\n");
        fflush(gnuplotP);
        fprintf(gnuplotP,"exit \n");
        pclose(gnuplotP);
    }

    FILE *gnuplotP2 = popen("gnuplot -persist", "w");
    if (gnuplotP2)
    {
        fprintf(gnuplotP2, "set encoding utf8\n");
        fprintf(gnuplotP2, "set terminal windows\n");
        fprintf(gnuplotP2, "set output \"plotTime2.pdf\" \n");
        fprintf(gnuplotP2, "set multiplot\n");
        fprintf(gnuplotP2, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP2, "set ylabel 'Time (in mcs)'\n");
        fprintf(gnuplotP2, "set title 'Time of sorting sequences with random elements'\n");
        fprintf(gnuplotP2, "plot \"nlogn.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Merge sort\", '' using 1:3 w lines lc rgb \"red\" title \"Heap sort\", '' using 1:4 w lines lc rgb \"green\" title \"Quick sort (middle)\", '' using 1:5 w lines lc rgb \"black\" title \"Shell sort\", '' using 1:6 w lines lc rgb \"orange\" title \"Insertion sort\" \n");
        fprintf(gnuplotP2, "unset multiplot\n");
        fflush(gnuplotP2);
        fprintf(gnuplotP2,"exit \n");
        pclose(gnuplotP2);
    }

}

void SortedBenchmark()
{
    vector<Sequence<int>*> sRand;
    vector<Sequence<pair<int, int>>*> sRandPair;
    vector<vector<int>*> v;

    pair<int, int> p1;

    for (int i = 0; i < n; i++)
    {
        sRand.push_back((Sequence<int>*)new ArraySequence<int>(sizes[i]));
        sRandPair.push_back((Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>(sizes[i]));
        v.push_back(new vector<int>);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            v[i]->push_back(j);
            p1.first = j;
            p1.second = j;
            sRand[i]->Set(j, j);
            sRandPair[i]->Set(j, p1);
        }
    }

    ofstream file1("nlogn.txt");
    ofstream file2("n2.txt");

    for (int i = 0; i < n; i++)
    {
        ISorter<int>* isortBS = new BubbleSorter<int>();
        double timeBS = timeSortMilli(isortBS, sRand[i], compInteger);

        ISorter<int>* isortIS = new InsertionSorter<int>();
        double timeIS = timeSortMicro(isortIS, sRand[i], compInteger);

        ISorter<int>* isortMS = new MergeSorter<int>();
        double timeMS = timeSortMicro(isortMS, sRand[i], compInteger);

        ISorter<int>* isortQSL = new QuickSorterLeft<int>();
        double timeQSL = timeSortMilli(isortQSL, sRand[i], compInteger);

        ISorter<int>* isortQSR = new QuickSorterRight<int>();
        double timeQSR = timeSortMilli(isortQSR, sRand[i], compInteger);

        ISorter<int>* isortQSM = new QuickSorterMiddle<int>();
        double timeQSM = timeSortMicro(isortQSM, sRand[i], compInteger);

        ISorter<int>* isortHS = new HeapSorter<int>();
        double timeHS = timeSortMicro(isortHS, sRand[i], compInteger);

        ISorter<int>* isortSelS = new SelectionSorter<int>();
        double timeSelS = timeSortMilli(isortSelS, sRand[i], compInteger);

        ISorter<int>* isortShellS = new ShellSorter<int>();
        double timeShellS = timeSortMicro(isortShellS, sRand[i], compInteger);

        double timeCountS = timeSortCounting(sRandPair[i], v[i]);

        file1 << sizes[i] << " " << timeMS << " " << timeHS << " " << timeQSM <<  " " << timeShellS << " " << timeIS << endl;

        file2 << sizes[i] << " " << timeBS << " " << " " << timeSelS << " " << timeQSR << " " << timeQSL  << " " << timeCountS << endl;

        delete isortBS;
        delete isortMS;
        delete isortHS;
        delete isortIS;
        delete isortSelS;
        delete isortShellS;
        delete isortQSL;
        delete isortQSM;
        delete isortQSR;
        delete sRand[i];
        delete sRandPair[i];
        delete v[i];
    }

    FILE *gnuplotP = popen("gnuplot -persist", "w");
    if (gnuplotP)
    {
        fprintf(gnuplotP, "set encoding utf8\n");
        fprintf(gnuplotP, "set terminal windows\n");
        fprintf(gnuplotP, "set output \"plotTime.pdf\" \n");
        fprintf(gnuplotP, "set multiplot\n");
        fprintf(gnuplotP, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP, "set ylabel 'Time (in ms)'\n");
        fprintf(gnuplotP, "set title 'Time of sorting of sorted sequences'\n");
        fprintf(gnuplotP, "plot \"n2.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Bubble sort\", '' using 1:3 w lines lc rgb \"black\" title \"Selection sort\", '' using 1:4 w lines lc rgb \"red\" title \"Quick sort (right)\", '' using 1:5 w lines lc rgb \"green\" title \"Quick sort (left)\", '' using 1:6 w lines lc rgb \"yellow\" title  \"Counting sort\" \n");
        fprintf(gnuplotP, "unset multiplot\n");
        fflush(gnuplotP);
        fprintf(gnuplotP,"exit \n");
        pclose(gnuplotP);
    }

    FILE *gnuplotP2 = popen("gnuplot -persist", "w");
    if (gnuplotP2)
    {
        fprintf(gnuplotP2, "set encoding utf8\n");
        fprintf(gnuplotP2, "set terminal windows\n");
        fprintf(gnuplotP2, "set output \"plotTime2.pdf\" \n");
        fprintf(gnuplotP2, "set multiplot\n");
        fprintf(gnuplotP2, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP2, "set ylabel 'Time (in mcs)'\n");
        fprintf(gnuplotP2, "set title 'Time of sorting of sorted sequences'\n");
        fprintf(gnuplotP2, "plot \"nlogn.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Merge sort\", '' using 1:3 w lines lc rgb \"red\" title \"Heap sort\", '' using 1:4 w lines lc rgb \"green\" title \"Quick sort (middle)\", '' using 1:5 w lines lc rgb \"black\" title \"Shell sort\", '' using 1:6 w lines lc rgb \"orange\" title \"Insertion sort\" \n");
        fprintf(gnuplotP2, "unset multiplot\n");
        fflush(gnuplotP2);
        fprintf(gnuplotP2,"exit \n");
        pclose(gnuplotP2);
    }

}

void ReverseBenchmark()
{
    vector<Sequence<int>*> sRand;
    vector<Sequence<pair<int, int>>*> sRandPair;
    vector<vector<int>*> v;

    pair<int, int> p1;

    for (int i = 0; i < n; i++)
    {
        sRand.push_back((Sequence<int>*)new ArraySequence<int>(sizes[i]));
        sRandPair.push_back((Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>(sizes[i]));
        v.push_back(new vector<int>);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            v[i]->push_back(sizes[i] - j);
            p1.first = sizes[i] - j;
            p1.second = sizes[i] - j;
            sRand[i]->Set(j, sizes[i] - j);
            sRandPair[i]->Set(j, p1);
        }
    }

    ofstream file1("nlogn.txt");
    ofstream file2("n2.txt");

    for (int i = 0; i < n; i++)
    {
        ISorter<int>* isortBS = new BubbleSorter<int>();
        double timeBS = timeSortMilli(isortBS, sRand[i], compInteger);

        ISorter<int>* isortIS = new InsertionSorter<int>();
        double timeIS = timeSortMicro(isortIS, sRand[i], compInteger);

        ISorter<int>* isortMS = new MergeSorter<int>();
        double timeMS = timeSortMicro(isortMS, sRand[i], compInteger);

        ISorter<int>* isortQSL = new QuickSorterLeft<int>();
        double timeQSL = timeSortMilli(isortQSL, sRand[i], compInteger);

        ISorter<int>* isortQSR = new QuickSorterRight<int>();
        double timeQSR = timeSortMilli(isortQSR, sRand[i], compInteger);

        ISorter<int>* isortQSM = new QuickSorterMiddle<int>();
        double timeQSM = timeSortMicro(isortQSM, sRand[i], compInteger);

        ISorter<int>* isortHS = new HeapSorter<int>();
        double timeHS = timeSortMicro(isortHS, sRand[i], compInteger);

        ISorter<int>* isortSelS = new SelectionSorter<int>();
        double timeSelS = timeSortMilli(isortSelS, sRand[i], compInteger);

        ISorter<int>* isortShellS = new ShellSorter<int>();
        double timeShellS = timeSortMicro(isortShellS, sRand[i], compInteger);

        double timeCountS = timeSortCounting(sRandPair[i], v[i]);

        file1 << sizes[i] << " " << timeMS << " " << timeHS << " " << timeQSM <<  " " << timeShellS << " " << timeIS << endl;

        file2 << sizes[i] << " " << timeBS << " " << " " << timeSelS << " " << timeQSR << " " << timeQSL << " " << timeCountS << endl;

        delete isortBS;
        delete isortMS;
        delete isortHS;
        delete isortIS;
        delete isortSelS;
        delete isortShellS;
        delete isortQSL;
        delete isortQSM;
        delete isortQSR;
        delete sRand[i];
        delete sRandPair[i];
        delete v[i];

    }

    FILE *gnuplotP = popen("gnuplot -persist", "w");
    if (gnuplotP)
    {
        fprintf(gnuplotP, "set encoding utf8\n");
        fprintf(gnuplotP, "set terminal windows\n");
        fprintf(gnuplotP, "set output \"plotTime.pdf\" \n");
        fprintf(gnuplotP, "set multiplot\n");
        fprintf(gnuplotP, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP, "set ylabel 'Time (in ms)'\n");
        fprintf(gnuplotP, "set title 'Time of sorting sequences with reverse order'\n");
//        fprintf(gnuplotP, "set xrange [*:*]\n");
//        fprintf(gnuplotP, "set yrange [*:*]\n");
//        fprintf(gnuplotP, "plot \"nlogn.txt\"  using 1:2 w lines title \'Merge sort\', '' using 1:3 w lines title \'Heap sort\', '' using 1:4 w lines title \'Quick sort (right)\', '' using 1:5 w lines title \'Quick sort (left)\', '' using 1:6 lines title \'Quick sort (middle)\' \n");
        fprintf(gnuplotP, "plot \"n2.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Bubble sort\", '' using 1:3 w lines lc rgb \"black\" title \"Selection sort\", '' using 1:4 w lines lc rgb \"red\" title \"Quick sort (right)\", '' using 1:5 w lines lc rgb \"green\" title \"Quick sort (left)\", '' using 1:6 w lines lc rgb \"yellow\" title  \"Counting sort\" \n");
//        fprintf(gnuplotP, "plot \"nlogn.txt\"  using 1:2 w lines title \"Merge sort\", '' using 1:3 w lines title \"Heap sort\", '' using 1:6 w lines title \"Quick sort (middle)\" \n");
//        fprintf(gnuplotP, "plot \"nlogn.txt\"  using 1:2 w lines title \"Merge sort\", '' using 1:3 w lines title \"Heap sort\", '' using 1:4 w lines title \"Quick sort\" \n");
        fprintf(gnuplotP, "unset multiplot\n");
        fflush(gnuplotP);
        fprintf(gnuplotP,"exit \n");
        pclose(gnuplotP);
    }

    FILE *gnuplotP2 = popen("gnuplot -persist", "w");
    if (gnuplotP2)
    {
        fprintf(gnuplotP2, "set encoding utf8\n");
        fprintf(gnuplotP2, "set terminal windows\n");
        fprintf(gnuplotP2, "set output \"plotTime2.pdf\" \n");
        fprintf(gnuplotP2, "set multiplot\n");
        fprintf(gnuplotP2, "set xlabel 'Size of sequence'\n");
        fprintf(gnuplotP2, "set ylabel 'Time (in mcs)'\n");
        fprintf(gnuplotP2, "set title 'Time of sorting sequences with reverse order'\n");
        fprintf(gnuplotP2, "plot \"nlogn.txt\"  using 1:2 w lines lc rgb \"blue\" title \"Merge sort\", '' using 1:3 w lines lc rgb \"red\" title \"Heap sort\", '' using 1:4 w lines lc rgb \"green\" title \"Quick sort (middle)\", '' using 1:5 w lines lc rgb \"black\" title \"Shell sort\", '' using 1:6 w lines lc rgb \"orange\" title \"Insertion sort\" \n");
        fprintf(gnuplotP2, "unset multiplot\n");
        fflush(gnuplotP2);
        fprintf(gnuplotP2,"exit \n");
        pclose(gnuplotP2);
    }

}



#endif // BENCHMARK_H_INCLUDED
