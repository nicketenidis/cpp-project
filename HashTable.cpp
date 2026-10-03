#include "HashTable.h"
#include <string>
#include <bits/stdc++.h>


using namespace std;

HashTable::HashTable(int Size)  //Constructor
{
    table_size=Size;
    setA();
    setfreq();

}

HashTable::~HashTable()
{
    //dtor
}


void HashTable::setA()              //Κατασκευή του πίνακα που περιέχει τις λέξεις
{
    int i;

    A = new string[table_size];

    for (i = 0; i < table_size; i++)
        A[i] = "-";              //Καθε θέση του πίνακα περιέχει "-" όταν είναι άδεια
}

void HashTable::setfreq()       //Κατασκευή του πίνακα που περιέχει την συχνότητα της κάθε λέξης που υπάρχουν στον πίνακα
{
    int i;

    freq = new int[table_size];

    for (i = 0; i < table_size; i++)
        freq[i] = 0;                //Θέτουμε όλες τις λέξεις του πίνακα με 0
}

void HashTable::addWord(string w)
{

    int pos,i;
    pos=HashFunction(w,table_size);
    i=pos;

    if(A[pos]=="-")     //αμα η αρχική θέση είναι άδεια τότε η λέξη μπαίνει σε αυτή την θέση
    {
        A[pos]=w;
        freq[pos]++;    //Και αυξάνεται κατα 1 ο πίνακας συχνότητας
    }
    else if(A[pos]==w)   //αμα βρεθεί η ίδια λέξη τότε μόνο αυξάνεται κατα 1 σε αυτή την θέση ο πίνακας συχνότητας
        freq[pos]++;
    else
    {
        while(A[i] != "-" && A[i] != w) //Αυτή η περίπτωση ελέγχεται όταν μια λέξη πάει να μπει σε μια θέση που υπάρχει ήδη άλλη λέξη.
        {
            i++;                        //Επομένως, αυτή η επανάληψη ψάχνει να βρει την επόμενη κενή θέση ώστε να μπει σε αυτήν η λέξη
            if(i>table_size-1)
                i=0;
        }
        A[i]=w;
        freq[i]++;
    }

}

string HashTable::findWord(string w)
{
    int pos,i;
    bool found=0;
    pos=HashFunction(w,table_size); //Η αναζήτηση ξεκινά πάντοτε απο την θέση που θα επιστρέψει η συνάρτηση HashFunction
    i=pos;
    if (A[pos]=="-")        //αμα η θέση της λέξης είναι άδεια τότε δεν υπάρχει περίπτωση η λέξη να είναι στον πίνακα και η αναζήτηση δεν είναι επιτυχής
        return nullptr;
    while (!found)      //Η μεταβλητή found βοηθάει την επανάληψη να σταματήσει εάν η λέξη βρεθεί μέσα στον πίνακα.
    {
        if (A[i]==w)
        {
            num_for_freq=i;
            return A[i];
        }
        else
        {
            i++;      //’μα η λέξη δεν βρεθεί σε αυτή την θέση τοτε το πρόγραμμα αρχίζει να ψάχνει στο υπόλοιπο του πίνακα για την βρει.
            if(i>table_size - 1)  //’μα φτάσει στο τέλος του πίνακα τότε συνεχίζει την αναζήτηση απο την αρχή του πίνακα.
                i=0;
            if (i==pos)
            {
                return A[i];
            }
        }
    }
    return nullptr;
}

int HashTable::getFreq()
{
    return freq[num_for_freq];
}

int HashFunction(string w,int Size)     //H συνάρτηση αυτή δέχεται μια συμβολοσειρά και το μέγεθος του πίνακα.
{                                       //και κωδικοποιεί την κάθε λέξη σε έναν ακέραιο αριθμό
    int key=151;
    unsigned long convert=0;
        for(int i=0;i<w.size();i++)
        {
            convert=(convert * key) + w[i];
        }

    return (convert%Size);          //Και επιστρέφει έναν ακέραιο που δείχνει τη θέση που πρέπει να τοποθετηθεί η λέξη στον πίνακα των λέξεων.

}

