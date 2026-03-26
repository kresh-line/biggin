#include <iostream>
using namespace std;
 

#include <iomanip>
using std::setw;
 #define  M 3
 #define  N 3
int main () {

   double vath[M][N]; // n is an array of 10 integers
 
   // initialize elements of array n to 0          
   for ( int i = 0; i < M; i++ ) // i= foithtis
   {
    cout<<"Foithtis "<<i+1<<"os "<<endl;
    for (int j=0; j<N; j++) // j= mathima
    {
      cout<< "dwse ton vathmo gia to "<<j+1<<"o mathima: ";
      cin>>vath[i][j];
    }
   }
   
   for(int i=0;i<M;i++) {
    double sum =0.0; 
    for (int j=0; j < N; j++)
    sum+=vath[i][j];
  
   double mesos_oros=sum/(N);
   cout<< "Mesos oros "<<i+1<<"foithth = "<<mesos_oros<< endl;
   }
   //cout << "Element" << setw( 13 ) << "Value" << endl;
 
   // output each array element's value                      
//    for ( int j = 0; j < 10; j++ ) {
    //   cout << setw( 7 )<< j << setw( 13 ) << vath[ j ] << endl;
  // }
 
   return 0;
}