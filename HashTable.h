#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>


using namespace std;

class HashTable
{

    public:
        HashTable(int);
        virtual ~HashTable();
        void setA();
        void setfreq();

        void addWord(string);
        string findWord(string);
        int getFreq();

    protected:

    private:
        int table_size ;
        string *A;
        int *freq;
        string * table;
        int num_for_freq;
};

int HashFunction(string,int);

#endif // HASHTABLE_H
