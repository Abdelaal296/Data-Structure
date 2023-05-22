#include "Matrix.h"
void menu();
template<class T2>
class MatrixCalculator {
public:
    Matrix<T2> ob9 ;
    void  calc(){
        cout << "Welcome to Matrix Calculator" << endl ;
        cout << "---------------------------------" << endl ;
        while (true){
            int pro  ;
            int r , c ;
            menu();
            cin>> pro ;
            if (pro==1) {

                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob(r , c);
                cout <<"Enter Matrix no.1 "<<endl;
                cin>>ob;
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob1(r , c);
                cout <<"Enter Matrix no.2 "<<endl;
                cin>>ob1;
                Matrix<T2> res = ob + ob1 ;
                cout<<res<<endl ;
            }

            else if (pro==2) {
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob(r , c);
                cout <<"Enter Matrix no.1 "<<endl;
                cin>>ob;
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob1(r , c);
                cout <<"Enter Matrix no.2 "<<endl;
                cin>>ob1;
                Matrix<T2> res = ob - ob1 ;
                cout<<res<<endl ;
            }
            else if (pro==3) {
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob(r , c);
                cout <<"Enter Matrix no.1 "<<endl;
                cin>>ob;
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob1(r , c);
                cout <<"Enter Matrix no.2 "<<endl;
                cin>>ob1;
                Matrix<T2> res = ob * ob1 ;
                cout<<res<<endl ;

            }
            else if (pro==4) {
                cout<<"Enter number of rows and cols"<<endl ;
                cin>>r >> c ;
                Matrix<T2> ob(r , c);
                cout <<"Enter Matrix no.1 "<<endl;
                cin>>ob;
                Matrix<T2> res = ob9.transpose(ob);
                cout << res << endl << endl;
            }
            else if (pro==0)
                break;

        }

    }


};
void menu(){
    cout<<"1- Perform Matrix Addition\n"
          "2- Perform Matrix Subtraction\n"
          "3- Perform Matrix Multiplication\n"
          "4- Matrix Transpose\n"
          "0-off"<< endl ;
}