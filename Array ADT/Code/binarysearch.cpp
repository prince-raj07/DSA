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

    void binary(int x){
        int l = 0 ;
        int h = length - 1;
        int mid  ;
        while(l<=h){
        cout <<"mid = "<<  mid << endl ;
         mid = (l+h)/2 ;
         if(A[mid]==x){
            cout <<"The element is present at "<< mid << endl ;
            return ;
         }
         else if(A[mid] < x)
         l = mid + 1 ;
         else 
         h = mid-1;
        }
        cout <<"The element is not present " << endl ;
    }

    ~array(){
        delete [] A;
        cout << "Array is destroyed" << endl ;
    }
};

int main(){
    array arr(15);
    arr.created();
    arr.display();
    arr.binary(18);
    return 0 ;
}