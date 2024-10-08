#include<iostream>
using namespace std ;

class lt{
    private :
        int *A ;
        int size ;

    public :
        lt(int n){
            size = n ;
            n = (n*(n+1))/2 ;
            A = new int[n] ;
        }    

    void set(int i,int j ,int x){
        if(i>=j){
        int a = ((i*(i+1))/2) + j ;
        A[a] = x ;
        } 
    }    

    int get(int i , int j){
        if(i>=j){
        int a = ((i*(i+1))/2) + j ;
        return A[a] ;
        }
        else
        return 0 ;
    }

    void display(){
        int i , j ;
        for (int i=0;i<size;i++){
            for(int j = 0 ;j<size;j++){
                if(i>=j){
                   int a = ((i*(i+1))/2) + j ;
                    cout <<  A[a] << " " ;
                }
                else
                    cout << "0 " ;
            }
            cout << endl ;
        }
    }

    ~lt(){
        delete []A;
        
    }
};

int main(){
    lt l1(3) ;
    l1.set(0,0,1);
    l1.set(1,0,2);
    l1.set(1,1,2);
    l1.set(2,0,3);
    l1.set(2,1,3);
    l1.set(2,2,3);
    l1.display();
    return 0 ;
}