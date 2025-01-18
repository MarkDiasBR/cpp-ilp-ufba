#include <iostream>
#include <chrono>

using namespace std;

int main(){

int chave, n;

cin>>chave>>n;
int v[n];

for(int i=0; i<n; i++) {
    cin>>v[i];
}

int li=0, ls=n-1, meio;

auto start = chrono::high_resolution_clock::now();

while(li<=ls) {
    meio = (li+ls)/2;
    
    if(chave<v[meio]) ls=meio-1;
    else if(chave>v[meio]) li=meio+1;
    else break;
}

if(chave==v[meio]) {
    cout<<"SIM"<<endl;
} else {
    cout<<"NAO"<<endl;
}

// End timing
auto end = chrono::high_resolution_clock::now();

// Calculate the duration and convert to nanoseconds for better precision
auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

// Convert nanoseconds to microseconds if needed
auto microseconds = chrono::duration_cast<chrono::microseconds>(duration);

// Output the time taken in nanoseconds and microseconds
cout << "Execution time: " << duration.count() << " nanoseconds (" 
     << microseconds.count() << " microseconds)." << endl;

return 0;
}
