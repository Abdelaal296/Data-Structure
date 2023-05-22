#include <iostream>
using namespace std;
class Fraction{
private:
    int numerator ;
    int denominator ;
public:
    Fraction(){
        numerator = 0 ;
        denominator =0 ;
    }
    Fraction(int n , int d){
        numerator = n ;
        denominator = d ;
    }
    void reduce () {
        while (true) {
            if (numerator % 2 == 0 && denominator % 2 == 0) {
                numerator = numerator / 2;
                denominator = denominator / 2;
            } else if (numerator % 3 == 0 && denominator % 3 == 0) {
                numerator = numerator / 3;
                denominator = denominator / 3;
            }
            else
                break;

        }
    }
    Fraction operator+(const Fraction&ob1){
        Fraction res ;
        if(denominator==ob1.denominator) {
            res.numerator=numerator+ ob1.numerator;
            res.denominator=ob1.denominator;
        }
        else{
            res.denominator = denominator * ob1.denominator;
            res.numerator = numerator * ob1.denominator + denominator * ob1.numerator;
        }
        res.reduce();
        return res ;

    }
    Fraction operator-(const Fraction&ob2){
        Fraction res ;
        if(denominator==ob2.denominator){
            res.numerator=numerator-ob2.numerator ;
            res.denominator=ob2.denominator;
        }
        else {
            res.denominator = denominator * ob2.denominator;
            res.numerator = numerator * ob2.denominator - denominator * ob2.numerator;
        }
        res.reduce();
        return res ;

    }
    Fraction operator* (const Fraction& ob3 ){

        Fraction res ;
        res.numerator=numerator*ob3.numerator ;
        res.denominator=denominator*ob3.denominator ;
        res.reduce();
        return res ;

    }
    Fraction operator/ (const Fraction& ob4 ){

        Fraction res ;
        res.numerator=numerator*ob4.denominator ;
        res.denominator=denominator*ob4.numerator ;
        res.reduce();
        return res ;

    }
    bool operator>(const Fraction &ob5)
    {
        bool status;
        if (numerator/denominator > ob5.numerator/ob5.denominator)
            status = true;
        else
            status = false;
        return status;
    }
    bool operator<(const Fraction &ob5)
    {
        bool status;
        if (numerator/denominator < ob5.numerator/ob5.denominator)
            status = true;
        else
            status = false;
        return status;
    }
    bool operator>=(const Fraction &ob5)
    {
        bool status;
        if (numerator/denominator >= ob5.numerator/ob5.denominator)
            status = true;
        else
            status = false;
        return status;
    }
    bool operator<=(const Fraction &ob6)
    {
        bool status;
        if (numerator/denominator <= ob6.numerator/ob6.denominator)
            status = true;
        else
            status = false;
        return status;
    }

    bool operator==(const Fraction &ob7){
        bool status ;
        if(numerator==ob7.numerator && denominator==ob7.denominator)
            status = true;
        else
            status = false;
        return status;

    }
    bool operator!=(const Fraction &ob8){
        bool status ;
        if(numerator==ob8.numerator && denominator==ob8.denominator)
            status = false;
        else
            status = true;
        return status;

    }


    friend istream &operator>>( istream & input ,Fraction & ob9);
    friend ostream &operator<<(ostream & output, const Fraction & ob) ;

};



istream &operator>>( istream & input ,Fraction & ob9) {

    cout << "Enter numerator" << endl;
    input >> ob9.numerator;
    cout << "Enter denominator" << endl;
    input >> ob9.denominator;
    ob9.reduce();
    return input;
}
ostream &operator<<(ostream & output, const Fraction & ob){

    if(ob.denominator==0)
        cout<<"wrong value,cannot divide by 0"<<endl ;
    else if (ob.numerator==0)
        cout<<0<<endl ;
    else
        cout<<ob.numerator<<"/"<<ob.denominator<<endl ;
    return output;
}
