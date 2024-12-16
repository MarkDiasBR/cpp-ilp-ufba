#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vec;
    int temp;
    
    for (int i=0; i<5; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    
    sort(vec.begin(),vec.end());
    
    int chave;
    cin >> chave;
    if (binary_search(vec.begin(), vec.end(), chave)) {
        cout << "Numero encontrado";
    }
    
    return 0;
}
