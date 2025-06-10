#include <iostream>
using namespace std;

int searchArray(int array[], int size, int element);
int searchArray(string array[], int size, string element);

int main() {
    
   int numbers[] = {1,2,3,4,5,6,7,8,9,10};
   int size = sizeof(numbers)/sizeof(numbers[0]);
   int index;
   int myNum;

   cout << "Enter element to search for: ";
   cin >> myNum;

    index = searchArray(numbers, size, myNum);
    
    if(index != -1){
        cout << myNum << " is at index " << index << endl;
    }
    else{
        cout << myNum << " is not in the array" << endl;
    }

    //FOODS

    string myFood;
    string foods[] = {"pizza", "hamburguer", "hotdog"};
    size = sizeof(foods)/sizeof(foods[0]);

    cout << "Enter element to search for: ";
    //O cin >> myNum deixa um \n no buffer, entao, temos que chamar o cin.ignore() para nao ler esse \n
    cin.ignore();
    getline(cin, myFood);

    index = searchArray(foods, size, myFood);

    if(index != -1){
        cout << myFood << " is at index " << index << endl;
    }
    else{
        cout << myFood << " is not in the array" << endl;
    }

    return 0;
}

int searchArray(int array[], int size, int element){
    for(int i = 0; i < size; i++){
        if(array[i] == element){
            return i;
        }
    }
    return -1;
}

int searchArray(string array[], int size, string element){
    for(int i = 0; i < size; i++){
        if(array[i] == element){
            return i;
        }
    }
    return -1;
}