#include<iostream>
using namespace std;

class array{
    private:
    int *A;
    int size;
    int length;
    
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

    void reverse(){
        int i = 0;
        int j = length - 1 ;
        for(;i<=j;i++,j--){
            swap(&A[i],&A[j]);
        }
    }

    void reverse2(){
        int *B = new int[length];
        for(int i=0,j=(length-1);i<length;i++,j--){
            B[j] = A[i];
        }
        for(int i=0,j=0;i<length;i++,j++){
            A[i] = B[j] ;
        }
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
    arr.reverse2();
    arr.display();
    return 0 ;
}