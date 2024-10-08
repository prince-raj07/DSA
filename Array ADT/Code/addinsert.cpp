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
        void add(int x){
            A[length] = x ;
            length++;
        }

        void insert(int idx,int x){
            if(idx<=length){
                for(int i=length;i>idx;i--){
                    A[i] = A[i-1];
                }
                A[idx] = x ;
                length ++ ;
            }
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
    arr.add(6);
    arr.display();
    arr.insert(4,44);
    arr.display();
    return 0 ;
}