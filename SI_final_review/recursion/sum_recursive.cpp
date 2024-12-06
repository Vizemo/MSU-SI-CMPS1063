#include <iostream>
using namespace std;

// Recursive function to calculate the sum of numbers from 1 to n
int sumRecursive(int n) {
    // Base Case: If n is 1, return 1
    if (n == 1) {
        return 1;
    }
    // Recursive Case: n + sum of numbers from 1 to n-1
    return n + sumRecursive(n - 1);
}

int main() {
    int num = 5; // Example: Find the sum of numbers from 1 to 5
    cout << "Recursive Sum: " << sumRecursive(num) << endl;
    return 0;
}