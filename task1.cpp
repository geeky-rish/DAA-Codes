#include<iostream>
using namespace std;

void tower(int n, char from, char to, char aux);

int main()
{
    int n;
    char from = 'A';
    char to = 'C';
    char aux = 'B';
    cout << "Enter n: " << endl;
    cin >> n;
    tower(n, from, to, aux);
}

void tower(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    tower(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    tower(n - 1, aux, to, from);
}
