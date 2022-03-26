//
// Created by rowe on 2022/3/25.
//

#ifndef DSALGCPP_BINNODE_H
#define DSALGCPP_BINNODE_H

template<typename E>
class BinNode {
public:
    virtual ~BinNode(){}
    virtual E& element() = 0;
    virtual void setElement(const E&) = 0;
    virtual BinNode* left() const = 0;
    virtual void setLeft(BinNode*) = 0;
    virtual BinNode* right() const = 0;
    virtual void setRight(BinNode*) = 0;
    virtual bool isLeaf() = 0;
};


#endif //DSALGCPP_BINNODE_H
