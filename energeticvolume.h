#ifndef ENERGETICVOLUME_H
#define ENERGETICVOLUME_H

#include <QString>
#include "volume.h"

class EnergeticVolume : public Volume
{
public:
    EnergeticVolume();
    EnergeticVolume(QString _name, QString _weight,
                    QString _fat, QString _proteins,
                    QString _carbonhydrates,
                    QString _acids,QString _ffibers );
    EnergeticVolume (const EnergeticVolume &a);
    ~EnergeticVolume();
    float countVolume();
    void setName(QString _name);
    void setParameters(QString _weight, QString _fat,
                       QString _proteins, QString _carbonhydrates,
                       QString _acids, QString _ffibers);
    QString getName();
    float getWeight();
    float getFat();
    float getProteins();
    float getCarbonhydrates();
    float getAcids();
    float getFfibers();
    void show();
    virtual int getType();
private:
    QString name;
    float weight;
    float fat;
    float proteins;
    float carbonhydrates;
    float acids;
    float ffibers;


};

#endif // ENERGETICVOLUME_H
