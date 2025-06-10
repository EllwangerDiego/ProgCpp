//Formatando numeros

/*
#include <stdio.h>

int main()
{
    printf("|%d|\n", 12345);
    printf("|%04d|\n", 25);
    printf("|%.2f|\n", 3.14159);
    printf("|%x|\n", 255); // hexa
    printf("|%o|\n", 255); // octal
    printf("|%E|\n", 255.1234);

    return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
    char buffer[50];
    int n, a = 12, b = 7;
    snprintf(
        buffer, sizeof(buffer),
        "%d/%d = %f", a, b, (float)a/b);
    cout << buffer << endl;
    
    return 0;
}