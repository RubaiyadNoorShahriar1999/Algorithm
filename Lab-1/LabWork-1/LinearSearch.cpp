#include<iostream>
using namespace std;
void linearSearch(int num, int arr[], int mark)
{
    int opCounter=0;
    int i=0;
    opCounter++;//i=0
    //Search
    while(i<num && arr[i]!=mark)
    {
        opCounter=opCounter+4;//i<num && arr[i]!=mark
        i=i+1;
        opCounter=opCounter+2;//i=i+1
    }
    opCounter=opCounter+4;//when (i<num && arr[i]!=mark) false
    //Output
    if(arr[i]!=mark)
    {
        opCounter=opCounter+2;//arr[i]!=mark
        cout<<endl<< "Mark not Found"<<endl;
    }
    else{cout<<mark<< " mark is found in subject number "<<(i+1)<<endl;}
    cout<<"The time complexity is "<<opCounter<<endl;
}

int main ()
{
    /*
    //pre-defined input
    int mark;
    int arr[]={12,17,19,11,10,8,15,7,13,12,6,14};
    int num=12;
    */

    //user defined input
    int arr[100], i, mark, num;
    cout<<"Enter the number of subject: ";
    cin>>num;
    cout<<endl<<"Enter marks: "<<endl;
    for(i=0;i<num;i++)
    {
        cout<<"Enter marks of subject "<<(i+1)<<" : ";
        cin>>arr[i];
    }

    cout<<endl<<"Enter the mark you want to search: ";
    cin>>mark;
    linearSearch(num, arr, mark);
}
