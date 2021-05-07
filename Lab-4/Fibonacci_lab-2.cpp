#include <iostream>
using namespace std;

int count;

int FibRec(int n)
{
    count=0;
    if(n<=1)
    {
        count++;
        return n;
    }
    else
    {
        count=count+3;
        cout<< " FibRec("<<n-1<<") + FibRec("<<n-2<<")"<<endl;
        return FibRec(n-1)+ FibRec(n-2);
    }
}


int FibRecDP(int n, int a[])
{
    count=0;

    if(n<=1)
    {
        count++;
        cout<< "\n if 0 or 1 \n";
        return a[n];
    }
    if(a[n-1]==-1)
    {
        FibRecDP(n-1, a);
        cout<< "\nFibRecDP["<<n<<"-"<<"1]\n";

        count=count+4;
    }

    if(a[n-2]==-1)
    {
        FibRecDP(n-2, a);
        cout<< "\n if n-2 \n";
        count=count+4;
    }

    a[n]= a[n-1]+ a[n-2];
    count=count+8;

    return a[n];
}

int FibDPiterative(int n)
{
    count=0;

    if(n<=1)
    {
        count++;
        return n;
    }
    int a=0,b=1, r;

    count=count+2;

    count=count+1+2*n-2;

    for(int i=2; i<=n; i++)
    {

        cout<< "\n Iterative :"<< a <<" + "<<b <<"= ";
        r = a + b;
        count=count+2;

        a = b;
        count++;

        b = r;
        count++;
        cout<< r<<"\n";
    }
    return r;
}

int main()
{
    int number;
    cout<<"Which Fibonacci number? ";
    cin>>number;

    //WITHOUT MEMOIZATION
    cout<<"Fibonacci ("<<number<<") = "<< FibRec(number)<<endl;

    cout<<"\nTime Complexity (Without Memorization): "<<count<<endl<<endl;

    //WITH MEMOIZATION (recursive)
    int F[number+1];
    F[0]=0;
    F[1]=1;
    for(int i=2; i<=number; i++)
    {
        F[i]=-1;
    }
    cout<<"Fibonacci ("<<number<<") = "<< FibRecDP(number,F)<<endl;
    cout<<"Time Complexity (With Memorization): "<<count<<endl<<endl;

    //WITH MEMOIZATION (iterative)
    cout<<"Fibonacci ("<<number<<") = "<< FibDPiterative(number)<<endl;
    cout<<"Time Complexity (Without Memorization (iterative)): "<<count<<endl;
}
