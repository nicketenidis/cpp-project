#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string>

using namespace std;

 struct BT     //δημιουργία struct BT
{               //κάθε κόμβος περιέχει
    string word;    //μια λέξη,
    int freq;       //μία μεταβλητή για υπολογισμό της συχνότητας,
    BT *left, *right;   //αριστερό και δεξί παιδί τύπου struct BΤ
    BT* parent;     //πατέρα τύπου struct BT
};

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();



        BT* newBT(string);

        string addWord(string);
        BT* findWord(string);
        void deleteWord(string);
        void Inorder(BT*);
        void Preorder(BT* );
        void Postorder(BT* );
        void printInorder();
        void printPostorder();
        void printPreorder();


    protected:

    private:

        BT *root;
        BT* temp;


};

#endif // BINARYTREE_H
