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

    void missing(array a){
        int l = a.A[0];
        int h = a.A[a.length - 1];
        int diff = l ;
        for(int i = 0;i<a.length;i++){
            if(a.A[i]-i!=diff){
                while(diff<a.A[i]-i){
                    cout << "The missing element  is " << i+diff << endl ;
                    diff++ ;
                }
            }
        }
    }

};

int main(){
    array arr(20);
    arr.create();
    arr.display();
    arr.missing(arr);
}