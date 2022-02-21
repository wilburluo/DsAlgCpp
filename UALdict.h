//
// Created by Rowe on 2022/2/21.
//

#ifndef DSALGCPP_UALDICT_H
#define DSALGCPP_UALDICT_H

#include "dictionary.h"
#include "KVpair.h"

template<typename Key, typename E>
class UALdict : public Dictionary<Key, E> {
private:
    AList <KVpair<Key, E>> *list;

public:
    UALdict(int size = defaultSize) {
        list = new AList<KVpair<Key, E>>(size);
    }

    ~UALdict() {
        delete list;
    }

    void clear(){
        list->clear();
    }

    void insert(const Key &k, const E &e) {
        KVpair<Key, E> temp(k, e);
        list->append(temp);
    }

    E remove(const Key &k) {
        E temp = find(k);
        if (temp != nullptr) list->remove();
        return temp;
    }

    E removeAny() { // Remove the last element
        Assert(size() != 0, "Dictionary is empty");
        list->moveToEnd();
        list->prev();
        KVpair<Key,E> e = list->remove();
        return e.value();
    }

    E find(const Key& k) const {
        for(list->moveToStart(); list->currPos()<list->length(); list->next()){
            KVpair<Key,E> temp = list->getValue();
            if(k == temp.key())
                return temp.value();
        }
        return nullptr;
    }

    int size() const {return list->length();}
};

#endif //DSALGCPP_UALDICT_H
