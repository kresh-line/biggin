#include <iostream>
#include <vector>
using namespace std;
int main()
{
// create a vector to store int
vector<int> vec;
int i, newInt;
// display the original size of vec
cout << "vector size = " << vec.size() << endl;
// read 3 integer values and push them in the vector
for (i = 0; i < 3; i++)
{
cout << "Give me a number :";
cin >> newInt;
vec.push_back(newInt);
}
// display vector contents
for (i = 0; i < vec.size(); i++)
{
cout << "value of vec[" << i << "] = " << vec[i] << endl;
}
// use iterator to access the values
vector<int>::iterator v;
v = vec.begin();
// read 2 more integer values and insert them in the beginning of the vector

for (i = 0; i < 2; i++)
{
cout << "Give me a number :";
cin >> newInt;
vec.insert(v, newInt);

}
v = vec.begin();
i = 0;
while (v != vec.end())
{
cout << "value of vec[" << i << "]=" << *v << endl;
v++;
i++;
}
return 0;
}