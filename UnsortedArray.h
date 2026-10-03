#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H
#include <string>
#include <iostream>

using namespace std;

class UnsortedArray
{
    public:

        UnsortedArray(int);
        virtual ~UnsortedArray();

        void deleteWord(string);
        string addWord(string);
        string findWord(string);
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

#endif // UNSORTEDARRAY_H
