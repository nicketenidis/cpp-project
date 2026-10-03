#include "UnsortedArray.h"
#include <cstring>

//Αυτή η κλάση αναπαριστά τη δομή ενός αταξινόμητου πίνακα

UnsortedArray::UnsortedArray(int s)  //Constructor
{
    num=0;
    arr_size=s;
    arr = new string[arr_size];    //Δήλωση του πίνακα arr[]
    freq=new int [arr_size];       //Δήλωση του πίνακα freq[]

     for(int i=0;i<arr_size;i++)
     {
         freq[i]=1;               //Αρχικοποίηση του freq με 1
     }
}

UnsortedArray::~UnsortedArray()
{
    //dtor
}

string UnsortedArray::addWord(string word)  //Συνάρτηση εισαγωγής λέξεων στον πίνακα
{

    for(int i=0;i<num;i++)        //η μεταβλητή num ξεκινάει με 0 και κάθε φορά που γίνεται επιτυχής εισαγωγή λέξης αυξάνεται κατά 1
    {
        if(word==arr[i])          //αν η εισερχόμενη λέξη υπάρχει ήδη στον πίνακα αυξάνουμε τη συχνότητά της και
        {                          //την επιστρέφουμε χωρίς να την εισάγουμε στον πίνακα (κάθε λέξη υπάρχει 1 μόνο φορά)
            freq[i]++;
            return arr[i];
        }
    }

    arr[num] = word;            //εφόσον η λέξη δεν υπάρχει ήδη στον πίνακα εκχωρείται στη θέση num
    num++;                      //άυξηση του num για την επόμενη λέξη που θα εισαχθεί στον arr[]

    return arr[num-1];          //επιστρέφουμε την λέξη που εκχωρήθηκε στον πίνακα arr[] επιτυχώς
}

int UnsortedArray::getFreq()   //αυτή η συνάρτηση επιστρέφει τη συχνότητα της εκάστοτε λέξης που ζητείται
{
    return freq[num_for_freq];
}


string UnsortedArray::findWord(string word) //συνάρτηση αναζήτησης λέξεων
{
    for(int i=0 ; i<num ; i++)      //διαπέραση του πίνακα
    {
        if(word == arr[i])         //αν βρεθεί η λέξη κρατάμε τη θέση της και την επιστρέφουμε
        {
            num_for_freq = i;
            return arr[i];
        }
    }
    return nullptr;
}



void UnsortedArray::deleteWord(string word)  //συνάρτηση διαγραφής λέξεων
{
      findWord(word);                        //καλούμε τη findWord() ώστε να βρούμε τη θέση της λέξης που θέλουμε να διαγραφεί
      for(int i=num_for_freq; i<num-1;i++)
      {
          arr[i]=arr[i+1];                   //από τη θέση της λέξης και μετά τις πάμε όλες μία θέση πίσω

      }
}

void UnsortedArray::print()     //συνάρτηση για εκτύπωση του πίνακα
{
    for(int i=0;i<num;i++)
        cout<<arr[i]<<endl;
}




