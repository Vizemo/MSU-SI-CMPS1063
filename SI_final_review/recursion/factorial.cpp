#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    // 1. Base Case: When n is 0, return 1
    if (n == 0) {
        return 1;
    }
    // 2. Recursive Step or Approach to the base case
    //    Progress towards the base case (n decreases)
    return n * factorial(n - 1);
}

int main() {
    int num = 5;

    // Calculate and print factorial of num
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;

    return 0;
}