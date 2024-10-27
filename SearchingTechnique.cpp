/*#include<iostream>
using namespace std;
void linear(int a[],int n){
    int key,i,pos,flag=0; 
    cout<<"Enter key element:";
    cin>>key;
    for(i=0;i<n;i++){
        if(key==a[i]){
            pos=i;
            flag=1;
        }
    }
    if(flag==1){
        cout<<key<<" is present at "<<pos<<" position";
    }
    else{
        cout<<key<<" is not present in given array:";
    }
}

int main(){
    int a[10],n,i;
    cout<<"Enter No. of elements in array:";
    cin>>n;
    cout<<"Enter Elements in the array :";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    linear(a,n);
    return 0;
}
*/
#include<iostream>
using namespace std;
void linear(int a[],int n){
    int key,i,flag=0,pos; 
    cout<<"Enter key element to be Search:";
    cin>>key;
    for(i=0;i<n;i++){
        if(key==a[i]){
            pos=i;
            flag=1;
        }
    }
    if(flag==1){
        cout<<key<<" is present at "<<pos<<" position";
    }
    else{
        cout<<key<<" is not present in given array:";
    }
}

void binary(int a[],int n){
    int low,high,mid,key;
    cout<<"Enter array element to be Search:";
    cin>>key;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==key){
            cout<<key<<" is present at "<<mid<<" position";
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
        cout<<key<<" is not present in given array:";
    }
}

int main(){
    int a[10],n,i,ch,c;
    cout<<"Enter array size:";
    cin>>n;
    cout<<"Enter array elements:";
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