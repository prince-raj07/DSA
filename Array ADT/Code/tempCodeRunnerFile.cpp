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

    void merge(array a ,array b,array c){
        int i = 0 ;
        int j = 0 ;
        int k = 0 ;
        while(i<5 && j<5){
            if(a.A[i] < b.A[j]){
                c.A[k] = a.A[i] ;
                if(i<=4)
                i++ ;
            }
            else{
            c.A[k] = b.A[j];
            if(j<=4)
            j++ ;
            }
            k++ ;
        }
    }

    ~array(){
        delete [] A;
        cout << "Array is destroyed" << endl ;
    }
};



int main(){
    array arr(5) ;
    arr.created() ;
    arr.display() ;
    array arr2(5) ;
    arr2.created() ;
    arr2.display() ;
    array arr3(10) ;
    arr3.merge(arr,arr2,arr3) ;
    arr3.display() ;
    return 0 ;
}