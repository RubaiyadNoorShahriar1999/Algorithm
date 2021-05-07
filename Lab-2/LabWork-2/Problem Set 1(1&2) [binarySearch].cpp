#include <iostream>
using namespace std;

void binary_search(int A[], int target)
{
  int lo = 0, hi = sizeof(A), opCounter=0;
  opCounter=opCounter+2;//hi = sizeof(A)
  while (lo <= hi)
  {
    opCounter++;//lo <= hi
    int mid = lo + (hi-lo)/2;
    opCounter=opCounter+6;//mid = lo + (hi-lo)/2,A[mid] == target or A[mid] < target
    if (A[mid] == target)
    {
        //output
        cout<<endl<<"Answer : "<<A[mid]<<" Found. "<<endl;
        cout<<endl<<"The time complexity is "<<opCounter<<"."<<endl;
        break;
    }
    else if (A[mid] < target)
        {
            lo = mid+1; opCounter=opCounter+2;//lo = mid+1
        }
    else
        {
            hi = mid-1; opCounter=opCounter+2;//hi = mid-1
        }
  }
  opCounter++;//when (lo <= hi) false
}

int main()
{
    int i,n,target, A[]={1,2,3,4,5,6,7,8,9};

    cout<<"Enter the number you want to find(from 1 to 9): ";
    cin>>target;

    //function calling
    binary_search(A, target);
}
