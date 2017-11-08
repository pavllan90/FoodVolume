#ifndef COMPLEX_H
#define COMPLEX_H

#include "volume.h"
#include "energeticvolume.h"
#include <iostream>

using namespace std;

class Complex : public Volume
{
public:
    Complex();
    Complex(EnergeticVolume _dish1, EnergeticVolume _dish2, EnergeticVolume _dish3, EnergeticVolume _dish4);
    Complex(EnergeticVolume _dish1, EnergeticVolume _dish2, EnergeticVolume _dish3);
    Complex(const Complex& a);
    ~Complex();
    EnergeticVolume dish1;
    EnergeticVolume dish2;
    EnergeticVolume dish3;
    EnergeticVolume dish4;
    bool hasDessert;
    float volume;
    virtual void show();
    virtual int getType();

};

#endif // COMPLEX_H
