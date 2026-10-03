#include "SortedArray.h"
#include <cstring>

//Αυτή η κλάση αναπαριστά τη δομή ενός ταξινομημένου πίνακα

SortedArray::SortedArray(int s)     //Constructor
{
    num=0;
    arr_size=s;
    arr = new string[arr_size];         //Δήλωση του πίνακα arr[]
    freq=new int[arr_size];             //Δήλωση του πίνακα freq[]
        for(int i=0;i<arr_size;i++)
        {
            freq[i]=1;                 //Αρχικοποίηση του freq με 1
        }

}

SortedArray::~SortedArray()
{
    //dtor
}


string SortedArray::addWord(string word)     //Συνάρτηση εισαγωγής λέξεων στον πίνακα
{
    for(int i=0;i<num;i++)      //η μεταβλητή num ξεκινάει με 0 και κάθε φορά που γίνεται επιτυχής εισαγωγή λέξης αυξάνεται κατά 1
    {
        if(word==arr[i])        //αν η εισερχόμενη λέξη υπάρχει ήδη στον πίνακα αυξάνουμε τη συχνότητά της και
        {                       //την επιστρέφουμε χωρίς να την εισάγουμε στον πίνακα (κάθε λέξη υπάρχει 1 μόνο φορά)
            freq[i]++;
            return arr[i];
        }
    }
    arr[num] = word;            //εφόσον η λέξη δεν υπάρχει ήδη στον πίνακα εκχωρείται στη θέση num
    num++;                      //άυξηση του num για την επόμενη λέξη που θα εισαχθεί στον arr[]

    return arr[num-1];          //επιστρέφουμε την λέξη που εκχωρήθηκε στον πίνακα arr[] επιτυχώς
}

void SortedArray::Sort()    //συνάρτηση για κλήση της αναδρομικής quickSort για ταξινόμιση του πίνακα arr[]
{
    quickSort(arr,0,num-1);
}

void SortedArray::quickSort(string* arr,int low, int high)  //συνάρτηση ταξινόμησης με QuickSort
{
     if (low < high)                //low η αρχή του πίνακα και high το τέλος
    {
        int pi = partitioning(arr,low, high);

        quickSort(arr,low, pi - 1);
        quickSort(arr,pi + 1, high);
    }
}

int SortedArray::partitioning(string* arr,int low, int high)
{
    string pivot = arr[high], temp;
    int temp2;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

            temp2=freq[i];      //ταξινομούμε ταυτόχρονα και τον πίνακα freq ώστε να είναι παράλληλος με τον arr[]
            freq[i]=freq[j];
            freq[j]=temp2;
        }
    }
        temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;

        temp2=freq[i+1];
        freq[i+1]=freq[high];
        freq[high]=temp2;

    return (i + 1);
}

int SortedArray::getFreq()      //αυτή η συνάρτηση επιστρέφει τη συχνότητα της εκάστοτε λέξης που ζητείται
{
    return freq[num_for_freq];
}

string SortedArray::findWord(string w) //συνάρτηση για κλήση της αναδρομικής binarySearch και αναζήτηση της λέξης w στον arr[]
{
    return binarySearch(arr,0,num,w);
}

string SortedArray::binarySearch(string* arr,int l, int r, string w)  //συνάρτηση δυαδικής αναζήτησης
{
     if (r >= l)                        //l η αρχή του πίνακα, r το τέλος
    {
        int mid = l + (r - l) / 2;      //βρίσκουμε το μέσο του πίνακα

        if (arr[mid] == w)              //αν η λέξη είναι στο μέσο κρατάμε τη θέση της και την επιστρέφουμε
        {
            num_for_freq = mid;
            return arr[mid];
        }


        if (arr[mid] > w)       //αν η λέξη είναι μικρότερη από τη λέξη στο μέσο εκτελούμε δυαδική αναζήτηση στο πρώτο μισό του πίνακα
             return binarySearch(arr,l, mid - 1, w);

        return binarySearch(arr,mid + 1, r, w); //διαφορετικά εκτελούμε δυαδική αναζήτηση στο δεύτερο μισό
    }                                           //συνεχίζουμε την ίδια διαδικασία μέχρι να βρεθεί η λέξη που αναζητούμε ή μέχρι να τελειώσει ο πίνακας

    return nullptr;                             //αν δε βρεθεί το στοιχείο επιστρέφουμε null
}

void SortedArray::deleteWord(string word)       //συνάρτηση διαγραφής λέξεων
{
      findWord(word);                           //καλούμε τη findWord() ώστε να βρούμε τη θέση της λέξης που θέλουμε να διαγραφεί
      for(int i=num_for_freq; i<num-1;i++)
      {
          arr[i]=arr[i+1];                      //από τη θέση της λέξης και μετά τις πάμε όλες μία θέση πίσω

      }
}

void SortedArray::print()                        //συνάρτηση για εκτύπωση του πίνακα
{
    for(int i=0;i<num;i++)
        cout<<arr[i]<<endl;
}







