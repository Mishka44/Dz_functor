#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <Windows.h>


class Function {
public:
    virtual double operator ()(double a, double b)const = 0;
    double Get_argsA(){
        return this->argsA;
    }
    double Get_argsB() {
        return this->argsB;
    }
    void Set_argsA(double tmp) {
        this->argsA = tmp;
    }
    void Set_argsB(double tmp) {
        this->argsB = tmp;
    }

private:
    double argsA;
    double argsB;
};

class lengthOfPath: public Function{
public:
    double operator ()(double v, double t)const override {
        auto Length = v * t;
        auto presc = ::pow(10, prescition);
        Length = ::round(Length * presc) / presc;

        auto tmp = const_cast<lengthOfPath*>(this);

        tmp->Set_argsA(v);
        tmp->Set_argsB(t);
        return Length;
    }


    void Prescition(int val) {
        prescition = val;
    }

private:
    int prescition;
};

class RotSpeed:public  Function{
public:
    double operator ()(double r, double n)const override {
        auto Speed = 2*pi*r*n;
        auto presc = ::pow(10, prescition);
        Speed = ::round(Speed * presc) / presc;

        auto tmp = const_cast<RotSpeed*>(this);

        tmp->Set_argsA(r);
        tmp->Set_argsB(n);

        return Speed;
    }
    void Prescition(int val) {
        prescition = val;
    }

private:
    int prescition;
    double pi = 3.14;

};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    lengthOfPath obj;
    obj.Prescition(6);

    std::cout << "путь, пройденный на скорости 3,58 м/c за 14,678 секунд: " << obj.operator()(3.58 , 14.678) << " метров ( точность = 6)\n\n";

    RotSpeed obj2;
    obj2.Prescition(7);

    std::cout << "скорость при вращении с радиусом 3 метра за 3.46 секунды: " << obj2.operator()(3, 3.46) << " метров в секунду (точность вычислений  = 7)\n";


    return 0;
}


