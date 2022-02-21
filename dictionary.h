//
// Created by Rowe on 2022/2/21.
//

#ifndef DSALGCPP_DICTIONARY_H
#define DSALGCPP_DICTIONARY_H

template<typename Key, typename E>
class Dictionary {
private:
    void operator=(const Dictionary&){}
    Dictionary(const Dictionary&){}

public:
    Dictionary(){}
    virtual ~Dictionary(){}
    virtual void clear() = 0;
    virtual void insert(const Key&, const E&) = 0;
    virtual E remove(const Key&) = 0;
    virtual E removeAny() = 0;
    virtual E find(const Key&) const = 0;
    virtual int size() const = 0;
};


#endif //DSALGCPP_DICTIONARY_H
