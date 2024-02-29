#include <iostream>
#include <cstdint>

class Fraction{
private:
    int32_t _num;
    uint32_t _denom;
public:
    Fraction(); //Конструктор по умолчанию
    Fraction(int32_t num, uint32_t denom); // Конструктор с параметрами
    Fraction(const Fraction& fraction);
    //ДЗ1-Лаба
    Fraction(double realFract);
    Fraction(const Fraction& fract){
        std::cout<<"Copy constructor" << this << std::endl;
    }
    //ДЗ2-Лаба
    void Reduce();

    //Сеттеры
    void SetNum(int32_t newNum);
    void SetDenom(uint32_t newDenom);
    //Геттеры
    inline int32_t GetNum(){
        return _num;
    }
    inline uint32_t GetDenom(){
        return _denom;
    }

    //Печать
    inline void PrintDouble(){
        std::cout << static_cast<double>(_num) / _denom << std::endl;
    }

    //Перегрузка операции вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const Fraction& tmp){
        os << tmp._num << "/" << tmp._denom << std::endl;
        return os;
    }
    //Перезагрузка операции сложения
    Fraction operator+(Fraction fraction) const{
        int32_t new_num=_num*fraction._denom
        + fraction._num*_denom;
        uint32_t new_denum=_denom*fraction._denom;
        return Fraction(new_num, new_denum);
    }


};

