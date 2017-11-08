#include "complex.h"

Complex::Complex()
{
    dish1 = EnergeticVolume("Borsch", "233", "11", "20", "10", "10", "5");
    dish2 = EnergeticVolume("Pizza", "250", "20", "11", "15", "5", "2");
    dish3 = EnergeticVolume("Compot", "100", "20", "20", "1", "1", "5");
    dish4 = EnergeticVolume("Cacke", "200", "30", "10", "10", "11", "22");
    hasDessert = true;
    volume = 0;
    volume = dish1.countVolume()+dish2.countVolume()+dish3.countVolume()+dish4.countVolume();
}

Complex::Complex(EnergeticVolume _dish1, EnergeticVolume _dish2, EnergeticVolume _dish3, EnergeticVolume _dish4) :
    dish1(_dish1), dish2(_dish2), dish3(_dish3), dish4(_dish4) { hasDessert = true; volume = _dish1.countVolume()+_dish2.countVolume()+_dish3.countVolume()+_dish4.countVolume(); }

Complex::Complex(EnergeticVolume _dish1, EnergeticVolume _dish2, EnergeticVolume _dish3) : dish1(_dish1), dish2(_dish2), dish3(_dish3), hasDessert(false) { volume = _dish1.countVolume()+_dish2.countVolume()+_dish3.countVolume(); }

Complex::Complex(const Complex &a) : dish1(a.dish1), dish2(a.dish2), dish3(a.dish3), dish4(a.dish4), volume(a.volume) {}

Complex::~Complex() { }

void Complex::show()
{
    cout<<endl<<"Complex dinner"<<endl<<endl;
    dish1.show();
    dish2.show();
    dish3.show();
    if(hasDessert)
        dish4.show();
    cout<<"Complex volume: "<<volume<<endl<<"++++++++++++"<<endl;

}

int Complex::getType()
{
    return 1;
}
