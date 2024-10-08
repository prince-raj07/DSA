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
        int sum = 0 ;
        int n = length + 1 ;
        for(int i=0;i<length;i++){
            sum += a.A[i];
        }
        int s = n*(n+1)/2 ;
        cout << "The missing element is " << s-sum << endl ;
    }

};

int main(){
    array arr(10);
    arr.create();
    arr.display();
    arr.missing(arr);
}