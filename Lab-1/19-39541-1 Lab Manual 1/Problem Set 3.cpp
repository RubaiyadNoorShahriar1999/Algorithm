#include<iostream>
using namespace std;

void DisplayArray(int *array, int s){
    cout<<endl;
    for(int i=1 ; i<=s; i++){
        cout<< array[i] <<" ";
    }
    cout<<endl;
}

int GetMaxElement(int *array, int s){
    int m = array[1];
    for(int i = 2; i <=s; i++){
        if(array[i] > m){
            m = array[i];
        }
    }
    return m ;
}

void CountSort(int *array, int s ){
    int counter=0;
    int B[s+1];

    int mx = GetMaxElement( array , s);

    int C[mx+1];

    int i,j;
    counter++;   //for i=0
    for(i=0 ; i<=mx ; i++){
   counter=counter+2;   //i<=mx ; i++
        C[i] = 0;
        counter=counter+2;  //C[i] = 0
    }
    for(j = 1 ; j <= s ; j++){
             counter=counter+3;  //j = 1 ; j <= s ; j++
        C[array[j]]++;
          counter=counter+3;  //C[array[j]]++
    }
    for( i = 1 ; i <= mx ; i++){
              counter=counter+3;  //i = 1 ; i <= mx ; i++

        C[i]= C[i]+C[i-1];
      counter=counter+4;  //C[i]= C[i]+C[i-1]
    }
    for( j = s ; j >=1 ; j--){
      counter=counter+3;  //j = s ; j >=1 ; j--
        B[C[array[j]]]= array[j];
        counter=counter+4;  // B[C[array[j]]]= array[j]
        C[array[j]]= C[array[j]]-1;
        counter=counter+6;  //C[array[j]]= C[array[j]]-1
    }

    int K[s+1];
        counter=counter+2; //int K[s+1]
    for(int i=1 ; i<=s; i++){
        counter=counter+3;  //int i=1 ; i<=s; i++
        K[i] = B[i];
        counter=counter+3;  //K[i] = B[i]
    }
    for(i=s,j=1; i>=1;i--,j++)
   {    counter=counter+5;  //i=s,j=1; i>=1;i--,j++
        array[i]=K[j];
        counter=counter+3;  //array[i]=K[j]
   }
cout<< "time complexity is "<<counter;
}

int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int A[n+1];
    for(int i = 1 ; i<=n ; i++){
        cin>>A[i];
    }

    DisplayArray( A , n );

    CountSort( A , n );

    DisplayArray( A , n );

}
