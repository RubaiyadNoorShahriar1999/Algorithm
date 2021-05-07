#include <iostream>
using namespace std;

void binary_search(int A[], int target)
{
  int lo = 0;
  int hi = sizeof(A);
  int Counter=0;
  Counter = Counter+2;     //hi = sizeof(A)

  while (lo <= hi)
  {
    Counter++;           //lo <= hi
    int mid = lo + (hi-lo)/2;

    Counter = Counter+6; //mid = lo + (hi-lo)/2&A[mid] == target or A[mid] < target

    if (A[mid] == target)
    {
        cout<<"Answer: "<< A[mid] <<" Found";

        cout<<endl<<"The time complexity of the snippet: "<<"  "<<Counter;

        break;
    }
    else if (A[mid] < target)
        {
            lo = mid+1;

            Counter= Counter+2;   //lo = mid+1
        }
    else
        {
            hi = mid-1;
            Counter= Counter+2;   //hi = mid-1
        }
  }
            Counter++;            //when (lo <= hi) false
}

int main()
{
    int i,n,target;
    int A[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    cout<<"Enter the number you want to find: ";
    cin>> target;

    binary_search(A, target);
}
