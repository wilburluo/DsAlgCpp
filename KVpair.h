//
// Created by Rowe on 2022/2/21.
//

#ifndef DSALGCPP_KVPAIR_H
#define DSALGCPP_KVPAIR_H

template<typename Key, typename E>
class KVpair {
private:
    Key k;
    E e;
public:
    KVpair() {}

    KVpair(Key kval, E eval) {
        k = kval;
        e = eval;
    }

    KVpair(const KVpair &o) {
        k = o.k;
        e = o.e;
    }

    ~KVpair() {}

    void operator=(const KVpair &o) {
        k = o.k;
        e = o.e;
    }

    Key key() {
        return k;
    }

    void setKey(Key ink) {
        k = ink;
    }

    E value() { return e; }

};

#endif //DSALGCPP_KVPAIR_H
