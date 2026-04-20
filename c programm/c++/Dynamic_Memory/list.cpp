#include <iostream>
#include <list>
using namespace std;
int main()
{
list<int> mylist;
// set some initial values:
for (int i = 1; i <= 5; ++i)
mylist.push_back(i); // 1 2 3 4 5
list<int>::iterator it;

cout << "mylist contains:";
for (it = mylist.begin(); it != mylist.end(); ++it)
cout << ' ' << *it;
cout << '\n';
it = mylist.begin(); // it shows item 1
++it; // it now shows item 2
mylist.insert(it, 10); // Insert 10 before 2 -> 1 10 2 3 4 5
// it still shows item 2
mylist.insert(it, 20); // 1 10 20 2 3 4 5
--it; // it shows now item 20
it = mylist.insert(it, 300); // it shows now item 300
mylist.insert(it, 450);
cout << "mylist Now contains:";
for (it = mylist.begin(); it != mylist.end(); ++it)
cout << ' ' << *it;
cout << '\n';
mylist.sort();
cout << "Sorted List:";
for (it = mylist.begin(); it != mylist.end(); ++it)
cout << ' ' << *it;
cout << '\n';
return 0;
}