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

    void deletes(int idx){
        if(idx<=length-1){
        for(int i=idx;i<length-1;i++){
            A[i] = A[i+1] ;
        }
        length -- ;
        }
    }
    ~array(){
        delete [] A;
        cout << "Array is destroyed" << endl ;
    }
};

int main(){
    array arr(7);
    arr.created() ;
    arr.display();
    arr.deletes(4);
    arr.display();
    return 0 ;
}