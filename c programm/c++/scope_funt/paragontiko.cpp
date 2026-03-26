#include <iostream>
using namespace std;

double parag(int N){
   double ginomeno = 1.0;
    for(int i = 1; i <= N; i++){
        ginomeno *= i;
    }
    return ginomeno;
}

int main (){
    
    cout << parag(49)/(parag(6)*parag(43)) << endl;

}