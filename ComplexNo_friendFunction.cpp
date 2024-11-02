#include<iostream>
using namespace std;
class complex{
    public:
    int real;
    int imag;
    complex(){
        real=0;
        imag=0; 
    }
    complex(complex &obj1,complex &obj2){
        real=obj1.real;
        imag=obj2.imag;
    }
    void input(){
        cout<<"Enter the value of real part:";
        cin>>real;
        cout<<"Enter the value of imag part:";
        cin>>imag;

    }
    void display(){
        cout<<"Complex Number is :"<<real<<" + "<<imag<<" i "<<endl;
    }
    friend complex operator+(complex &x,complex &y);
};
  complex operator+(complex &x,complex &y){
     complex temp;
        temp.real=x.real+y.real;
        temp.imag=x.imag+y.imag;
        return temp;
 }
    complex operator-(complex &x,complex &y){
    complex temp;
    temp.real=x.real-y.real;
    temp.imag=x.imag-y.imag;
      return temp;
   }
    complex operator*(complex &x,complex &y){
    complex temp;
     temp.real= x.real * y.real - x.imag * y.imag;
     temp.imag=x.real * y.imag + x.imag * y.real;
       return temp;
   }
   complex operator/(complex &x,complex &y){
    complex temp;
     temp.real= (x.real * y.real + x.imag * y.imag)/((y.real*y.real)+(y.imag*y.imag));
     temp.imag= (x.imag * y.real - x.real * y.imag)/((y.real*y.real)+(y.imag*y.imag));
       return temp;
   }


 
int main(){
    complex obj1,obj2,obj3;
    int ch,c;
    do{
        cout<<"\nMenu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:obj1.input();
                   obj2.input();
                   obj3=obj1+obj2;
                   obj3.display();
                   break;
            case 2:obj1.input();
                   obj2.input();
                   obj3=obj1-obj2;
                   obj3.display();
                   break;
            case 3:obj1.input();
                   obj2.input();
                   obj3=obj1*obj2;
                   obj3.display();
                   break;
            case 4:obj1.input();
                   obj2.input();
                   obj3=obj1/obj2;
                   obj3.display();
                   break;
            default:cout<<"Invalid Choice"<<endl;
        }
        cout<<"If you want to continue Enter 1:";
        cin>>c;
    }while(c==1);
    return 0;
}