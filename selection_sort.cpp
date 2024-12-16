#include <iostream>
#include <chrono>

using namespace std;

int main() {
    /*
    N is the size of the array to be ordered
   
    */
    int N, menor_index=0, temp, temp2;

    cout << "Insert the size of the array to be ordered: " << endl;
    cin >> N;

    //Declaring the array without initializing its values
    int arr[N];

    //Reading the N elements
    cout << "Insert the " << N << " elements separated by a whitespace character" << endl;
    for (int i=0; i < N; i++) {
        cin >> arr[i];
    }
    
    //Comparing the i=0 element to every other element. If we find any element less than it,
    //we will exchange places and continue the search
    
    // Start timing the execution
    auto start = chrono::high_resolution_clock::now();
    
    for (int i=1; i<N; i++) {    
        temp = arr[i-1];
        menor_index = i-1;
        
        for (int j=i; j<N; j++) {
            cout << "INÍCIO Rodada j = " << j << endl; 
            cout << "elemento pivô: " << temp << endl;
            cout << "comparando com: " << arr[j] << endl;
            
            if (temp > arr[j]) {
                cout << arr[j] << " é menor!" << endl;
                menor_index = j;
                temp = arr[j];
            } else {
                cout << temp << " permanece menor" << endl;
            }
            
            cout << "FIM Rodada j = " << j << endl;
            
            
            cout << endl;
        }
        
        if (menor_index != i-1) {
            cout << "houve troca e o novo resultado é: " << endl;
            arr[menor_index] = arr[i-1];
            arr[i-1] = temp;
        } else {
            cout << "não houve troca e o resultado permanece: " << endl;
        }
        
        for (int i=0; i<N;i++) {
            cout<< arr[i] <<" ";
        }
        
        cout << endl;
    }
    
    // End timing
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration and convert to microseconds for better precision
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Convert microseconds to milliseconds if needed
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(duration);

    // Output the time taken in microseconds and milliseconds
    cout << "Execution time: " << duration.count() << " microseconds (" 
         << milliseconds.count() << " milliseconds)." << endl;

}
