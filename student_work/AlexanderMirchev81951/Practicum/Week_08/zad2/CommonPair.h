#ifndef _COMMONPAIR_HH
#define _COMMONPAIR_HH

#include "Pair.h"

class CommonPair: public Pair<int ,double> {
public:
    CommonPair(const int key, const double data): Pair<int, double>(key, data) {}
};

#endif
