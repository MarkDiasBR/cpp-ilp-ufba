#include <iostream>
#include <chrono>
#include <Windows.h>
#include <vector>

using namespace std;


int main() {
    //Set console encoding to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    //Get input N: length of the array to be sorted
    int N;
    cin >> N;
    // Edge case for empty or invalid input
    if (N <= 0) return 0; 

    vector<int> my_vector(N);

    //Get input: array elements (N elements)
    for (int i = 0; i < N; i++)
        cin >> my_vector[i];

    // Start timing the execution
    auto start = chrono::high_resolution_clock::now();
    
    // Selection Sort
    for (int j = 0; j < N - 1; j++) {
        int min_i = j;
        for (int i = j + 1; i < N; i++) {
            if (my_vector[i] < my_vector[min_i])
                min_i = i;
        }

        // Swap only if necessary
        if (min_i != j)
            swap(my_vector[j], my_vector[min_i]);
    }

    // End timing
    auto end = chrono::high_resolution_clock::now();
    // Calculate the duration and convert to microseconds for better precision
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // Convert microseconds to milliseconds if needed
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration);
    
    // Output the sorted array
    for (int i = 0; i < N - 1; i++)
        cout << my_vector[i] << " ";
    cout << my_vector[N - 1] << endl; // No extra space after the last element
    
    // Output the time taken in microseconds and milliseconds
    cout << "Execution time: " << duration.count() << " microseconds ("
        << milliseconds.count() << " milliseconds)." << endl;

    return 0;
}
