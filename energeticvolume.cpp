#include "energeticvolume.h"
#include <iostream>

using namespace std;

EnergeticVolume::EnergeticVolume()
{
    name = "Pizza";
    weight = 100;
    fat = 34;
    proteins = 16;
    carbonhydrates = 20;
    acids = 10;
    ffibers = 20;
}

EnergeticVolume::EnergeticVolume(QString _name, QString _weight, QString _fat, QString _proteins, QString _carbonhydrates, QString _acids, QString _ffibers)
{

    EnergeticVolume temp;
    name = _name == "" ? temp.name : _name;
    weight = temp.weight;
    fat = temp.fat;
    proteins = temp.proteins;
    carbonhydrates = temp.carbonhydrates;
    acids = temp.acids;
    ffibers = temp.ffibers;
    setParameters(_weight, _fat, _proteins, _carbonhydrates, _acids, _ffibers);
}

EnergeticVolume::EnergeticVolume(const EnergeticVolume &a)
{
    name = a.name;
    weight = a.weight;
    fat = a.fat;
    proteins = a.proteins;
    carbonhydrates = a.carbonhydrates;
    acids = a.acids;
    ffibers = a.ffibers;
}

EnergeticVolume::~EnergeticVolume()
{

}

int EnergeticVolume::getType()
{
    return 0;
}

void EnergeticVolume::setParameters(QString _weight, QString _fat, QString _proteins, QString _carbonhydrates, QString _acids, QString _ffibers)
{
    bool f = true, F = true;
    float w = -1, fa = -1, p = -1, c = -1, a = -1, ff = -1;
    _weight.toFloat(&f);
    w = f ? _weight.toFloat(&f) : weight;
    _fat.toFloat(&f);
    fa = f ? _fat.toFloat() : fat;
    _proteins.toFloat(&f);
    p = f ? _proteins.toFloat() : proteins;
    _carbonhydrates.toFloat(&f);
    c = f ? _carbonhydrates.toFloat() : carbonhydrates;
    _acids.toFloat(&f);
    a = f ? _acids.toFloat() : acids;
    _ffibers.toFloat(&f);
    ff = f ? _ffibers.toFloat() : ffibers;
    if(w>0) weight = w;
    if(fa>0 && p>0 && c>0 && a>0&& ff>0)
    {
        if(100 >= int(fa + p + c + a + ff))
        {
            fat = fa;
            proteins = p;
            carbonhydrates = c;
            acids = a;
            ffibers = ff;
        }
    }
}

void EnergeticVolume::setName(QString _name)
{
    name = _name =="" ? name : _name;
}

QString EnergeticVolume::getName()
{
    return name;
}

float EnergeticVolume::getWeight()
{
    return weight;
}

float EnergeticVolume::getFat()
{
    return fat;
}

float EnergeticVolume::getProteins()
{
    return proteins;
}

float EnergeticVolume::getCarbonhydrates()
{
    return carbonhydrates;
}

float EnergeticVolume::getAcids()
{
    return acids;
}

float EnergeticVolume::getFfibers()
{
    return ffibers;
}

float EnergeticVolume::countVolume()
{
    return (fat*9.29 + proteins*4.11 + carbonhydrates*4.11 + acids*2.2 +ffibers*1.9)*weight/100;
}

void EnergeticVolume::show()
{
    cout<<"Name: "<<name.toLatin1().data()<<endl;
    cout<<"Weight: "<<weight<<endl;
    cout<<"Fat: "<<fat<<endl;
    cout<<"Proteines: "<<proteins<<endl;
    cout<<"Carbonhydrates: "<<carbonhydrates<<endl;
    cout<<"Acids: "<<acids<<endl;
    cout<<"Food fibers: "<<ffibers<<endl;
    cout<<"Volume: "<<countVolume()<<endl;
    cout<<"--------------------"<<endl;
}
