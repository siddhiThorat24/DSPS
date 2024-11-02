#include<iostream>
using namespace std;
void linear(int a[],int n){
    int key,i,flag=0; 
    cout<<"Enter Roll No. to be Search:";
    cin>>key;
    for(i=0;i<n;i++){
        if(key==a[i]){
            flag=1;
        }
    }
    if(flag==1){
        cout<<"Roll No. "<<key<<" have attended training ";
    }
    else{
        cout<<"Roll No. "<<key<<" have not attended training ";
    }
}

void binary(int a[],int n){
    int low,high,mid,key;
    cout<<"Enter Roll No. to be Search:";
    cin>>key;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==key){
            cout<<"Roll No. "<<key<<" have attended training ";
            break;
        }
        else if(a[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    if(low>high){
        cout<<"Roll No. "<<key<<" have not attended training ";
    }
}

int main(){
    int a[10],n,i,ch,c;
    cout<<"Enter no. of Students:";
    cin>>n;
    cout<<"Enter Roll No. of Students (Sorted) :";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    do{
        cout<<"1.Linear Search\n2.Binary Search\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:linear(a,n);
                break;
            case 2:binary(a,n);
                break;
            default:"Invalid Choice";
        }
        cout<<"\n[Press 1 to Continue]:";
        cin>>c;
    }while(c==1);
    return 0;
}