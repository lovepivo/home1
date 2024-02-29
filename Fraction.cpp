#include "Fraction.h"

void Fraction::SetDenom(uint32_t newDenom){
    if (newDenom == 0)
        throw "Divide by zero!";
    _denom = newDenom;
}

void Fraction::SetNum(int32_t newNum){
    _num = newNum;
}

Fraction::Fraction(){
    _num = 0;
    _denom = 1;
}

Fraction::Fraction(int32_t num, uint32_t denom){
    _num = num;
    SetDenom(denom);
}

Fraction::Fraction(const Fraction& fraction){
    _num = fraction._num;
    _denom = fraction._denom;
}