#include "AVLtree.h"
#include <bits/stdc++.h>


AVLtree::AVLtree()      //Constructor
{
    root = nullptr;     //αρχικοποίηση του root με null
}

AVLtree::~AVLtree()
{
    //dtor
}
AVL* AVLtree:: newAVL(string data)  //συνάρτηση για δημιουργία νέου struct AVL
{
    AVL* temp = new AVL;

    temp->word= data;       //αρχικοποίηση της λέξης με το data
    temp->left = nullptr;   //αρχικοποίηση των παιδιών του κόμβου με null
    temp->right = nullptr;
    temp->freq=1;           //αρχικοποίηση της συχνότητας της λέξης με 1
    temp->height=1;         //αρχικοποίηση του ύψους με 1

    return temp;            //επιστροφή του νέου κόμβου
}



int AVLtree:: getHeight(AVL *a)     //συνάρτηση υπολογισμού ύψους κόμβου
{
    if(a->left!=nullptr && a->right!=nullptr) //αν ο κόμβος έχει 2 παιδιά
    {
        if (a->left->height < a->right->height) //αν το αριστερό ύψος είναι μικρότερο του δεξιού ύψους
            return (a->right->height + 1);      //επέστρεψε το δεξί ύψος +1
        else
            return  (a->left->height + 1);      //διαφορετικά επέστρεψε το αριστερό ύψος +1
    }
    else if(a->left!=nullptr && a->right == nullptr) //αν έχει μόνο αριστερό παιδί
    {
        return (a->left->height + 1);               //επέστρεψε το αριστερό ύψος +1
    }
    else if(a->left ==nullptr && a->right!=nullptr) //αν έχει μόνο δεξί παιδί
    {
        return (a->right->height + 1);              //επέστρεψε το δεξί ύψος +1
    }
    return 0;

}

int AVLtree:: getBalance(AVL *a)        //συνάρτηση για υπολογισμό του balance factor
{
    if(a->left!=nullptr && a->right!=nullptr)   //αν ο κόμβος a έχει 2 παιδιά
    {
        return (a->left->height - a->right->height);    //επέστρεψε τη διαφορά των ύψων
    }
    else if(a->left != nullptr && a->right == nullptr)  //αν ο κόμβος έχει μόνο αριστερό παιδί
    {
        return (a->left->height);                       //επέστρεψε το ύψος του αριστερού παιδιού
    }
    else if(a->left == nullptr && a->right!=nullptr )   //αν ο κόμβος έχει μόνο δεξί παιδί
    {
        return (-a->right->height);                     //επέστρεψε το ύψος του δεξιού παιδιού με αρνητικό πρόσημο
    }

}

AVL* AVLtree:: rrRotate(AVL *a)     //right right περιστροφή
{
    AVL *t;

    t = a->right;       //όρισε το t με το δεξί παιδί του a
    a->right = t->left; //όρισε το δεξί παιδί με το αριστερό παιδί του t
    t->left = a;        //όρισε το αριστερό παιδί του t με a

    return t;           //επέστρεψε τον κόμβο t
}

AVL* AVLtree:: llRotate(AVL *a) //left left περιστροφή
{
    AVL *t;
    t = a->left;    //όρισε το t με το αριστερό παιδί του a
    a->left = t->right; //όρισε το αριστερό παιδί του a με το δεξί παιδί του t
    t->right = a;       //όρισε το δεξί παιδί του t με a

    return t;           //επέστρεψε τον κόμβο t
}

AVL* AVLtree:: rlRotate(AVL *a) //right left περιστροφή
{

    AVL *t;
    AVL *t2;

    t = a->right;           //όρισε το t με το δεξί παιδί του a
    t2 =a->right->left;   //όρισε το t2 με το αριστερό παιδί του δεξιού παιδιού του a
    a-> right = t2->left; //όρισε το δεξί παιδί του a με το αριστερό παιδί του t2
    t ->left = t2->right;   //όρισε το αριστερό παιδί του t με το δεξί παιδί του t2
    t2 ->left = a;          //όρισε το αριστερό παιδί του t2 με a
    t2->right = t;          //όρισε το δεξί παιδί του t2 με t

    return t2;              //επέστρεψε τον κόμβο t2
}


AVL* AVLtree:: lrRotate(AVL *a)  //left right περιστροφή
{

    AVL *t;
    AVL *t2;

    t = a->left;            //όρισε το t με το αριστερό παιδί του a
    t2 =a->left->right;     //όρισε το t2 με το δεξί παιδί του αριστερού παιδιού του a
    a -> left = t2->right;  //όρισε το αριστερό παιδί του a με το δεξί παιδί του t2
    t ->right = t2->left;   //όρισε το δεξί παιδί του t με το αριστερό παιδί του t2
    t2 ->right = a;         //όρισε το δεξί παιδί του t2 με a
    t2->left = t;           //όρισε το αριστερό παιδί του t2 με t

    return t2;              //επέστρεψε τον κόμβο t2
}

void AVLtree:: addWord(string w) //συνάρτηση για κλήση της αναδρομικής insertion
{
   root=insertion(root,w);
}

