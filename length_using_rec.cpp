#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int findLength(const std::string& str, int index = 0)
{
    if (str[index] == '\0')
    {
        return 0;
    }
    return 1 + findLength(str, index + 1);
}

int main()
{
    string str;
    clock_t start, endt;
    double duration;

    cout<<"Enter a string: ";
    getline(std::cin, str);



    start = clock();// TAKES TIME OF THE SYSTEM WHEN THE ALGORITHM STARTS
         cout<<"Length of the string:"<<findLength(str)<<endl;
    endt = clock();//TAKES TIME OF THE SYSTEM WHEN THE ALGORITHM ENDS
    duration = (double)(endt-start) / CLOCKS_PER_SEC;//COVERTS TIME TO A PER SECOND FORMAT
    cout << "Time taken in seconds is " << duration;
    return 0;
}
