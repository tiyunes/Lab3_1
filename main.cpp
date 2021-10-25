#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSortF.h"
#include "QuickSortM.h"
#include "QuickSort3.h"
#include "tests.h"
#include "benchmark.h"
#include "ISorter.h"
#include <cmath>


using namespace std;

bool comp1(int a, int b)
{
    if(a < b)
    {
        return 1;
    }
    else return 0;
}

bool comp2(double a, double b)
{
    if(a < b)
    {
        return 1;
    }
    else return 0;
}

bool comp3(char a, char b)
{
    if(a < b)
    {
        return 1;
    }
    else return 0;
}

bool isEqualInt(int a, int b)
{
    if(a == b)
    {
        return 1;
    }
    else return 0;
}
function<bool(int, int)>compInt = comp1;
function<bool(int, int)>compDouble = comp2;
function<bool(int, int)>compChar = comp3;
//function<bool(int, int)>isEqual = isEqualInt;
int main()
{
    int var = 0;
    int length = 0;
    int x;
    pair<int, int> p1;
    while (var != 8)
    {
        cout << "Choose the option: " << endl;
        cout << "1. Sort sequence by BubbleSort " << endl << "2. Sort sequence by InsertionSort" << endl
        << "3. Sort sequence by MergeSort" << endl << "4. Sort sequence by QuickSort" << endl
        << "5. Sort sequence by QuickSort with first barrier element" << endl
        << "6. Sort sequence by QuickSort with middle barrier element" << endl
        << "7. Sort sequence by CountingSort" << endl << "8. Exit" << endl;
        cin >> var;
        switch (var)
        {
            case 1:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new BubbleSorter<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

            case 2:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new InsertionSorter<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

            case 3:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new MergeSorter<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

            case 4:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new QuickSorter<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

             case 5:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new QuickSorterF<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

                case 6:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            s1->Append(x);
                        }
                        ISorter<int>* isort = new QuickSorterM<int>();
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = isort->Sorter(s1, compInt);
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        //delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

            case 7:
                {
                    try
                    {
                        cout << "Enter the length of sequence: " << endl;
                        cin >> length;
                        if (length <= 0)
                        {
                            throw std::out_of_range("Invalid length");
                        }
                        Sequence<pair<int, int>>* s1 = (Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>();
                        vector<int> v;
                        cout << "Enter the elements of sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cin >> x;
                            v.push_back(x);
                            p1.first = x;
                            p1.second = x;
                            s1->Append(p1);
                        }
                        Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                        sSort1 = CountingSort(s1, *max_element(v.begin(), v.end()));
                        cout << "Sorted sequence: " << endl;
                        for (int i = 0; i < length; i++)
                        {
                            cout << sSort1->Get(i) << endl;
                        }
                        delete[] s1;
                        delete[] sSort1;
                        break;
                    }
                    catch(out_of_range &e)
                    {
                        cout << e.what() << endl;
                        break;
                    }
                }

            case 8:
                break;

            default:
                {
                    cout << "Choose correct option" << endl;
                    break;
                }
        }
    }
    cout << endl;
    testInt(compInt);
    testDouble(compDouble);
    testChar(compChar);
    //RandomBenchmark();
    //SortedBenchmark();
    //ReverseBenchmark();
}
