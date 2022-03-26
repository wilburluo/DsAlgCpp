//
// Created by rowe on 2022/3/26.
//

#ifndef DSALGCPP_BST_H
#define DSALGCPP_BST_H
#include "BSTNode.h"
#include "dictionary.h"

template<typename Key, typename E>
class BST: public Dictionary<Key,E>{
private:
    BSTNode<Key, E>* root;
    int nodecount;

    void clearhelp(BSTNode<Key, E>*);
    BSTNode<Key, E>* inserthelp(BSTNode<Key,E>*, const Key&, const E&);
    BSTNode<Key, E>* deletemin(BSTNode<Key,E>*);
    BSTNode<Key, E>* getmin(BSTNode<Key,E>*);
    BSTNode<Key, E>* removehelp(BSTNode<Key,E>*, const Key&);
    E findhelp(BSTNode<Key,E>*, const Key&) const;
    void printhelp(BSTNode<Key, E>*, int) const;

public:
    BST(){root = nullptr; nodecount = 0;}
    ~BST(){ clearhelp(root);}

    void clear(){
        clearhelp(root);
        root = nullptr;
        nodecount = 0;
    }

    void insert(const Key& k, const E& e) {
        root = inserthelp(root, k, e);
        nodecount++;
    }

    E remove(const Key& k) {
        E temp = findhelp(root, k);   // First find it
        if (temp != nullptr) {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }

    E removeAny() {  // Delete min value
        if (root != nullptr) {
            E temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else return nullptr;
    }

    E find(const Key& k) const { return findhelp(root, k); }

    // Return the number of records in the dictionary.
    int size() { return nodecount; }

    void print() const { // Print the contents of the BST
        if (root == nullptr) cout << "The BST is empty.\n";
        else printhelp(root, 0);
    }

    int size() const{
        return nodecount;
    }
};

template<typename Key, typename E>
void BST<Key, E>::
clearhelp(BSTNode<Key,E>* root){
    if(root == nullptr) return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

template<typename Key, typename E>
BSTNode<Key,E>* BST<Key,E>::inserthelp(
        BSTNode<Key, E>* root, const Key &k, const E & it) {
    if(root == nullptr)
        return new BSTNode<Key, E>(k, it, nullptr, nullptr);
    if(k < root->key())
        root->setLeft(inserthelp(root->left(), k, it));
    else
        root->setRight(inserthelp(root->right(), k, it));
    return root;
}

template<typename Key, typename E>
BSTNode<Key, E>* BST<Key,E>::getmin(BSTNode<Key, E> * rt) {
    if(rt->left()== nullptr)
        return rt;
    else
        return getmin(rt->left());
}

template<typename Key, typename E>
BSTNode<Key,E>* BST<Key,E>::deletemin(BSTNode<Key, E> *rt) {
    if(rt->left() == nullptr)
        return rt->right();
    else{
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}

template<typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::removehelp(BSTNode<Key, E> *rt, const Key &k) {
    if(rt == nullptr)
        return rt;
    else if(k < rt->key())
        rt->setLeft(removehelp(rt->left(), k));
    else if(k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else{
        BSTNode<Key, E>* temp = rt;
        if(rt->left() == nullptr){
            rt = rt->right();
            delete temp;
        }
        else if(rt->right() == nullptr){
            rt = rt->left();
            delete temp;
        } else{
            BSTNode<Key, E>* temp = getmin(rt->right());
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            delete temp;
        }
    }
    return rt;
}

template<typename Key, typename E>
E BST<Key,E>::findhelp(BSTNode<Key, E> *rt, const Key &k) const {
    if(rt == nullptr)
        return nullptr;
    if(k < rt->key())
        return findhelp(rt->left(), k);
    else if(k > rt->key())
        return findhelp(rt->right(), k);
    else return rt->element();
}

template<typename Key, typename E>
void BST<Key,E>::printhelp(BSTNode<Key, E> *rt, int level) const {
    if(rt == nullptr)
        return;
    printhelp(rt->left(), level+1);
    for(int i = 0; i < level; i++)
        cout << " ";
    cout << rt->key() << "\n";
    printhelp(rt->right(), level+1);
}

#endif //DSALGCPP_BST_H
