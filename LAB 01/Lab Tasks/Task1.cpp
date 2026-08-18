#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the no of elements in an array : "<<endl;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>> *(arr+i);
    }

    int sum=0;
    int max=*arr,min=*arr;

    for(int i=0;i<n;i++){
        int value=*(arr+i);
        sum+=value;
        if(value>max){
            max=value;
        }

        if(value<min){
            min=value;
        }
    }
    double avg;
    avg=sum/n;
    cout<<endl;
    cout<<"Sum : "<<sum<<endl;
    cout<<"Average : "<<avg<<endl;
    cout<<"Maximum : "<<max<<endl;
    cout<<"Minimum : "<<min<<endl;
    
    delete[] arr;
    return 0;
}