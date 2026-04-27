#include "my_header.hpp" 
 
int main(){ 
 
     int sum_array = 0; // store sum of elements in array[] 
 
    int num1=4, num2=1; 
    int sum, diff; 
    int array[] = {2, 4, 6};   
 
    for (int i=0; i<3; i++)  // loop to find sum of array 
        sum_array += array[i]; 
    cout << "sum_array = " << sum_array << endl; 
 
    // add two numbers 
    add2Num(&num1, &num2, &sum); // pass by reference 
    cout << "sum of "<< num1<< " and "<< num2 <<" = " <<  sum << endl; 
 
    // subtract two numbers 
    diff = diff2Num(num1, num2); // pass by value 
    cout << "difference of "<< num1<< " and "<< num2 <<" = " << diff << endl;

    cout<<"Circle Perimeter with radius "<<num1<<" = "<<circle_perimeter(num1)<<endl;
}