#include "BinaryTree.h"
#include <bits/stdc++.h>

BinaryTree::BinaryTree() //Constructor
{
    root=nullptr;          //αρχικοποίηση της ρίζας με null
}

BinaryTree::~BinaryTree()
{
    //dtor
}

BT* BinaryTree:: newBT(string data) //συνάρτηση για δημιουργία νέου struct BT
{
    BT* temp = new BT;

    temp->word= data;           //αρχικοποίηση της λέξης με το data
    temp->left = nullptr;       //αρχικοποίηση των παιδιών του κόμβου με null
    temp->right = nullptr;
    temp->freq=1;               //αρχικοποίηση της συχνότητας της λέξης με 1
    return temp;                //επιστροφή του νέου κόμβου
}


string BinaryTree::addWord(string w) //συνάρτηση για εισαγωγή λέξεων στο δένδρο
{

    if(root==nullptr)           //αν η ρίζα είναι null
    {
        root = newBT(w);        //δημιούργησε νέο κόμβο με τη λέξη w
        root->parent= nullptr;   //αρχικοποίηση του πατέρα με null
        return root->word;          //επιστροφή της λέξης της ρίζας
    }
    else                        //αν η ρίζα δεν είναι null
    {
        temp = root;
        while(true)
        {
            if( w < temp->word )   //αν η ζητούμενη λέξη είναι μικρότερη της λέξης του κόμβου temp
            {
                if(temp->left == nullptr)      //αν το αριστερό παιδί του temp είναι null
                {
                    temp->left = newBT(w);      //δημιούργησε νέο κόμβο με τη λέξη w
                    temp->left->parent = temp;   //κάνε πατέρα του το temp
                    return temp->left->word;       //επέστρεψε τη λέξη του temp->left
                }
                temp = temp->left;              //αν το αριστερό παιδί είναι γεμάτο όρισε ως temp το αριστερό παιδί του
            }
            else if(w> temp->word)         //αν η ζητούμενη λέξη είναι μεγλύτερη της λέξης του κόμβου temp
            {
                if(temp->right == nullptr)    //αν το δεξί παιδί του temp είναι null
                {
                    temp->right = newBT(w);     //δημιούργησε νέο κόμβο με τη λέξη w
                    temp->right->parent= temp;   //κάνε πατέρα του το temp
                    return temp->right->word;     //επέστρεψε τη λέξη του temp->right
                }
                temp=temp->right;               //αν το δεξί παιδί είναι γεμάτο όρισε ως temp το δεξί παιδί του
            }
            else                            //αν η ζητούμενη λέξη είναι ίδια με τη λέξη του κόμβου
            {
                temp->freq++;               //αύξησε τη συχνότητα του temp
                return temp->word;          //επέστρεψε τη λέξη του κόμβου temp
            }

        }
    }

}
BT* BinaryTree::findWord(string w)  //συνάρτηση για αναζήτηση λέξεων
{
    temp=root;                      //όρισε το temp με τη ρίζα
    while(true)
    {
        if(temp==nullptr)           //αν βρεθεί σε null κόμβο επέστρεψε null
        {
            return nullptr;
        }

        if(w > temp->word)          //αν η ζητούμενη λέξη είναι μεγαλύτερη από τη λέξη του κόμβου
        {
            temp=temp->right;       //όρισε το temp με το δεξί παιδί του και ψάξε εκεί
        }
        else if (w < temp->word)    //αν η ζητούμενη λέξη είναι μικρότερη από τη λέξη του κόμβου
        {
            temp=temp->left;        //όρισε το temp με το αριστερό παιδί του και ψάξε εκεί
        }
        else                        //αν βρεθεί η λέξη επέστρεψε τον κόμβο που βρέθηκε
        {
            return temp;
        }
    }
}


void BinaryTree::printInorder()     //συνάρτηση για εκτύπωση του δένδρου με Inorder
{
    cout<<"INORDER"<<endl;
    Inorder(root);
}

void BinaryTree::printPostorder()   //συνάρτηση για εκτύπωση του δένδρου με Postorder
{
    cout<<"POSTORDER"<<endl;
    Postorder(root);
}

void BinaryTree::printPreorder()    //συνάρτηση για εκτύπωση του δένδρου με Preorder
{
    cout<<"PREORDER"<<endl;
    Preorder(root);
}

void BinaryTree::Inorder(BT *root)
{
    if (root == NULL)
        return;

        Inorder(root->left);
        cout<<"Word: "<<root->word<<" Times: "<<root->freq<< endl;
        Inorder(root->right);

}

void BinaryTree:: Postorder( BT* root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<"Word: "<< root->word<<" Times: " <<root->freq<<endl;
}

void BinaryTree::Preorder(BT* root)
{
    if (root == NULL)
        return;

    cout<<"Word: "<<root->word<<" Times: "<<root->freq<<endl;
    Preorder(root->left);
    Preorder(root->right);
}

