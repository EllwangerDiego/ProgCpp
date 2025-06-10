#include <iostream>
using namespace std;

    // Abstraction = hiding unnecessary data from outside a class
    // getter = function that makes a private atribute READABLE
    // setter = function that makes a private attribute WRITEABLE

    class Stove{
        private:
            int temperature = 0;

        public:
        // Pode usar constructor
        Stove(int temperature){
            setTemperature(temperature);
        }
            //Getter - Readable
            int getTemperature(){
                return this->temperature;
            };
            //Setter - Writeable
            void setTemperature(int temperature){
                if(temperature < 0){
                    this->temperature = 0;
                }
                else if(temperature >= 10){
                    this->temperature = 10;
                }
                else{
                    this->temperature = temperature;
                }
                
            };
    };

int main() {
    
    //Atribuindo usando constructor
    Stove stove(0);

    int temperature;
    cout << "Digite uma temperatura: ";
    cin >> temperature;

    //Atribuindo usando setter
    stove.setTemperature(temperature);

 
    //Lendo e dando cout com o getter
    cout << stove.getTemperature() << endl;
    
    return 0;
}
