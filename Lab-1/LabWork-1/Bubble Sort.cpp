#include <iostream>
using namespace std;
void bubble (float arr[], int num)
{
    int pass,i;
    int opCounter=0;
    //sort
    opCounter++;//pass=1
    for(pass=1;pass<num;pass++)
    {
        opCounter=opCounter+2;//pass<num;pass++
        int flag=0;
        opCounter=opCounter+2;//flag=0;i=0
        for(i=0;i<(num-pass);i++)
        {
            opCounter=opCounter+3;//i<(num-pass);i++
            if(arr[i]>arr[i+1])
            {
                opCounter=opCounter+4;//arr[i]>arr[i+1]
                swap(arr[i+1],arr[i]);
                opCounter=opCounter+8;//swap(arr[i+1],arr[i])
                flag=1;
                opCounter++;//flag=1
            }
        }
        opCounter++;//when (i<(num-pass)) false
        if(flag==0)break;
        opCounter++;//flag==0
    }
    opCounter++;//when (pass<num) false
    cout<<endl<<"The time complexity is "<<opCounter<<endl;
}
int main()
{
    /*
    //pre-defined input
    int i;
    float arr[]={3.75,3.98,2.67,3.11,4.00,3.75,3.88};
    int num=7;
    cout<<"Uncorted CGPA"<<endl;
    for(i=0; i<num; i++)cout<<arr[i]<<"  ";
    */

    //user defined input
    int i,num;
    float arr[100];
    cout<<"Enter the number of student: ";
    cin>>num;
    cout<<endl<<"Enter CGPA: "<<endl;
    for(i=0;i<num;i++){cin>>arr[i];}

    //function calling
    bubble (arr,num);
    //output
    cout<<endl<<"Sorted CGPA"<<endl;
    for(i=0; i<num; i++)cout<<arr[i]<<"  ";
  }
