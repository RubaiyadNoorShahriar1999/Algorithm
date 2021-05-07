#include<iostream>
using namespace std;
//find average of n numbers
int main(){
    int n,i;
    //input
    cout<<"Enter n:";
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }

    //average
    int opCounter=0;
    opCounter++;//sum=0
    float sum=0;


    opCounter++;//i=0
    for(i=0; i<n; i++){
        opCounter=opCounter+2;//i<n; i++
        sum = sum + a[i];
        opCounter=opCounter+3;//sum = sum + a[i]
    }
    opCounter++;// when i<n false

    float average = sum/n;
    opCounter=opCounter+2;//average = sum/n

    //output
    cout<<"The average is "<<average<<endl;
    cout<<"The time complexity is "<<opCounter<<endl;

    main();
}
