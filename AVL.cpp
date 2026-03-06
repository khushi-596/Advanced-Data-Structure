#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
    int key;
    node *left, *right, *parent;
    int bf;
};

class AVL{
    node *root;

private:

    int max(int a,int b){
        return (a>b)?a:b;
    }

    int height(node *p){
        if(!p)
            return -1;
        return 1 + max(height(p->left), height(p->right));
    }

    node *imbalance(node *p){
        while(p){
            if(p->bf == 2 || p->bf == -2)
                return p;
            p = p->parent;
        }
        return NULL;
    }

    void LL(node *i){

        node *iL = i->left;
        node *iLR = iL->right;
        node *iP = i->parent;

        if(!iP){
            root = iL;
            iL->parent = NULL;
        }
        else{
            iL->parent = iP;
            if(iP->left == i)
                iP->left = iL;
            else
                iP->right = iL;
        }

        iL->right = i;
        i->parent = iL;

        i->left = iLR;
        if(iLR)
            iLR->parent = i;
    }

    void RR(node *i){

        node *iR = i->right;
        node *iRL = iR->left;
        node *iP = i->parent;

        if(!iP){
            root = iR;
            iR->parent = NULL;
        }
        else{
            iR->parent = iP;
            if(iP->left == i)
                iP->left = iR;
            else
                iP->right = iR;
        }

        iR->left = i;
        i->parent = iR;

        i->right = iRL;
        if(iRL)
            iRL->parent = i;
    }

    void LR(node *i){
        RR(i->left);
        LL(i);
    }

    void RL(node *i){
        LL(i->right);
        RR(i);
    }

    // recompute BF for all nodes
    void update_all_bf(node *p){
        if(!p) return;
        update_all_bf(p->left);
        p->bf = height(p->left) - height(p->right);
        update_all_bf(p->right);
    }

    void updateBF(node *p){

        node *temp = p;

        while(p){
            p->bf = height(p->left) - height(p->right);
            p = p->parent;
        }

        node *i = imbalance(temp);

        if(!i)
            return;

        cout<<"\nBefore Rotation (Inorder with BF):\n";
        inorder();

        cout<<"\nImbalance Node = "<<i->key<<"  BF = "<<i->bf<<endl;

        if(temp->key < i->key && temp->key < i->left->key){
            cout<<"\nLL Rotation\n";
            LL(i);
        }

        else if(temp->key > i->key && temp->key > i->right->key){
            cout<<"\nRR Rotation\n";
            RR(i);
        }

        else if(temp->key < i->key && temp->key > i->left->key){
            cout<<"\nLR Rotation\n";
            LR(i);
        }

        else if(temp->key > i->key && temp->key < i->right->key){
            cout<<"\nRL Rotation\n";
            RL(i);
        }

        // recompute BF for whole tree
        update_all_bf(root);

        cout<<"\nAfter Rotation (Inorder with BF):\n";
        inorder();

        cout<<"\nBalanced Height = "<<treeHeight()<<endl;
    }

    void inorder_rec(node *p){
        if(!p) return;
        inorder_rec(p->left);
        cout<<p->key<<" BF:"<<p->bf<<endl;
        inorder_rec(p->right);
    }

public:

    AVL(){
        root = NULL;
    }

    void insert(int data){

        node *nn = new node;

        nn->key = data;
        nn->left = nn->right = NULL;
        nn->parent = NULL;
        nn->bf = 0;

        if(!root){
            root = nn;
            return;
        }

        node *ptr = root;

        while(ptr){

            if(data == ptr->key){
                delete nn;
                return;
            }

            if(data < ptr->key){

                if(ptr->left==NULL){
                    ptr->left = nn;
                    nn->parent = ptr;
                    updateBF(nn);
                    return;
                }

                ptr = ptr->left;
            }

            else{

                if(ptr->right==NULL){
                    ptr->right = nn;
                    nn->parent = ptr;
                    updateBF(nn);
                    return;
                }

                ptr = ptr->right;
            }
        }
    }

    void inorder(){
        inorder_rec(root);
    }

    int treeHeight(){
        return height(root);
    }
};

int main(){

    AVL t;

    int n;

    cout<<"Enter number of nodes: ";
    cin>>n;

    srand(time(0));

    cout<<"\nRandom Numbers Inserted:\n";

    for(int i=0;i<n;i++){

        int x = rand()%100;

        cout<<x<<" ";

        t.insert(x);
    }

    cout<<"\n\nFinal Inorder Traversal\n";
    t.inorder();

    cout<<"\nHeight = "<<t.treeHeight()<<endl;

    return 0;
}
