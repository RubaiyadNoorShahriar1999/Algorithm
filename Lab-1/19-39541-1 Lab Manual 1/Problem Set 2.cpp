#include <iostream>

using namespace std;


int SWAP(float x , float y){  //Swapping method
    float t = x;
    x=y;
    y=t;
}
void bubble( float a[], int n){
    int pass, j, flag,counter=0;

    counter++; //counter=0
    counter++; //pass=1

    for(pass=1;pass<n;pass++){
        counter= counter+2; //pass<n;pass++
        flag = 0;
        counter= counter+2; //flag=0;j=0
    for(j=0; j<(n-pass) ; j++)
    {
        counter= counter+3; //j<(n-pass) ; j++
        if(a[j] > a[j+1]){
           counter=counter+4;  //a[j] > a[j+1]
           SWAP(a[j+1],a[j]);
           counter= counter+8; //SWAP(a[j+1],&a[j]);
           flag=1 ;
           counter++; //flag=1;
           }

           if(flag==0) {
                break;
                counter= counter+2; //flag==0 & break
                }
                counter++; // if j<(n-pass) is false
    }
}
        counter--; //counter is an extra variable
        cout<<"Time Complexity of Bubble Sort:" <<"  "<<counter<<"\n";
}


int main(){
 /*
 float a[7]={3.75,3.98,2.67,3.11,4.00,3.75,3.88};
 int n = sizeof(a)/ sizeof(a[0]);

 cout<<"The required Sorted list is:\n";
 bubble( a, n);
 for(int i=0; i<n ; i++){
    cout<< a[i]<< " "<< endl;
 }
*/
    int n;
    float a[40];
    cout<<"Enter the number of students, n: ";
    cin>>n;
    cout<<"\nEnter CGPA: \n"<<endl;
    for(int i=0;i<n;i++){
            cin>>a[i];
    }
    bubble(a,n);

    cout<<"\nSorted CGPA\n";
    for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
    }
    cout<<"\n";
    main();
return 0;
}
