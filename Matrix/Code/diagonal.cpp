#include<iostream>
using namespace std ;

class diagonal{
    private :
        int *A ;
        int n ;
    
    public :

        diagonal(int n)
        {
          this->n = n ;
          A = new int[this->n] ;
        }

        void set(int i , int j , int x) ;
        int get (int i , int j) ;
        void display() ;
        ~diagonal()
        {
            delete []A;
        }
};

        void diagonal :: set(int i,int j ,int x){
            if(i==j)
             A[i-1] = x ;
        }

        int  diagonal :: get(int i , int j){
            if(i==j)
                return A[i-1] ;
            else 
                return 0 ;
        }

        void diagonal :: display(){
            int i , j ;
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(i==j)
                     cout << " "<< A[i-1] << " " ;
                     else
                     cout <<" 0 " ;
                }
                    cout << endl ;
            }
        }
int main()
{
    diagonal d1(4) ;
    d1.set(1,1,1);
    d1.set(2,2,2);
    d1.set(3,3,3);
    d1.set(4,4,4);
     cout << d1.get(2,2) << endl ;
     d1.display();
     return 0 ;
}