#include<iostream>
#include<limits>

using namespace std;

int MatrixChainMultiplication(int p[], int n)
{
    int counter = 0;
    int M[n][n];
    // s matrix
    int s[n][n];
    int i, j, k, L, q;


    for (i=1; i<=n; i++)
        {
            counter = counter+3;
            M[i][i] = 0;
        }
            counter = counter+3;
    for (L=2; L<=n; L++)
    {
         counter = counter+3;

        for (i=1; i<=n-L+1; i++)
        {
            counter = counter+5;

            j = i+L-1;
            counter = counter+3;

            M[i][j] = INT_MAX; //assigning to maximum value
            counter = counter+3;

            for (k=i; k<=j-1; k++)
            {
                counter = counter+4;

                //simulation
                q = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
                counter = counter+14;

                // print q
                if (q < M[i][j])
                {
                    counter = counter+3;

                    M[i][j] = q;
                    counter = counter+3;

                    // s matrix
                    s[i][j]=k;
                    counter = counter+3;
                }
            }
        }
    }
    // print M and s matrix
    cout<<endl;

    for(int i=1; i<= n; i++)
        {
        for(int j=1; j<=n; j++)
            {
                if(i<j)
                {
                   cout<<M[i][j]<<"\t";

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


    // print operation counts
    return M[1][n];
}

int main()
{
    int n=6,i;
    int arr[7]={35,30,15,5,10,20,25};
    cout<<"Minimum number of multiplications is\n "<<MatrixChainMultiplication(arr, n);
    return 0;
}
