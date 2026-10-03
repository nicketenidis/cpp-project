#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <string>
#include <iostream>

using namespace std;

class SortedArray
{
    public:
        SortedArray(int);
        virtual ~SortedArray();

        void quickSort(string*,int,int);
        int partitioning(string*,int,int);
        void Sort();
        string addWord(string);
        void deleteWord(string);
        string findWord(string);
        string binarySearch(string*,int,int,string);
        int getFreq();
        void print();


    protected:

    private:
       string *arr;
       int arr_size;
       int num;
       int num_for_freq;
       int *freq;
};

#endif // SORTEDARRAY_H
