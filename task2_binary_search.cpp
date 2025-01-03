#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

#define Max 50000

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            return mid;
        }

        if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n = Max;
    int a[n];


    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;  // Random numbers between 0 and 999
        //cout << a[i] << " ";   // Display the generated numbers
    }
    //cout << endl;

    // Sort the array before performing binary search
    sort(a, a + n);

    // Display the sorted array
    //cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        //cout << a[i] << " ";
    }
    //cout << endl;

    // Input the key to search
    int key;
    //cout << "Enter the key to search: ";
    //cin >> key;
    key=a[Max/2];
    // Call the binary search function
    int result = binarySearch(a, n, key);

    if (result != -1)
    {
        //cout << "Element found at index " << result << endl;
    }
    else
    {
        //cout << "Element not present in the array." << endl;
    }

    return 0;
}
