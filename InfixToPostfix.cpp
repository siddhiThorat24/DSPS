#include<iostream>
using namespace std;
char stack[20];
int top=-1;
void push(char x){
    top++;
    stack[top]=x;
}

char pop(){
    return stack[top--];
}

int precedence(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    else{
        return -1;
    }
}

int main(){
    char x,c,a[10];
    int i;
    cout<<"Enter Infix Expression:";
    cin>>a;
    cout<<"The Postfix Expression is:";
    for(i=0;a[i]!='\0';i++){
        c=a[i];
        if(precedence(c)>0){
            while(top!=-1 && precedence(stack[top])>=precedence(c)){
                cout<<pop();
            }
            push(c);
        }
        else if(c==')'){
            x=pop();
            while(x!='('){
                cout<<x;
                x=pop();
            }
        }
        else if(c=='('){
            push(c);
        }
        else{
            cout<<c;
        }
    }
    for(i=0;i=top+1;i++){
        cout<<pop();
    }
    return 0;
}