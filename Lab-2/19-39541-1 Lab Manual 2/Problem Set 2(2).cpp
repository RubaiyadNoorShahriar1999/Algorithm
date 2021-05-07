#include <iostream>

using namespace std;

int mystery(int n)
{
    if(n<=1){

        return 0;
    }

	else
    {
        int k=n;
		for(int i=1;i<n;i++){
                k=k+5;
        }
		return k*mystery(n/2)+8*mystery(n/4);
    }
}

int main()
{
     cout<<"The output of is: "<<mystery(10);
}
