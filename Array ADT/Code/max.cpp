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

    void max(){
        int max = A[0];
        for(int i=1;i<=length-1;i++){
            if(A[i]>=max){
                max = A[i];
            }
        }
        cout << "The maximum element in array is " << max << endl ;
    }

    ~array(){
        delete [] A;
        cout << "Array is destroyed" << endl ;
    }
};

int main(){
    array arr(10);
    arr.created();
    arr.display();
    arr.max();
    return 0 ;
}