//a
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    std::string str;
    clock_t start, endt;
    double duration;

    int i;

    cout << "Enter a string: ";
    getline(std::cin, str);



    start = clock();// TAKES TIME OF THE SYSTEM WHEN THE ALGORITHM STARTS
         cout << "Length of the string: " << str.length() << endl;
    endt = clock();//TAKES TIME OF THE SYSTEM WHEN THE ALGORITHM ENDS
    duration = (double)(endt-start) / CLOCKS_PER_SEC;//COVERTS TIME TO A PER SECOND FORMAT
    cout << "Time taken in seconds is " << duration;
    return 0;
}
