#include<iostream>

using namespace std;

void LinearSearch(int A[],int n,int v){

      int i=0,counter=0;
      counter= counter+2;

      while(i<n && A[i]!= v){

        counter=counter+4;
        i= i+1;
        counter=counter+2;

      }
        counter=counter+4;

        if(A[i]!= v){

                counter=counter+2;
                cout<<"Not found\n";
        }
        else {cout<<"found\n";}
        cout<<"Time complexity of Linear Search Algorithm"<<counter;
}


int main(){

    /*int n=12,v;
    int A[n]= {12,17,19,11,10,8,15,7,13,12,6,14};
    cout<<"Enter the number you want to search:";
    cin>> v;
    cout<<"Search results:\n";
    LinearSearch(A,n,v);
    cout<<"\n";
    main();
    */

    int A[40],n,v;
    cout<<"Enter the number of subject: ";
    cin>>n;
    cout<<"Enter marks: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter marks of subject "<<(i+1)<<" : ";
        cin>>A[i];
    }

    cout<<"Enter the mark you want to search: ";
    cin>>v;
    LinearSearch(A,n,v);
    main();
}
