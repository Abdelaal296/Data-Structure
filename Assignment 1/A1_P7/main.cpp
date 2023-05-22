#include <bits/stdc++.h>
using namespace std;
void BiasedSort(vector<string>&songs){
    for (int i = 1; i < songs.size(); ++i) {
        string key =songs[i];
        int j= i-1;
        while (j>=0&& songs[j]>key){
            songs[j+1]=songs[j];
            j--;
        }
        songs[j+1]=key;
    }
    for (int i = 0; i < songs.size(); ++i) {
        if(songs[i]=="Untitled"){
            int j=i;
            while (j>0){
                swap(songs[j],songs[j-1]);
                j--;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<string>songs(n);
    for (int i = 0; i < n; ++i) {
        cin>>songs[i];
    }
    BiasedSort(songs);
    for (auto &song:songs) {
        cout<<song<<endl;
    }
    return 0;
}
