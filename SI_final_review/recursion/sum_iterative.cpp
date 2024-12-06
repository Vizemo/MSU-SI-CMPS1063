#include <iostream>
using namespace std;

int sumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int num = 5; // Example: Find the sum of numbers from 1 to 5
    cout << "Iterative Sum: " << sumIterative(num) << endl;
    return 0;
}