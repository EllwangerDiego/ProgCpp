#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // Inicializa vector
    vector<int> v1 = {1, 2, 3};
    cout << "[1]: " << v1[1] << endl;
    cout << "Front: " << v1.front() << endl;
    cout << "Back: "<< v1.back() << endl;
    cout << "Size: "<< v1.size() << endl;
    cout << "Capacity: "<< v1.capacity() << endl;
    cout << "Número na posição 2: " << v1.at(2) << endl;

    //Push back adiciona o numero
    v1.push_back(9);
    cout << "Size 2: "<< v1.size() << endl;
    cout << "Capacity 2: "<< v1.capacity() << endl;

    //Remove elemento do final: 
    v1.pop_back();
    v1.shrink_to_fit();

    //Insere elementos em qualquer posição:
    v1.insert(v1.begin() + 1, 99);  // Insere 99 na segunda posição

    //Remove um elemento de uma posição específica:
    v1.erase(v1.begin() + 2);  // Remove o terceiro elemento



    
    vector<int> v2 = {1, 2, 3, 4};
    v2.insert(v2.begin(), 5, 6);
    v2.erase(v2.begin());
    cout << v2[0] << endl;


    
    return 0;
}
