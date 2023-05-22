#include "Fraction.h"
void menu();
class FractionCalculator{
public:
    Fraction num1 , num2 ;
    void  calc(){
        cout<<"Welcome to Fraction Calculator"<<endl ;
        cout <<"Enter two fractions" << endl ;
        cin >> num1 >> num2 ;
        while (true){
            int pro  ;
            menu();
            cin>> pro ;
            if (pro==1) {

                Fraction res(num1 + num2);
                cout << res<< endl;
            }

            else if (pro==2) {
                Fraction res(num1 - num2);
                cout << res << endl;
            }
            else if (pro==3) {
                Fraction res(num1 * num2);
                cout << res << endl;

            }
            else if (pro==4) {
                Fraction res(num1 / num2);
                cout << res << endl;
            }
            else if (pro==0)
                break;


        }

    }



};
void menu(){
    cout<<"0-Exit"<<endl
        <<"1-Addition"<<endl
        <<"2-subtraction"<<endl
        <<"3-multiplication"<<endl
        <<"4-Division"<<endl;
}
