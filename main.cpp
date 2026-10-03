#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <iterator>
#include <cstdio>
#include <ctime>
#include "UnsortedArray.h"
#include "SortedArray.h"
#include "BinaryTree.h"
#include "AVLtree.h"
#include "HashTable.h"

using namespace std;

int main()
{

   string* arr2 = new string[1000];

   fstream file;
   string word, filename;
   list<string> mylist;

   filename= "C:\\Users/User/Desktop/gutenberg.txt";
   file.open(filename.c_str());

    while (file >> word)     //διαβασμα αρχείου λέξη-λέξη και αφαίρεση των σημείων στίξης
    {
        for(int i=0;i<=word.length();i++)
        {
           if(word[i]>=65 && word[i]<=90)
                word[i]=word[i]+32;

           if ((word[i]>=33 && word[i]<=47) || (word[i]>=58 && word[i]<=64) || (word[i]>=91 && word[i]<=96) || (word[i]>=123 && word[i]<=126)  || (word[i]>=128 && word[i]<=255))
           {
                word.erase(word.begin() +i);
                i--;
           }
        }
        mylist.push_back(word);  //προσθήκη των λέξεων σε μία λίστα με όνομα mylist
    }



    srand(time(NULL));


    clock_t start;
    double duration_un;
    double duration_sor;
    double duration_bt;
    double duration_avl;
    double duration_ht;

    list<string>::iterator it = mylist.begin();

        for(int i=0;i<1000;i++)     //με τη βοήθεια της συνάρτησης rand() επιλέγονται τυχαία 1000 λέξεις από τη λίστα και εκχωρούνται σε έναν πίνακα arr2[]
        {

            int j= rand() % mylist.size();
            advance(it,j);
            arr2[i] = *it;

            it=mylist.begin();
        }


    UnsortedArray un(mylist.size());  //δημιουργία αντικειμένων από κάθε κλάση
    SortedArray sor(mylist.size());
    BinaryTree bt;
    AVLtree av;
    HashTable ht(mylist.size());

        for (string word : mylist) //διαπέραση της λίστας και εισαγωγή των λέξεων στις δομές μία προς μία
        {
            un.addWord(word);
            sor.addWord(word);
            bt.addWord(word);
            av.addWord(word);
            ht.addWord(word);
        }

    start = clock();
    cout<<"----------------------------------------------UNSORTED ARRAY-------------------------------------------------"<<endl;

        for(int i=0 ; i<1000; i++) //αναζήτηση των 1000 λέξεων του arr2[] στον αταξινόμητο πίνακα και εμφάνιση της συχνότητάς τους
        {
            cout<<"Word: "<<un.findWord(arr2[i])<<" -- Times: "<<un.getFreq()<<endl;
        }
    //un.print(); //εκτύπωση του αταξινόμητου πίνακα

    duration_un = ( clock() - start ) / (double) CLOCKS_PER_SEC;  //συνολικός χρόνος που χρειάστηκε η δομή να εκτελέσει αναζήτηση των λέξεων

    start=clock();
     cout<<"----------------------------------------------SORTED ARRAY--------------------------------------------------"<<endl;

    sor.Sort();
      for(int i=0;i<1000;i++) //αναζήτηση των 1000 λέξεων του arr2[] στον ταξινομημένο πίνακα και εμφάνιση της συχνότητάς τους
      {
       cout<<"Word: "<<sor.findWord(arr2[i])<<" -- Times: "<<sor.getFreq()<<endl;
      }
    //sor.print()  //εκτύπωση του ταξινομημένου πίνακα
    duration_sor = ( clock() - start ) / (double) CLOCKS_PER_SEC; //συνολικός χρόνος που χρειάστηκε η δομή να εκτελέσει ταξινόμιση και αναζήτηση των λέξεων

    start=clock();
    cout<<"-------------------------------------------------BINARY TREE------------------------------------------------------"<<endl;
        for(int i=0; i<1000;i++) //αναζήτηση των 1000 λέξεων του arr2[] στο δυαδικό δένδρο και εμφάνιση της συχνότητάς τους
        {
           cout<<"Word: "<<bt.findWord(arr2[i])->word<<" -- Times: "<<bt.findWord(arr2[i])->freq<<endl;
        }

   // bt.printInorder();   //δυνατότητα εκτύπωσης του δένδρου με 3 τρόπους
   // bt.printPostorder();
   // bt.printPreorder();


    duration_bt = ( clock() - start ) / (double) CLOCKS_PER_SEC; //συνολικός χρόνος που χρειάστηκε η δομή να εκτελέσει αναζήτηση των λέξεων


    start=clock();
    cout<<"--------------------------------------------------AVL BINARY TREE---------------------------------------------------"<<endl;
        for(int i=0; i<1000;i++) //αναζήτηση των 1000 λέξεων του arr2[] στο AVL δυαδικό δένδρο και εμφάνιση της συχνότητάς τους
        {
           cout<<"Word: "<<av.findWord(arr2[i])->word<<" -- Times: "<<av.findWord(arr2[i])->freq<<endl;
        }

    //av.printInorder();   //δυνατότητα εκτύπωσης του δένδρου με 3 τρόπους
    //av.printPostorder();
    //av.printPreorder();
    duration_avl = ( clock() - start ) / (double) CLOCKS_PER_SEC; //συνολικός χρόνος που χρειάστηκε η δομή να εκτελέσει αναζήτηση των λέξεων

    cout<<"----------------------------------------------------HASH TABLE------------------------------------------------------"<<endl;
    start=clock();

        for(int i=0; i<1000;i++) //αναζήτηση των 1000 λέξεων του arr2[] στον πίνακα κατακερματισμού και εμφάνιση της συχνότητάς τους
        {
            cout<<"Word: "<<ht.findWord(arr2[i])<<" -- Times: "<<ht.getFreq()<<endl;
        }

    duration_ht = ( clock() - start ) / (double) CLOCKS_PER_SEC; //συνολικός χρόνος που χρειάστηκε η δομή να εκτελέσει αναζήτηση των λέξεων


    cout<<"----------------------------------------------------TOTAL TIME----------------------------------------------------------"<<endl;
    cout<<"Unsorted Array time: "<<duration_un<<endl; //εμφάνιση των συνολικών χρόνων
    cout<<"Sorted Array time: "<<duration_sor<<endl;
    cout<<"Binary Tree time: "<<duration_bt<<endl;
    cout<<"AVL Binary Tree time: "<<duration_avl<<endl;
    cout<<"Hash Table time: "<<duration_ht<<endl;


    return 0;
}
