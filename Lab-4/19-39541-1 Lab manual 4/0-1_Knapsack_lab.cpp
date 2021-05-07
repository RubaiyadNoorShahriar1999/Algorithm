#include <iostream>
using namespace std;

int counter=0;

void Knapsack(int n,  int w[], int b[], int W)
{

    int B[n+1][W+1];
    int i,wt;
    counter++;

    for(wt=0; wt<=W; wt++)
    {
        B[0][wt]=0;
        counter=counter+6;
    }


    counter++;
    for(i=0; i<=n; i++)
    {
        B[i][0]=0;
        counter=counter+6;
    }


    for(i=1; i<=n; i++)
    {
        counter=counter+3;
        for(wt=1; wt<=W; wt++)
        {
            counter=counter+3;
            if(w[i]<=wt)
            {
                counter=counter+2;
                counter=counter+11;
                if((b[i]+B[i-1][wt-w[i]])>B[i-1][wt])
                {

                    B[i][wt]=b[i]+B[i-1][wt-w[i]];
                    counter=counter+10;

                }
                else

                    B[i][wt]= B[i-1][wt];
                    counter=counter+6;

            }
                else

                    B[i][wt]= B[i-1][wt];
                    counter=counter+6;

        }
    }


        cout<<"Matrix"<<endl;
        for(int i=0; i<= n; i++)
         {
            for(int j=1; j<=W; j++)
            {
                cout<<B[i][j]<<endl;
            }

        }
        cout<<"Max profit:"<<B[n][W]<<endl;


    int r = B[n][W];
    cout<<"Items included are listed below:"<< endl;

    for(int item = n; item >0; item--)
    {
        bool found =false;

        for(int j=0; j<= W; j++)
            {
                if(B[item-1][j] == r)
            {
                found =true;
            }
        }


        if(found == false)
        {
            cout<<"Item : "<< item << ", Profit : "<< b[item] << endl;
            r = r - b[item];
            cout<<"Time Complexity :"<< counter;
        }
    }
}

int main()
{

    int number_of_items=5;
    int weights[]={0,2,3,5,6,7};
    int benefits[]={0,6,7,14,23,15};
    int Capacity = 8;
    Knapsack(number_of_items,weights,benefits,Capacity);
}
