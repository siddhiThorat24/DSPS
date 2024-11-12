#include<iostream>
#include<string>
using namespace std;

struct node{
    string name;
    int id,cont;
    float amount;
    struct node*next;
};
node *head=0;
node *newnode, *temp;

void insertFirst(){
    newnode = new node;
    cout<<"Enter Donor's Name:";
    cin>>newnode->name;
    cout<<"Enter Donor's ID:";
    cin>>newnode->id;
    cout<<"Enter Donation Amount:";
    cin>>newnode->amount;
    cout<<"Enter Donor's Contact No.:";
    cin>>newnode->cont;
    newnode->next=head;
    head=newnode;
}

void insertAfter(){
    int pos,i=1,count=0;
    cout<<"Enter Position after which you want to insert node:";
    cin>>pos;
    temp=head;
    while(temp!=0){
        temp=temp->next;
        count++;
    }
    if(pos>count){
        cout<<"Invalid Position";
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode=new node;
        newnode = new node;
        cout<<"Enter Donor's Name:";
        cin>>newnode->name;
        cout<<"Enter Donor's ID:";
        cin>>newnode->id;
        cout<<"Enter Donation Amount:";
        cin>>newnode->amount;
        cout<<"Enter Donor's Contact No.:";
        cin>>newnode->cont;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void insertLast(){
    newnode = new node;
    cout<<"Enter Donor's Name:";
    cin>>newnode->name;
    cout<<"Enter Donor's ID:";
    cin>>newnode->id;
    cout<<"Enter Donation Amount:";
    cin>>newnode->amount;
    cout<<"Enter Donor's Contact No.:";
    cin>>newnode->cont;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=0;
}
void deleteFirst(){
    if(head==0){
        cout<<"SLL is Empty";
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteAtPostion(){
    if(head==0){
        cout<<"SLL is Empty";
    }
    else{
        node *nextnode;
        int pos,i=1;
        cout<<"Enter the Position Node to be deleted:";
        cin>>pos;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode); 
    }
}
void deleteLast(){
    if(head==0){
        cout<<"SLL is Empty";
    }
    else{
        node *prevnode;
        temp=head;
        while(temp->next!=0){
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=0;
        free(temp);
    }
}
void display(){
    temp=head;
    while(temp!=0){
        cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->amount<<"\t"<<temp->cont<<endl;
        temp=temp->next;
    }
}

int main(){
    int c,ch;
    node *head, *newnode, *temp;
    do{
        cout<<"\n1.Insert At First\n2.Insert After\n3.Insert Last\n4.Delete First\n5.Delete At Position\n6.Delete Last\n7.Display\nEnter your choice:";
        cin>>ch;
        switch(ch){
            case 1:insertFirst();
                break;
            case 2:insertAfter();
                break;
            case 3:insertLast();
                break;
            case 4:deleteFirst();
                break;
            case 5:deleteAtPostion();
                break;
            case 6:deleteLast();
                break;
            case 7:cout<<"ID\tName\tAmount\tContact No."<<endl;
                display();
                break;
            default:cout<<"Invalid Choice";
        }
        cout<<"\nEnter 1 to continue:";
        cin>>c;
    }while(c == 1);
}