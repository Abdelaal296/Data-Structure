#include <iostream>
#include <algorithm>
using namespace std;
template<class T>
class Matrix {
protected:
    T**arr ;
    int row , col ;
public :
    Matrix<T>(){}
    Matrix<T>( int r ,  int c ){
        row= r ;
        col=c ;
        arr =new T *[row] ;
        for(int i=0 ; i<row ; i++){

            arr[i] = new T [col];

        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = 0;

    }

    Matrix<T>(const Matrix<T>& obj)
    {
        col = obj.col;
        row = obj.row;
        arr = new T*[row];

        for (int i = 0; i < row; i++)
            arr[i] = new T[col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = obj.arr[i][j];
    }
    int getRow(){
        return row ;
    }
    int getCol(){
        return col ;
    }
    Matrix<T> operator+( Matrix<T>&ob1){
        Matrix<T> res(row , col) ;
        if(getRow() == ob1.getRow() && getCol()==ob1.getCol()) {
            for (int i = 0; i < ob1.row; i++)
                for (int j = 0; j < ob1.col; j++)
                    res.arr[i][j] = arr[i][j] + ob1.arr[i][j];


            return res;
        } else
        {
            cout << "cannot add two matrices with different size" << endl;
        }

    }
    Matrix<T> operator-( Matrix<T>&ob1){
        Matrix<T> res(row , col) ;
        if(getRow() == ob1.getRow() && getCol()==ob1.getCol()){
            for (int i = 0; i < ob1.row; i++)
                for (int j = 0; j < ob1.col; j++)
                    res.arr[i][j] =arr[i][j]- ob1.arr[i][j];
            return res ;
        }else {

            cout << "cannot Subtract two matrices with different size" << endl;
        }

    }
    Matrix<T> operator* (  Matrix<T>& ob3 ){

        Matrix<T> res(row , col) ;
        if(getCol() == ob3.getRow()) {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < ob3.col; j++)
                    for (int k = 0; k < col; k++)
                    {
                        res.arr[i][j] = res.arr[i][j]+(arr[i][k] * ob3.arr[k][j]);
                    }
            return res ;

        }else {

            cout << "cannot Multiply two matrices with different size" << endl;
        }

    }
    Matrix<T> transpose(Matrix<T>& obj)
    {
        Matrix<T> res(obj.col, obj.row);

        for (int i = 0; i < obj.row; i++)
            for (int j = 0; j < obj.col; j++)
                res.arr[i][j] = obj.arr[j][i];

        for (int i = 0; i < obj.row; i++)
            for (int j = 0; j < obj.col; j++)
                obj.arr[i][j] = res.arr[i][j];

        return obj;
    }

    template<class T1>
    friend ostream &operator<<(ostream & output, const Matrix<T1> & ob);
    template<class T1>
    friend istream &operator>>( istream & input ,Matrix<T1> & ob9);

    ~Matrix<T>(){

        for(int i = 0; i < row;i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

template<class T1>
istream &operator>>( istream & input ,Matrix<T1> & ob9) {


    for (int i = 0; i < ob9.row; i++) {
        for (int j = 0; j < ob9.col; j++) {
            input >> ob9.arr[i][j];
        }
    }
    return input ;
}
template<class T1>
ostream &operator<<(ostream & output, const Matrix<T1> & ob){

    for(int i = 0;i < ob.row;i++) {
        for(int j = 0;j < ob.col;j++) {
            output<<ob.arr[i][j]<<" ";
        }
        output<<endl ;
    }
    return output;
}