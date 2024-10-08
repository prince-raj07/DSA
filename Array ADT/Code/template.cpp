#include<iostream>
using namespace std;

class array{
    private:
    int *A;
    int size;
    int length;
    friend void swap(int *,int*) ;
    public:

    void swap(int *a,int *b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
    }
    array(int size){
        this->size=size;
        A = new int[size];
        cout<<"Enter counting of elemnets" << endl;
        cin >> length ;
    }

    void created(){
        cout << "Enter elements" << endl;
        for(int i=0;i<length;i++){
            cin >> A[i] ;
        }
        cout << endl ;
    }

    void display(){
        cout << "Printing all elements" << endl; 
        for(int i=0;i<length;i++){
            cout << A[i] <<" " ;
        }
        cout<< endl;
    }
    ~array(){
        delete [] A;
        cout << "Array is destroyed" << endl ;
    }
};



int main(){
    array arr();
    return 0 ;
}