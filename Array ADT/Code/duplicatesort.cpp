#include<iostream>
using namespace std ;

class array{
    private :
    int *A ;
    int size ;
    int length ;

    public :
    array(int size){
        this->size = size ;
        A = new int [size];
        cout << "Enter length of array" << endl;
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

    void duplicate(array a){
        
    }
};

int main(){

}