AVL* AVLtree::insertion(AVL* r,string w)  //συνάρτηση εισαγωγής λέξεων
{
    if(r==nullptr)                      //αναδρομική εισαγωγή λέξεων στο δένδρο
    {
        r=newAVL(w);                    //αν το r είναι null δημιούργησε νέο κόμβο με τη λέξη w
        return r;                       //επέστρεψε τον κόμβο
    }
    else
    {
        if(w < r->word)                 //αν η λέξη είναι μικρότερη από τη λέξη του κόμβου κάνε αναδρομικά εισαγωγή στο αριστερό παιδί του r
            r->left = insertion(r->left,w);
        else if(w > r->word)            //αν η λέξη ειναι μεγαλύτερη κάνε αναδρομικά εισαγωγή στο δεξί παιδι του r
            r->right = insertion(r->right,w);
        else                            //αν η λέξη είναι ίδια αύξησε τη συχνότητά της κατά 1
            r->freq++;
    }

        r->height = getHeight(r);       //ενημέρωσε το ύψος του κόμβου μέσω της συνάρτησης getHeight

        //έλεγχος για το αν ικανοποιείται ο περιορισμός του AVL
        if(getBalance(r)==2 && getBalance(r->left)==1) //αν ο balance factor(bf) του r είναι 2 και ο bf του αριστερού παιδιού είναι 1
        {
            r = llRotate(r);                            //εκτέλεσε left left περιστροφή
        }
        else if(getBalance(r)==-2 && getBalance(r->right)==-1) //αν ο bf του r είναι -2 και ο bf του δεξιού παιδιού είναι -1
        {
            r = rrRotate(r);                                //εκτέλεσε right right περιστροφή
        }
        else if(getBalance(r)==-2 && getBalance(r->right)==1) //αν ο bf του r είναι -2 και ο bf του δεξιού παιδιού είναι 1
        {
            r = rlRotate(r);                                    //εκτέλεσε right left περιστροφή
        }
        else if(getBalance(r)==2 && getBalance(r->left)==-1)    //αν ο bf του r είναι 2 και ο bf του αριστερού παιδιού είναι -1
        {
            r = lrRotate(r);                                    //εκτέλεσε left right περιστροφή
        }

        return r;                                               //επέστρεψε τον κόμβο
}

AVL* AVLtree::findWord(string w)        //συνάρτηση αναζήτησης λέξης
{
    temp=root;                          //όρισε το temp με τη ρίζα
    while(true)
    {
        if(temp==nullptr)               //αν βρεθεί σε null κόμβο επέστρεψε null
        {
            return nullptr;
        }

        if(w > temp->word)              //αν η ζητούμενη λέξη είναι μεγαλύτερη από τη λέξη του κόμβου
        {
            temp=temp->right;           //όρισε το temp με το δεξί παιδί του και ψάξε εκεί
        }
        else if (w < temp->word)        //αν η ζητούμενη λέξη είναι μικρότερη από τη λέξη του κόμβου
        {

            temp=temp->left;            //όρισε το temp με το αριστερό παιδί του και ψάξε εκεί
        }
        else                            //αν βρεθεί η λέξη επέστρεψε τον κόμβο που βρέθηκε
        {
            return temp;
        }

    }
}

void AVLtree::printInorder()    //συνάρτηση για εκτύπωση του δένδρου με Inorder
{
    cout<<"INORDER"<<endl;
    Inorder(root);
}

void AVLtree::printPostorder()  //συνάρτηση για εκτύπωση του δένδρου με Postorder
{
    cout<<"POSTORDER"<<endl;
    Postorder(root);
}

void AVLtree::printPreorder()   //συνάρτηση για εκτύπωση του δένδρου με Preorder
{
    cout<<"PREORDER"<<endl;
    Preorder(root);
}

void AVLtree::Inorder(AVL *root)
{
    if (root == NULL)
        return;

        Inorder(root->left);
        cout<<"Word: "<<root->word<<" Times: "<<root->freq<< endl;
        Inorder(root->right);

}

void AVLtree:: Postorder(AVL *root)
{
    if (root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<"Word: "<< root->word<<" Times: " <<root->freq<<endl;
}

void AVLtree::Preorder(AVL *root)
{
    if (root == NULL)
        return;

    cout<<"Word: "<<root->word<<" Times: "<<root->freq<<endl;
    Preorder(root->left);
    Preorder(root->right);
}

void AVLtree::deleteWord(string word)   //συνάρτηση διαγραφής λέξης
{
    temp = findWord(word);              //κλήση της findWord(word) και αποθήκευση του κόμβου της λέξης στην temp

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
        if(temp->right== nullptr)                           //αν έχει αριστερό παιδί
        {
            if(temp == temp->parent->right)                 //αν ο κόμβος είναι δεξί παιδί
            {
                temp->parent->right = temp->left;           //όρισε ως δεξί παιδί του πατέρα το αριστερό παιδί του temp
                temp->left->parent =temp->parent;           //όρισε πατέρα του αριστερού παιδιού τον πατέρα του temp
            }
            else if(temp == temp->parent->left)             //αν ο κόμβος είναι αριστερό παιδί
            {
                temp->parent->left = temp->left;            //όρισε ως αριστερό παιδί του πατέρα το αριστερό παιδί του temp
                temp->left->parent = temp->parent;          //όρισε πατέρα του αριστερού παιδιού τον πατέρα του temp
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
        AVL* temp2;
        temp2=temp->left;       //όρισε ως temp2 το αριστερό παιδί του temp

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

        //έλεγχος για το αν μετά τη διαγραφή το δένδρο είναι ακόμα ισορροπημένο
        //αν δεν είναι κάνει τις κατάλληλες περιστροφές
        if(getBalance(temp)==2 && getBalance(temp->left)==1)
            temp = llRotate(temp);
        else if(getBalance(temp)==2 && getBalance(temp->left)==-1)
            temp = lrRotate(temp);
        else if(getBalance(temp)==2 && getBalance(temp->left)==0)
            temp = llRotate(temp);
        else if(getBalance(temp)==-2 && getBalance(temp->right)==-1)
            temp = rrRotate(temp);
        else if(getBalance(temp)==-2 && getBalance(temp->right)==1)
            temp = rlRotate(temp);
        else if(getBalance(temp)==-2 && getBalance(temp->right)==0)
            temp = llRotate(temp);


}


