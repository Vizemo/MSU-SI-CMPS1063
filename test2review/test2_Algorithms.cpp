#include <iostream>
using namespace std;

/*
Purpose: Sorts an array in ascending order using insertion sort
Parameters: int a[] - the array to be sorted, int n - the number of elements in the array
Returns: void
*/
void insertSort(int a[], int n);

/*
Purpose: Sorts an array in ascending order using selection sort
Parameters: int arr[] - the array to be sorted, int n - the number of elements in the array
Returns: void
*/
void selectionSort(int arr[], int n);

/*
Purpose: Searches for a value in an array using linear search
Parameters: int list[] - the array to be searched, int numberOfElements - the number of elements in the array, int searchValue - the value to search for
Returns: int - the index of the searchValue if found, otherwise -1
*/
int linearSearch(int list[], int numberOfElements, int searchValue);

/*
Purpose: Recursively searches for a value in an array using linear search
Parameters: int arr[] - the array to be searched, int size - the number of elements in the array, int key - the value to search for
Returns: int - the index of the key if found, otherwise -1
*/
int linearSearchR(int arr[], int size, int key);

/*
Purpose: Searches for a value in a sorted array using iterative binary search
Parameters: int arr[] - the sorted array to be searched, int low - the starting index, int high - the ending index, int x - the value to search for
Returns: int - the index of the value x if found, otherwise -1
*/
int binarySearch(int arr[], int low, int high, int x);

/*
Purpose: Recursively searches for a value in a sorted array using binary search
Parameters: int a[] - the sorted array to be searched, int start - the starting index, int end - the ending index, int key - the value to search for
Returns: int - the index of the key if found, otherwise -1
*/
int binarySearchR(int a[], int start, int end, int key);

/*
Purpose: Prints all elements of an array
Parameters: int arr[] - the array to be printed, int n - the number of elements in the array
Returns: void
*/
void printArray(int arr[], int n);

int main() {
    int arr[] = { 30, 25, 20, 15, 10, 5 };
    int n = 6;

    cout << "Original array: ";
    printArray(arr, n);

    // Testing insertion sort
    insertSort(arr, n);
    cout << "Array after insertion sort: ";
    printArray(arr, n);

    // Resetting the array to unsorted state for the next sort test
    int arr2[] = { 30, 25, 20, 15, 10, 5 };
    cout << "\nOriginal array for selection sort: ";
    printArray(arr2, n);

    // Testing selection sort
    selectionSort(arr2, n);
    cout << "Array after selection sort: ";
    printArray(arr2, n);

    // Testing iterative linear search
    int searchValue = 15;
    int pos = linearSearch(arr2, n, searchValue);
    if (pos != -1)
        cout << "\nIterative linear search: " << searchValue << " found at index " << pos << endl;
    else
        cout << "\nIterative linear search: " << searchValue << " not found in array." << endl;

    // Testing recursive linear search
    pos = linearSearchR(arr2, n, searchValue);
    if (pos != -1)
        cout << "Recursive linear search: " << searchValue << " found at index " << pos << endl;
    else
        cout << "Recursive linear search: " << searchValue << " not found in array." << endl;

    // Testing iterative binary search
    int key = 15;
    pos = binarySearch(arr2, 0, n - 1, key);
    if (pos != -1)
        cout << "Iterative binary search: " << key << " found at index " << pos << endl;
    else
        cout << "Iterative binary search: " << key << " not found in array." << endl;

    // Testing recursive binary search
    pos = binarySearchR(arr2, 0, n - 1, key);
    if (pos != -1)
        cout << "Recursive binary search: " << key << " found at index " << pos << endl;
    else
        cout << "Recursive binary search: " << key << " not found in array." << endl;

    return 0;
}


// Insert sort
void insertSort(int a[], int n)
{
    bool found;
    int j;

    // put each element in unsorted subarray in proper position
    for (int i = 1; i < n; i++)
    {
        // find proper place for a[i] relative to a[0]..a[i]
        found = false;
        j = i;
        while ((j > 0) && !found)
        {
            // swap using a temporary variable and decrement j
            if (a[j] < a[j - 1])
            {
                // Use a temporary variable to swap
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                j = j - 1;
            }
            else found = true;
        } // end while
    } // end for
} // end insertSort

// selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted
        // portion of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with 
        // the first element of the unsorted portion
        swap(arr[minIndex], arr[i]);
    }
}

int linearSearch(int list[], int numberOfElements, int searchValue) {
    bool found = false;
    int position = -1;
    int index = 0;

    // Loop until we reach the end of the list or find the search value
    while (index < numberOfElements && !found) {
        if (list[index] == searchValue) {
            found = true;
            position = index;  // Set position to the current index
        }
        index++;  // Move to the next element
    }

    return position;  // Return the position (or -1 if not found)
}

// Recursive linear search function
int linearSearchR(int arr[], int size, int key) {
    // Base case: If the size is 0, the key was not found in the array.
    if (size == 0) {
        return -1; // Return -1 to indicate the key is not found.
    }

    // Check if the last element in the current array segment is the key.
    else if (arr[size - 1] == key) {
        // If found, return the index of the key (size - 1).
        return size - 1;
    }

    // Recursive case: Call linearsearch on the array excluding the last element.
    return linearSearchR(arr, size - 1, key);
}

// An iterative binary search function.
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// recursive binary search
int binarySearchR(int a[], int start, int end, int key)
{
    int m = (start + end) / 2;
    if (start > end) return -1; // base
    if (a[m] == key) return m; // base
    if (a[m] > key)
        return binarySearchR(a, start, m - 1, key);
    else
        return binarySearchR(a, m + 1, end, key);
}

// prints array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}