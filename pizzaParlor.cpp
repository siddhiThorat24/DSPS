#include<iostream>
#include<string>
using namespace std;

class Pizza{
    public:
        int id;
        float price;
        string pizza_type;
        int queue[30], r, f, ele;
        string type[30];
        float pizza_price[30];

        Pizza(){
            r=-1;
            f=-1;
        }
        
        void details(){
            cout<<"Enter the id of pizza:";
            cin>>id;
            cout<<"Enter the type of Pizza:";
            cin>>pizza_type;
            cout<<"Enter the price of Pizza:";
            cin>>price;
        }

        void display()
        {
        
            int i,n;
            if (f == r)
            {
                cout << "Nothing for Placed and served" << endl;
            }
            else
            {
                cout << "Served Pizzas are :" << endl;
                for (i = f + 1; i <= r; i++)
                {
                    cout << queue[i] << ":" << type[i] <<pizza_price[i]<< endl;
                }
            }
        }

        void enqueue(int n, int ele, string pizza_type,float price)
        {
            
            if (r == n - 1)
            {
                cout << "order is full" << endl;
            }
            else
            {
                r++;
                queue[r] = ele;
                type[r] = pizza_type;
                pizza_price[r]=price;
                cout << "Placed Ordered is " << type[r] << " pizza with order no " << queue[r] << endl;
                cout << "Price of Pizza is :" << pizza_price[r] << endl;
            }
        }

        void dequeue()
        {
            
            if (r == f)
            {
                cout << "order is empty" << endl;
            }
            else
            {
                f++;
                cout << "served order is  :" << queue[f] << " : " << type[f] << "Pizza" << "Price is :" << pizza_price[f] << endl;
            }
        }

};

int main()
{
    Pizza p;
    int ch, c, n, ele;
    string pizza_type;
    float price;

    cout << "Enter the no of order that pizza parlor can take: ";
    cin >> n;

    do
    {
        cout << "\nMenu:\n1. Place the order\n2. Serve the order\n3. Display the current orders\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            p.details();
            p.enqueue(n, p.id, p.pizza_type, p.price);
            break;
        case 2:
            p.dequeue();
            break;
        case 3:
            p.display();
            break;
        case 4:
            break;
        default:
            cout << "Wrong choice! Please try again." << endl;
        }

        cout << "If you want to continue for placing and serving orders, enter 1: ";
        cin >> c;

    } while (c == 1);

    return 0;
}
