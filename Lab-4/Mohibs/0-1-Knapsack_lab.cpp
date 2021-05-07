#include <iostream>
using namespace std;

int com;

int getMax(int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void Knapsack(int n,  int w[], int b[], int W)
{
    com=0;
    // defining a matrix to store result
    int B[n+1][W+1];
    int i,wt;

    com=com+2;

    // initialize 0 to first row where i=0
    com=com+1+2*(W+1);
    for(wt=0; wt<=W; wt++)
    {
        B[0][wt]=0;
        com=com+3;
    }

    // initialize 0 to first column where w=0
    com=com+1+2*(n+1);
    for(i=0; i<=n; i++)
    {
        B[i][0]=0;
        com=com+3;
    }

    // to consider each item i=1,i=2, i=3, so on
    com=com+1+2*(n-1);
    for(i=1; i<=n; i++)
    {
        // to consider each capacity 1 to M
        com=com+1+2*W;
        for(wt=1; wt<=W; wt++)
        {
            if(w[i]<=wt)
            {
                com=com+2;
                B[i][wt] = getMax(B[i-1][wt], b[i] + B[i-1][wt - w[i]]);
                com=com+13;
            }
            else
            {
                B[i][wt]= B[i-1][wt];
                com=com+6;
            }
        }
    }
    //////
    cout<<"\nMatrix"<<endl;
    com=com+1+2*(n+1);
    for(int i=0; i<= n; i++)
    {
        com=com+1+2*W;
        for(int j=1; j<=W; j++)
        {
            cout<<B[i][j]<<"\t";
            com = com+2;
        }
        cout<<endl;
    }
    cout<<"\nMaximum profit: "<<B[n][W]<<endl;
    com = com+2;

    // finding including items
    int r = B[n][W];
    com = com+3;
    cout<<"\nItems included are listed below:\n";
    com = com+1+2*n;
    for(int item = n; item >0; item--)
    {
        bool found =false;
        com++;
        com=com+1+2*(W+1);
        for(int j=0; j<= W; j++)
        {
            if(B[item-1][j] == r)
            {
                found =true;
                com=com+5;
            }
        }

        if(found == false)
        {
            cout<<"Item : "<< item << ", Profit : "<< b[item] << "\n";
            r = r - b[item];
            com=com+5;
        }
    }
}
int main()
{
    int i,number_of_items,capacity;

    cout<<"Enter number of items: ";
    cin>>number_of_items;

    int weights[number_of_items];
    int benefits[number_of_items];

    cout<<"Enter Knapsack Capacity: ";
    cin>>capacity;

    for(i=1; i<=number_of_items; i++)
    {
        cout<<"Enter weight for item "<<i<<": ";
        cin>>weights[i];
        cout<<"Enter benefit for item "<<i<<": ";
        cin>>benefits[i];
    }
    Knapsack(number_of_items,weights,benefits,capacity);

    cout<<endl<<"Time Complexity: "<<com<<endl;

    return 0;
}
