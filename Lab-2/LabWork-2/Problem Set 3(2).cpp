#include <iostream>
using namespace std;

int long power (long x, long n)
{
    if (n==0){return 1;}
    if ((n%2)==0){return power(x,n/2)*power(x,n/2);}
    else{return x*power(x,n/2)*power(x,n/2);}
}

int main()
{
    //Outpit + function calling
     cout<<"The output of 'power (3,5)' is : "<<power(3,5)<<endl;
}
