#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

#define Max 50000

void Search(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[n/2])
        {
            //cout<<"element found at index "<<i<<" is "<<a[i]<<endl;
            break;
        }
    }
    /*if(f!=1)
        cout<<"element not found"<<endl;*/
}
int main()
{
    int key = Max/2,n=Max;
    int a[n];

    srand(time(0));
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%1000;
    }

    Search(a,n);

    return 0;
}
