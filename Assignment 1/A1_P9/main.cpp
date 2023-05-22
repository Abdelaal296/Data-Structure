#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
using namespace std ;
using namespace std::chrono;
class Sorter{
protected:
    int size ;
    int *arr ;
public:
    Sorter(){}
    Sorter(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
       virtual void Sort(int* arr, int size){
           sort(arr , arr +size);
        }
};
class SelectionSort : public Sorter{
private:
    int size ;
public:
        SelectionSort(){}

        SelectionSort(int s):Sorter(s){
            size = s ;
        }
        void Sort(int* arr, int size){
            for (int i = 0, j, least; i < size-1; i++) {

                for (j = i+1, least = i; j < size; j++)

                    if (arr [j] < arr [least])
                        least = j;
                swap (arr [least], arr [i]);
            }

        }
};
class QuickSort : public Sorter{
private:
    int size ;
public:
    QuickSort(){}
    QuickSort(int s):Sorter(s){
        size = s ;
    }
    int partition(int arr[], int start, int end)
    {

        int pivot = arr[start];

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);

        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i] <= pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
    }
    void quickSort(int arr[], int start, int end)
    {

        if (start >= end)
            return;

        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);

        quickSort(arr, p + 1, end);
    }

    void Sort(int* arr, int size) {
        quickSort(arr,0,size - 1);
    }
};
class Testbed {
private:
    int size ;
    int* arr ;
public:
    Testbed(){
        size = 0;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    Testbed(int s) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    void Setsize(int s){
       this-> size = s ;
    }

    void GenerateRandomList(int min,int  max, int size){
        for(int i=0;i<size;i++) {
            arr[i] = (rand() % (max - min + 1));

        }
    }
    void GenerateReverseOrderedList(int min,int  max, int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = (rand() % (max - min + 1));

        }

        reverse(arr, arr + size);

    }
    void RunOnce( Sorter sorter,int data[],int size){

            auto start = high_resolution_clock::now();
            sorter.Sort(data , size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            duration.count();
        }
    void RunAndAverage(Sorter sorter,int type,int min,int max,int size,int sets_num){
        int result = 0 , average=0;
        if(type == 0)
        {
            for (int i = 0; i < sets_num; i++)
            {

              auto start = high_resolution_clock::now();
              GenerateRandomList(min , max ,size );
              RunOnce(sorter,arr , size);
              auto stop = high_resolution_clock::now();
              auto duration = duration_cast<microseconds>(stop - start);
              result += duration.count() ;




            }
        }
        else if(type == 1)
        {
            for (int i = 0; i < sets_num; i++)
            {
                auto start = high_resolution_clock::now();
                GenerateReverseOrderedList(min , max ,size );
                RunOnce(sorter,arr , size);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                result += duration.count() ;


            }
        }

        average = (result / sets_num) ;
        cout<<size << setw(8) << average <<" microseconds" << endl;

    }
    void RunExperiment (Sorter sorter,int type,int min,int max,int min_val,int max_val,int sets_num,int step){

        if (type == 0){
            for(int i =min_val ; i< max_val ; i +=step){
                RunAndAverage(sorter,0,min , max,size,sets_num);




            }
        } else if (type == 1){
            for(int i =min_val ; i< max_val ; i +=step){
                RunAndAverage(sorter,1,min , max,size,sets_num);

            }

        }


    }
    void print(int data[],int n) {
        for (int i = 0; i < n; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};


int main()
{
    cout<< "     random data "<<endl ;
    cout<<"size" << setw(15) << "average"<< endl;
    Testbed obj(25000) ;
    Sorter* s = new SelectionSort ;
    obj.RunExperiment(*s,0,1000,1000000,5000,100000,4,500000);

    Testbed obj1(50000) ;
    Sorter* s1 = new SelectionSort ;
    obj1.RunExperiment(*s1,0,1000,1000000,5000,100000,4,500000);

    Testbed obj2(100000) ;
    Sorter* s2 = new SelectionSort ;
    obj2.RunExperiment(*s2,0,1000,1000000,5000,100000,4,500000);

    Testbed obj3(250000) ;
    Sorter* s3 = new SelectionSort ;
    obj3.RunExperiment(*s3,0,1000,1000000,5000,100000,4,500000);

    Testbed obj4(500000) ;
    Sorter* s4 = new SelectionSort ;
    obj4.RunExperiment(*s4,0,1000,1000000,5000,100000,4,500000);


    cout<< "     reverse data "<<endl ;
    cout<<"size" << setw(15) << "average"<< endl;
    Testbed obj5(25000) ;
    Sorter* s5 = new SelectionSort ;
    obj5.RunExperiment(*s5,1,10000,1000000,5000,10000,6,500000);

    Testbed obj6(50000) ;
    Sorter* s6 = new SelectionSort ;
    obj6.RunExperiment(*s6,1,1000,1000000,5000,100000,4,500000);

    Testbed obj7(100000) ;
    Sorter* s7 = new SelectionSort ;
    obj7.RunExperiment(*s7,1,1000,1000000,5000,100000,4,500000);

    Testbed obj8(250000) ;
    Sorter* s8 = new SelectionSort ;
    obj8.RunExperiment(*s8,1,1000,1000000,5000,100000,4,500000);

    Testbed obj9(500000) ;
    Sorter* s9= new SelectionSort ;
    obj9.RunExperiment(*s9,1,1000,1000000,5000,100000,4,500000);


    return 0;
}




























