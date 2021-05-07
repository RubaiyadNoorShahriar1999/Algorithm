#include<iostream>
#include<limits>
using namespace std;
int MatrixChainMultiplication(int p[], int n)
{
    int count=0;
    int m[n][n], s[n][n];
    // s matrix
    int i, j, k, L, q;
    for (i=1; i<=n; i++)
        m[i][i] = 0;
    for (L=2; L<=n; L++)
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX; //assigning to maximum value
            for (k=i; k<=j-1; k++)
            {
                //simulation
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                cout<<"M["<<i<<","<<j<<"]="<<q<<"    k="<<k<<endl;
                // print q
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                    // s matrix
                }
            }
        }
    }
    // print M and s matrix
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            m[i][j]=0;
        }
    }
    cout<<"\nMatrix M"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            s[i][j]=0;
        }
    }
    cout<<"\nMatrix S"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<s[i][j]<<"\t";
        }
        cout<<endl;
    }

    // show the split


    // print operation counts

    cout<<endl;
    return m[1][n];
}

int main()
{
    int n=6,i;
    //int arr[7]={35,30,15,5,10,20,25};
    int arr[7]={30,35,15,5,10,20,25};
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, n);
    return 0;
}
