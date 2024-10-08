  #include<iostream>
  using namespace std ;

  class lt{
    private :
     int *A;
     int size ;

     public :
        lt(int n){
            n = size ;
            n = (n*(n+1))/2;
            A = new int[n] ;
        }

        void set(int i,int j,int x){
            if(i>=j){
                int a = ((size*j) - (j*(j-1))/2) + (i-j);
                A[a] = x ;
            }
        }

        int get(int i , int j){
            if(i>=j){
                int a = ((size*j) - (j*(j-1))/2) + (i-j);
                return A[a];
            }
            else if(i<j)
            return  0 ;
        }

        void display(){
          for(int i=0;i<size;i++){
             for(int j=0;j<size;j++){
                 if(i>=j){
                     int a = ((size*j) - (j*(j-1))/2) + (i-j);
                     cout << A[a] << " ";
                 }
                 else{
                    cout << "0" << " " ;
                 }
             }
                    cout << endl ;
          }
        }
  };

    int main(){
        lt l1(3);
        // l1.set(0,0,1);
        // l1.set(1,0,1);
        // l1.set(2,0,1);
        // l1.set(1,2,2);
        // l1.set(2,2,2);
        // l1.set(2,3,3);
        // l1.display();
    l1.set(0,0,1);
    l1.set(1,0,2);
    l1.set(1,1,2);
    l1.set(2,0,3);
    l1.set(2,1,3);
    l1.set(2,2,3);
    l1.display();
    return 0 ;
    }