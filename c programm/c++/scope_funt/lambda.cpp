#include<iostream>
using namespace std;

int main() {

  int initial_sum = 100;

  // capture initial_sum by value
  auto add_to_sum = [initial_sum] (int num) {
    // here inital_sum = 100 from local scope
    return initial_sum + num;
  };

  int final_sum = add_to_sum(78);
  cout << "100 + 78 = " << final_sum;

  return 0;
}
