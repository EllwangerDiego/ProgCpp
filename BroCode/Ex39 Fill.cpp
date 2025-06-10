#include <iostream>
using namespace std;

    // fill() = Fills a range of elements with a specified value
    //          fill(begin, end, value)

int main() {
    const int size = 10;
    string foods[size];

    fill(foods, foods + size/2, "pizza");
    fill(foods + (size/2), foods + (size), "hamburguers");

    for(int i = 0; i < size; i++){
        cout << foods[i] << " ";
    }
    
    return 0;
}