#include "Stack.cpp"
template<class T> class BTree;

template<class T>
class Node
{
    friend class BTree<T>;
public:
    T data;
    Node<T> *Lchild;
    Node<T> *Rchild;
    bool visited;
    Node(){
        Lchild = 0;
        Rchild = 0;
    }
};

template <class T>
class BTree
{
public:
    BTree(T key);
    void insert(BTree<T> L, BTree<T>D, BTree<T>R);
    Node<T> *root;
    string postorder();

};

template <class T>
BTree<T>::BTree(T key){
    root = new Node<T>;
    Node<T> *L = new Node<T>;
    L->data = key;
    L->Lchild = 0;
    L->Rchild = 0;
    this->root = L;
}

template <class T>
void BTree<T>::insert(BTree<T> L, BTree<T>D, BTree<T>R){
    D.root->Lchild = L.root;
    D.root->Rchild = R.root;
    root = D.root;
}


template<class T>
string BTree<T>::postorder(){
    char output[9];
    int i = 0;
    Stack< Node<T>* > s;
    Node<T> *currentNode =root;
    s.Add(currentNode);
    while(!s.IsEmpty()){
        Node<T> *node = new Node<T>;
        node = *s.peek();
        if( node->Lchild != 0 && node->Lchild->visited == 0){
            s.Add(node->Lchild);
        }
        else{
            if(node->Rchild != 0 && node->Rchild->visited == 0){
                s.Add(node->Rchild);
            }
            else{
                cout << node->data << ends;
                output[i] = node->data;
                i++;
                node->visited = 1;
                s.Delete(node);
            }
        }
    }
    return output;
}




