#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
void insertionSort (int data[], int n)
{
    int tmp , i , j ;
    for ( i = 1; i < n; i++) {
        int tmp = data[i];

        for ( j = i; j > 0 && tmp < data[j - 1]; j--)
            data[j] = data[j - 1];
            data[j] = tmp;

    }
}
int binarySearch(int a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
void binaryInsertionSort(int data[], int n)
{
    int i, loc, j, position;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        position = data[i];
        loc = binarySearch(data, position, 0, j);

        while (j >= loc)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] =position;
    }

}
void print(int data[],int n){
    for(int i=0 ; i<n ; i++)
        cout<<data[i]<<" ";
    cout<<endl;

}


int main() {


    int* ptr;
    int n;
    auto f = []() -> int { return rand() % 10000; };
        cin >> n;
        ptr = new int[n];
        generate(ptr, ptr + n, f);
        auto start = high_resolution_clock::now();
        insertionSort(ptr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
         cout << duration.count()<<" millisecond" << endl;
    return 0 ;

}
