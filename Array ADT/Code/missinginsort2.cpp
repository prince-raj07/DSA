// Using hashing

#include<iostream>
using namespace std;

class array{
    private :
    int *A ;
    int size ;
    int length;

    public :
    array(int size){
        this->size = size ;
        A = new int[size] ;
        cout << "Enter length of elements" << endl ;
        cin >> length ;
    }

    void create(){
        cout << "Enter elements" << endl ;
        for(int i = 0;i<length;i++){
            cin >> A[i];
        }
        cout << endl ;
    }

    void display(){
        for(int i=0;i<length;i++){
            cout << A[i] << " " ;
        }
        cout << endl;
    }

    void missing2(array a,int h){
       int arr[h]={0};
       for(int i=0;i<length;i++){
        arr[a.A[i]]++;
       }
       for(int i=0;i<h;i++){
        cout << arr[i] << endl ;
        if(arr[i]==0)
        cout << "The missing elemest is " << i << endl ;
       }
    }

};

int main(){
    array arr(10);
    arr.create();
    arr.display();
    arr.missing2(arr,8);
}