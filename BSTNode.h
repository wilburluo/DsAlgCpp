//
// Created by rowe on 2022/3/26.
//

#ifndef DSALGCPP_BSTNODE_H
#define DSALGCPP_BSTNODE_H
#include "BinNode.h"

template<typename Key, typename E>
class BSTNode: public BinNode<E>{
private:
    Key k;
    E it;
    BSTNode* lc;
    BSTNode* rc;

public:
    BSTNode(){lc = rc = nullptr;}
    BSTNode(Key K, E e, BSTNode* l = nullptr, BSTNode* r = nullptr){
       k = K; it = e; lc = l; rc = r;
    }
    ~BSTNode(){}

    E& element(){return it;}
    void setElement(const E& e){it = e;}
    Key& key(){return k;}
    void setKey(const Key& K){k = K;}
    inline BSTNode* left() const {return lc;}
    void setLeft(BinNode<E>* b){lc = (BSTNode*)b;}
    inline BSTNode* right() const {return rc;}
    void setRight(BinNode<E>* b){rc = (BSTNode*)b;}

    bool isLeaf(){return (lc == nullptr) && (rc == nullptr);}
};


#endif //DSALGCPP_BSTNODE_H
