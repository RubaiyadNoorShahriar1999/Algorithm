#include<iostream>
#include<limits>
using namespace std;
int MatrixChainMultiplication(int p[], int n)
{   int count=0;
    int m[n][n];
    // s matrix
    int s[n][n];
    int i, j, k, L, q;

    count=count+3;
    for (i=1; i<=n; i++)
    {
        m[i][i] = 0;
       count=count +3;
    }
       count=count+3;
    for (L=2; L<=n; L++)
    {
        cout<<endl;
        cout<<"Simulation"<<endl;
        cout<<"len="<<L<<endl;

        count=count+4;
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;

            m[i][j] = INT_MAX;//assigning to maximum value
           count=count+6;
           cout<<"m["<<i<<","<<j<<"]"<<endl;
           count=count+4;
            for (k=i; k<=j-1; k++)
            {
                 //simulation

                cout<<"m["<<i<<","<<k<<"]"<<"=";
                cout<<m[i][k]<<"+"<<m[k+1][j]<<"+"<<p[i-1]*p[k]*p[j]<<"=";
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                // print q
                 cout<<q<<endl;

                 count=count+14;

                if (q < m[i][j])
                {
                 cout<<q<<"<"<<m[i][j]<<"=";
                 m[i][j] = q;

                 cout<<q<<endl;

                  s[i][j]=k;

                count=count+9;
                }
            }
            }
    }
  cout<<endl;
  // print M and s matrix
    for(int i=1; i<= n; i++)
        {
        for(int j=1; j<=n; j++)
            {
                if(i<j)
                {
                   cout<<m[i][j]<<"\t";
                }
            }
        cout<<endl;
        }
 for(int i=1; i<= n; i++)
        {
        for(int j=1; j<=n; j++)
            {
                if(i<j)
                {
                   cout<<s[i][j]<<"\t";

                }
            }
        cout<<endl;
        }
    // show the split
for (L=2; L<=n; L++)
    {
    for (i=1; i<=n-L+1; i++)
        {

            cout<<"M"<<i<<"-"<<"M"<<j<<endl;

        for (k=i; k<=j-1; k++)
            {   //simulation
                cout<<"["<<"M"<<i<<"-"<<"M"<<k<<"] =";

                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

             // print q
                 cout<<q<<endl;
            }
        }
    }
    // print operation counts
    cout<<"The time complexity is  "<< count<<endl;
    return m[1][n];


}

int main()
{
    int n=6,i;
    int arr[7]={20,15,15,5,10,5,25};
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, n);

    return 0;
}
