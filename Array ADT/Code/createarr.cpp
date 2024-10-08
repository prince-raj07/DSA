#include<iostream>
using namespace std;

class array{
    private:
    int *A;
    int size;
    int length;

    public:
    array(int size){
        this->size=size;
        A = new int[size];
    }

    void created(){
        cout << "Enter elements" << endl;
        for(int i=0;i<size;i++){
            cin >> A[i] ;
        }
        cout << endl ;
    }

    void display(){
        cout << "Printing all elements" << endl; 
        for(int i=0;i<size;i++){
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
    array arr(5);
    arr.created();
    arr.display();

    return 0 ;
}