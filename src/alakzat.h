#ifndef ALAKZAT_H_INCLUDED
#define ALAKZAT_H_INCLUDED

#include "rajzolas.h"

class Alakzat {
protected:
    Color szin;
    virtual void rajzol() = 0;
public:
    virtual ~Alakzat() {}
};

#endif // ALAKZAT_H_INCLUDED
