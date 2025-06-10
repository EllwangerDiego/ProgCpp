#include <iostream>
#include <vector>
using namespace std;

int main() {
    
vector<int> v1 = {1, 2, 3, 4};

for(int i = 0; i < v1.size(); i++){
    cout << v1.at(i) <<" ";
}
cout << endl;

vector<int>::iterator it;
for(it = v1.begin(); it != v1.end(); it++){
    cout << *it << ' ';
}
cout << endl;
    
    return 0;
}
