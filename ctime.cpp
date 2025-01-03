#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define SIZE 1000
#define ITER 10000

void find_sum(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum =  sum + a[i];
    }
}

int main()
{
    clock_t start, endt; // clock_t: time taken by the algo (implementation time)
    double duration;
    int a[SIZE];
    int i;

    srand(42);  //Used to generated random numbers, and time(0) stores values in seconds from Jan 1970
    for(i=0; i < SIZE; i++) {
        a[i] = rand() % 100;  //Gives values from 0 to 999
        cout << a[i] << endl;
    }
    start = clock();
    for(i = 0; i < ITER; i++)
        find_sum(a, SIZE);
    endt = clock();

    duration = (double)(endt-start) / CLOCKS_PER_SEC;
    cout << "Time taken in seconds is " << duration/ITER;

    return 0;
}
