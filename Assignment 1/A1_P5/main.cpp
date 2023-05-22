#include <bits/stdc++.h>
using namespace std;
class studentName{
private:
    string name;
public:
    vector<string>names;
    studentName(){
        name="";
    }
    studentName(string s) {
        int spaces = 0,last_space;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                spaces++;
                last_space=i;
            }
        }
        if(spaces==0){
            name = name+s+" "+s+" "+s;
        }
        else if(spaces==1){
            name=name+s+s.substr(last_space);
        }
        else {
            name =s;
        }
        string temp="";
        for (int i = 0; i < name.size(); ++i) {
            if(name[i]==' '){
                names.push_back(temp);
                temp.clear();
            }
            else{
                temp+=name[i];
            }
        }
        names.push_back(temp);
    }
    void print() {
        cout<<name<<endl;
        int t=1;
        for (auto x:names) {
            cout<<t<<")"<<x<<endl;
            t++;
        }
        cout<<"....................................................."<<endl;
    }
    bool replace(int i,int j){
        i--;
        j--;
        if(j>=names.size()){
            return false;
        }
        else{
            swap(names[i],names[j]);
            string cach="";
            for (auto x:names) {
                cach += x+" ";
            }
            name=cach;
            return true;
        }
    }


};
int main() {
    studentName s1("youseef");
    studentName s3("Ziad ahmed");
    studentName s2("omar ahmed mohamed");
    studentName s4("mohamed abdelaal mahmoud abdelaal");
    studentName s5("Ahmed Ali ALi Mahmoud Ahmed");
    if(s1.replace(1,4)){
        s1.print();
    }
    else {
        cout << "Out of the range" << endl;
    }
    if(s2.replace(1,4)){
        s2.print();
    }
    else {
        cout << "Out of the range" << endl;
    }
    if(s3.replace(1,4)){
        s3.print();
    }
    else {
        cout << "Out of the range" << endl;
    }
    if(s4.replace(1,4)){
        s4.print();
    }
    else {
        cout << "Out of the range" << endl;
    }
    if(s5.replace(1,4)){
        s5.print();
    }
    else {
        cout << "Out of the range" << endl;
    }
    

     return 0;
}
