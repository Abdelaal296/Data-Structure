#include <bits/stdc++.h>
using namespace std;

class BigInt{
private:
    vector<int>v;
    bool sign= false;
public:
    BigInt(){
        v.push_back(0);
        sign= false;
    }
    BigInt(string s){

        for (int i = (int)s.size()-1; i >0; --i) {
            int x=(int(s[i])-48);
            v.push_back(x);
        }
        if(s[0]=='-')sign= true;
        else {
            v.push_back(s[0]-48);
        }
    }
    BigInt(int x){
        if(x<0){
            x*=-1;
            sign=true;
        }
        while (x!=0){
            v.push_back(x%10);
            x/=10;
        }
    }
    bool operator <(BigInt obj){
        if(sign!=obj.sign)return sign<obj.sign;
        if(v.size()!=obj.v.size())return v.size()<obj.v.size();
        for (int i = v.size()-1; i >=0 ; --i) {
            if(v[i]!=obj.v[i])return v[i]<obj.v[i];
        }
    }
    void operator = (BigInt obj){
        sign=obj.sign;
        v=obj.v;
    }
    BigInt operator+(BigInt  &obj){
        BigInt sum;
        // + +
        if(!sign&&!obj.sign){
            for (int i = 0,c=0; i <v.size()||i<obj.v.size()||c; ++i) {
                if(i<v.size()){
                    c+=v[i];
                }
                if(i<obj.v.size()){
                    c+=obj.v[i];
                }
                sum.v.push_back(c%10);
                c/=10;
            }
        }
        // - -
        else if (sign&&obj.sign){
            sign= false;
            obj.sign= false;
            sum = *this+obj;
            sign = true;
            obj.sign = true;
            sum.sign = true;
        }
        // + -
        else if ( !sign&&obj.sign){
            obj.sign= false;
            sum = *this-obj;
            obj.sign= true;
        }
        // - +
        else if(sign&&!obj.sign){
            sign= false;
            sum= obj-*this;
            sign = true;
        }
        return sum;
    }
    BigInt operator-(BigInt  &obj ){
        BigInt sub;
        // - +
        if(sign&&!obj.sign){
             obj.sign= false;
             sign = false;
             sub = *this+obj;
             sub.sign= true;
             obj.sign= true;
        }
        // + +
        else if(!sign&&!obj.sign){
            if(*this<obj){
                sub = obj-*this;
                sub.sign= true;
            }
            else {
                for (int i = 0, b = 0; i < v.size(); ++i) {
                    if (i < obj.v.size()) {
                        b = v[i] - b - obj.v[i];
                    } else {
                        b = v[i] - b;
                    }
                    if (b >= 0) {
                        sub.v.push_back(b);
                        b = 0;
                    }
                    else {
                        sub.v.push_back(b + 10);
                        b = 1;
                    }
                }
            }
        }
        // - -
        else if (sign&&obj.sign){
            obj.sign = false;
            sub = *this+obj;
            obj.sign= true;
        }
        // + -
        else if (!sign&&obj.sign){
             obj.sign= false;
             sub = *this+obj;
             sub.sign= false;
             obj.sign= true;
         }
        return sub;

    }
    int size(){
        return (int)v.size();
    }
    void eraseZero(){
        while (v[v.size()-1]==0&&v.size()>1){
            v.pop_back();
        }

    }
    friend ostream& operator << (ostream& out, BigInt b){
        b.eraseZero();
        reverse(b.v.begin(),b.v.end());
        if(b.sign)cout<<'-';
        for (int i = 0; i < b.size(); ++i) {
            cout<<b.v[i];
        }
        cout<<endl;
    }


};
int main()
{
    BigInt num( 99999);
    BigInt num9(99999);
    cout<<num-num9<<endl;
    // 0
    BigInt num1("12345678901234567890123456789123456789");
    BigInt num2("11345678901134567890113456789123456789");
    BigInt num3 = num2 + num1;
    BigInt num4 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num3 << endl;
    //236913578023691357802369135782469135780
    cout << "num2 - num1 = " << num4 << endl;
    //-10000000001000000000100000000000000000
    BigInt num5("3333333333333333333333333333333333333333333");
    BigInt num6("-111111111111111111111111111111111111111111");
    BigInt num7 = num5 + num6;
    BigInt num8 = num5 - num6;

    cout << "num5 + num6 = " << num7 << endl;
//32222222222222222222222222222222222222222220
    cout << "num5 - num6 = " << num8 << endl;
//34444444444444444444444444444444444444444440

    return 0;
}
