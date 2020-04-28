#ifndef _PAIR_HH
#define _PAIR_HH


template<class KeyType, class DataType>
class Pair {
private:
    KeyType key;
    DataType data;
public:
    Pair(const KeyType& key, const DataType& data) {
        this->key = key;
        this->data = data;
    }
    virtual ~Pair() = default;

    virtual const KeyType& first() const {
        return key;
    }
    virtual const DataType& second() const {
        return data;
    }
};

#endif