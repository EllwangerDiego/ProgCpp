#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    
    string questions[] = {{"1. What year was C++ created?: "},
                         {"2. Who invented C++?: "},
                         {"3. What is the predecessor of C++?: "},
                         {"4. Is the earth flat?: "}};

    string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                          {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerberg"},
                          {"A. C", "B. C+", "C. C--", "D. B++"},
                          {"A. Yes", "B. No", "C. Sometimes", "D. What's Earth?"}};
    
    char answerKey[] = {'C', 'B', 'A', 'D'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    for(int i = 0; i < size; i++){
        cout << "**************************" << endl;
        cout << questions[i] << endl;
        cout << "**************************" << endl;

        for(int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
            cout << options[i][j] << endl;
        }
        cout << "Type your answer: ";
        cin >> guess;
        //Passar de minusculo para maiusculo
        guess = toupper(guess);

        if(guess == answerKey[i]){
            cout << "CORRECT" << endl;
            Sleep(1500);
            score++;

        }
        else{
            cout << "WRONG" << endl;
            cout << "Answer: " << answerKey[i] << endl;
            Sleep(1500);
        }
    }
    cout << "**************************" << endl;
    cout << "*       Player score     *" << endl;
    cout << "**************************" << endl;
    cout << "# of questions: "<< size << endl;
    cout << "Score: "<< (score/(double)size) * 100 << endl;

    return 0;
}