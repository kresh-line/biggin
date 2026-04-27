#include <iostream> 
using namespace std; 
 
void add2Num(int *, int *, int *); // pass by reference 
int diff2Num(int, int); // pass by value 
 
int main(){ 
 
    int num1=4, num2=1; 
    int sum, diff; 
    int array[] = {2, 4, 6};   
    int sum_array = 0; // store sum of elements in array[] 
 
    for (int i=0; i<3; i++)  // loop to find sum of array 
        sum_array += array[i]; 
    cout << "sum_array = " << sum_array << endl; 
 
    // add two numbers 
    add2Num(&num1, &num2, &sum); // pass by reference 
    cout << "sum of "<< num1<< " and "<< num2 <<" = " <<  sum << endl; 
 
    // subtract two numbers 
    diff = diff2Num(num1, num2); // pass by value 
    cout << "difference of "<< num1<< " and "<< num2 <<" = " << diff <<  endl; 
} 
 
// pass by reference 
void add2Num (int *a, int *b, int *c){ 
    *c = *a + *b; 
} 
 
// pass by value 
int diff2Num(int a, int b){ 
    return (a-b); 
}