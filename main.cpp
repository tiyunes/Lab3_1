#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSortRight.h"
#include "QuickSortLeft.h"
#include "QuickSortMiddle.h"
#include "tests.h"
#include "benchmark.h"
#include "ISorter.h"
#include "HeapSort.h"


using namespace std;

void sortSequence(ISorter<int>* isort, function<bool(int, int)> cmp)
{
    try
    {
        int length, x;
        cout << endl;
        cout << "Enter the length of sequence: " << endl;
        cin >> length;
        if (length <= 0)
        {
            throw std::out_of_range("Invalid length");
        }

        Sequence<int>* s1 = (Sequence<int>*)new ArraySequence<int>();
        cout << endl;
        cout << "Enter the elements of sequence: " << endl;

        string s;
        cin.ignore();
        getline(cin, s);
        istringstream iss(s);

        for (int i = 0; i < length; i++)
        {
            iss >> x;
            s1->Append(x);
        }

        isort->Sorter(s1, cmp);
        cout << endl;
        cout << "Sorted sequence: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << s1->Get(i) << endl;
        }
    }

    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
}

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

int main()
{
    int var = 0;

    while (var != 11)
    {
        cout << endl;
        cout << "Choose the option: " << endl;
        cout << "1. Sort sequence by BubbleSort " << endl << "2. Sort sequence by InsertionSort" << endl
        << "3. Sort sequence by MergeSort" << endl << "4. Sort sequence by QuickSort with first barrier element" << endl
        << "5. Sort sequence by QuickSort with middle barrier element" << endl
        << "6. Sort sequence by QuickSort with last barrier element" << endl
        << "7. Sort sequence by Heap sort" << endl <<  "8. Sort sequence by Shell sort " << endl
        << "9. Sort sequence by Selection sort" << endl << "10. Sort sequence by Counting sort" <<  endl << "11. Exit and start a benchmark" << endl;
        cin >> var;
        switch (var)
        {
            case 1:
            {
                ISorter<int>* isort = new BubbleSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 2:
            {
                ISorter<int>* isort = new InsertionSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 3:
            {
                ISorter<int>* isort = new MergeSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 4:
            {
                ISorter<int>* isort = new QuickSorterLeft<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 5:
            {
                ISorter<int>* isort = new QuickSorterMiddle<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 6:
            {
                ISorter<int>* isort = new QuickSorterRight<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 7:
            {
                ISorter<int>* isort = new HeapSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 8:
            {
                ISorter<int>* isort = new ShellSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 9:
            {
                ISorter<int>* isort = new SelectionSorter<int>();
                sortSequence(isort, compInt);
                break;
            }

            case 10:
            {
                try
                {
                    int length = 0;
                    int x;
                    pair<int, int> p1;
                    cout << endl;
                    cout << "Enter the length of sequence: " << endl;
                    cin >> length;
                    if (length <= 0)
                    {
                        throw std::out_of_range("Invalid length");
                    }
                    Sequence<pair<int, int>>* s1 = (Sequence<pair<int, int>>*)new ArraySequence<pair<int, int>>();
                    vector<int> v;
                    cout << endl;
                    cout << "Enter the elements of sequence: " << endl;

                    string s;
                    cin.ignore();
                    getline(cin, s);
                    istringstream iss(s);

                    for (int i = 0; i < length; i++)
                    {
                        iss >> x;
                        v.push_back(x);
                        p1.first = x;
                        p1.second = x;
                        s1->Append(p1);
                    }

                    Sequence<int>* sSort1 = (Sequence<int>*)new ArraySequence<int>(length);
                    sSort1 = CountingSort(s1, *max_element(v.begin(), v.end()));
                    cout << endl;
                    cout << "Sorted sequence: " << endl;
                    for (int i = 0; i < length; i++)
                    {
                        cout << sSort1->Get(i) << endl;
                    }
                    break;
                }

                catch(out_of_range &e)
                {
                    cout << e.what() << endl;
                    break;
                }
            }

            case 11:
            {
                break;
            }

            default:
            {
                cout << endl;
                cout << "Choose correct option" << endl;
                break;
            }
        }
    }


    int flag = 0;

    while (flag != 4)
    {
        cout << endl;
        cout << "Choose the option: " << endl;
        cout << "1. Time of sorting sequences with random elements" << endl << "2. Time of sorting sorted sequences"
        << endl << "3. Time of sorting reversed sequences" << endl << "4. Exit" << endl;
        cin >> flag;
        switch(flag)
        {
        case 1:
            {
                RandomBenchmark();
                break;
            }
        case 2:
            {
                SortedBenchmark();
                break;
            }
        case 3:
            {
                ReverseBenchmark();
                break;
            }
        case 4:
            {
                break;
            }
        default:
            {
                cout << endl;
                cout << "Choose correct option" << endl;
                break;
            }
        }
    }

    testInt(compInt);
    testDouble(compDouble);
    testChar(compChar);
}
