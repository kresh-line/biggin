#include <iostream>
using namespace std;
int main (){
    int firstvalue, secondvalue;

    int * mypointer;
    mypointer = &firstvalue;
    cout<< "mypointers value = "<<mypointer<<endl;
    cout<<"firstvalue address = "<<&firstvalue<<endl;

    *mypointer = 10;
    //firstvalue = 10;
    mypointer = &secondvalue;
    cout<< "mypointers value = "<<mypointer<<endl;
    cout<<"secondvalue address = "<<&secondvalue<<endl;

    *mypointer = 20;
// secondvalue=20;
    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';
    return 0;
}