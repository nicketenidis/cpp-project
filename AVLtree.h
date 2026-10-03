#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>

using namespace std;

struct AVL  //δημιουργία struct AVL
{                   //κάθε κόμβος περιέχει
    string word;    //μία λέξη
    int freq;       //μία μεταβλητή για υπολογισμό της συχνότητας,
    int height;     //μία μεταβλητή για το ύψος του δένδρου,
    AVL *left, *right;  //αριστερό και δεξί παιδί τύπου struct AVL
    AVL* parent;        //πατέρα τύπου AVL
};

class AVLtree
{
    public:
        AVLtree();
        virtual ~AVLtree();
        AVL* newAVL(string);
        void addWord(string);
        int getHeight(AVL*);
        int getBalance(AVL*);
        AVL* rrRotate(AVL*);
        AVL* llRotate(AVL*);
        AVL* lrRotate(AVL*);
        AVL* rlRotate(AVL*);
        AVL* findWord(string);
        void Inorder(AVL*);
        void Preorder(AVL*);
        void Postorder(AVL*);
        void printInorder();
        void printPostorder();
        void printPreorder();
        void deleteWord(string);

        AVL *insertion(AVL*,string);





    protected:

    private:
        AVL *root;
        AVL *temp;
};

#endif // AVLTREE_H
