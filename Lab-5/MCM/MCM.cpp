#include<iostream>
#include<limits>

using namespace std;

int MatrixChainMultiplication(int p[], int n)
{
    int count=0;
    int m[n][n];
    // s matrix
    int s[n][n];
    int i, j, k, L, q;

    for (i=1; i<=n; i++)
        {
            count=count+3;
            m[i][i] = 0;
        }

    count= count+3;
    for (L=2; L<=n; L++)
    {
            count= count+3;

        for (i=1; i<=n-L+1; i++)
        {
                count= count+5;
                j = i+L-1;
                count= count+3;
                m[i][j] = INT_MAX; //assigning to maximum value
                count= count+3;

            for (k=i; k<=j-1; k++)
                {

                count= count+4;
                //simulation
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                count= count+14;
                // print q

                if (q < m[i][j])
                {
                    count= count+3;
                    m[i][j] = q;
                    count= count+3;
                    // s matrix
                    s[i][j]=k;
                    count= count+3;
                }
            }
        }
    }
    // print M and s matrix

    // show the split


    // print operation counts
    cout<<"The time complexity is\n  "<< count;
    return m[1][n];
}

int main()
{
    int n=6,i;
    int arr[7]={35,30,15,5,10,20,25};
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, n)<<endl;
    return 0;
}