void BinaryTree::deleteWord(string word)    //συνάρτηση για διαγραφή λέξης
{

    temp = findWord(word);                  //κλήση της findWord(word) και αποθήκευση του κόμβου της λέξης στην temp


    if(temp->right== nullptr && temp->left== nullptr)   //1η περίπτωση διαγραφής (ο κόμβος δεν έχει παιδιά)
    {
        if(temp==root)
            root=nullptr;

        else if(temp== temp->parent->left)      //αν ο κόμβος μας είναι αριστερό παιδί
            temp->parent->left = nullptr;       //κάνε null το αριστερό παιδί του πατέρα του temp
        else if (temp == temp->parent->right)   //αν ο κόμβος είναι δεξί παιδί
            temp->parent->right = nullptr;      //κάνε null το δεξί παιδί του πατέρα του temp
        delete temp;                            //διέγραψε τον κόμβο temp

    }
    else if(temp->right == nullptr || temp->left == nullptr)    //2η περίπτωση διαγραφής (ο κόμβος έχει μόνο 1 παιδί)
    {
        if(temp->right== nullptr)       //αν έχει αριστερό παιδί
        {
            if(temp == temp->parent->right) //αν ο κόμβος είναι δεξί παιδί
            {
                temp->parent->right = temp->left;   //όρισε ως δεξί παιδί του πατέρα το αριστερό παιδί του temp
                temp->left->parent =temp->parent;   //όρισε πατέρα του αριστερού παιδιού τον πατέρα του temp
            }
            else if(temp == temp->parent->left)     //αν ο κόμβος είναι αριστερό παιδί
            {
                temp->parent->left = temp->left;     //όρισε ως αριστερό παιδί του πατέρα το αριστερό παιδί του temp
                temp->left->parent = temp->parent;   //όρισε πατέρα του αριστερού παιδιού τον πατέρα του temp
            }

        }
        else if (temp->left == nullptr)     //αν έχει δεξί παιδί
        {

            if(temp == temp->parent->left)      //αν ο κόμβος είναι αριστερό παιδί
            {
                temp->parent->left  = temp->right;      //όρισε ως αριστερό παιδί του πατέρα το δεξί παιδί του temp
                temp->right->parent = temp->parent;     //όρισε πατέρα του δεξιού παιδιού τον πατέρα του temp
            }
            else if(temp == temp->parent->right)        //αν ο κόμβος είναι δεξί παιδί
            {
                temp->parent->right= temp->right;       //όρισε ως δεξί παιδί του πατέρα το δεξί παιδί του temp
                temp->right->parent = temp->parent;     //όρισε πατέρα του δεξιού παιδιού τον πατέρα του temp
            }
        }
        delete temp;                       //διέγραψε τον κόμβο temp
    }
    else if (temp->right!=nullptr && temp->left!=nullptr)  //3η περίπτωση διαγραφής (ο κόμβος έχει 2 παιδιά)
    {
        BT* temp2;
        temp2=temp->left;       //όρισε temp2 το αριστερό παιδί του temp

        while(temp2->right!=nullptr)  //όσο το temp2 έχει δεξί παιδί
        {
            temp2=temp2->right;       //όρισε temp2 το δεξί του παιδί
        }

        if(temp == temp->parent->right)     //αν το temp είναι δεξί παιδί
        {
            temp->parent->right = temp2;    //όρισε δεξί παιδί του parent το temp2
            temp2->parent = temp->parent;   //όρισε πατέρα του temp2 τον πατέρα του temp

             if(temp->left != temp2)        //αν το αριστερό παιδί του temp είναι διάφορο του temp2
             {
                temp -> left ->parent = temp2;  //όρισε πατέρα του αριστερού παιδιού το temp2
                temp2->left = temp->left;       //όρισε αριστερό παιδί του temp2 το αριστερό παιδί του temp
             }

             if(temp->right != temp2)       //αν το δεξί παιδί του temp είναι διάφορο του temp2
             {
                temp->right-> parent = temp2;   //όρισε πατέρα του δεξιού παιδιού το temp2
                temp2->right = temp->right;     //όρισε δεξί παιδί του temp2 το δεξί παιδί του temp
             }

        }
        else if(temp == temp->parent->left)     //αν το temp είναι αριστερό παιδί
        {
            temp->parent->left = temp2;         //όρισε αριστερό παιδί του parent το temp2
            temp2->parent = temp->parent;       //όρισε πατέρα του temp2 τον πατέρα του temp

            if(temp->left != temp2)         //αν το αριστερό παιδί του temp είναι διάφορο του temp2
            {
                temp2->left = temp->left;           //όρισε αριστερό παιδί του temp2 το αριστερό παιδί του temp
                temp -> left ->parent = temp2;      //όρισε πατέρα του αριστερού παιδιού το temp2
            }

            if(temp->right != temp2)            //αν το δεξί παιδί του temp είναι διάφορο του temp2
            {
                temp2->right = temp->right;     //όρισε δεξί παιδί του temp2 το δεξί παιδί του temp
                temp->right-> parent = temp2;   //όρισε πατέρα του δεξιού παιδιού το temp2
            }
        }

        delete temp;        //διέγραψε τον κόμβο temp
    }
}




