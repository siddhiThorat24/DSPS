#include <iostream> 
#include <string> 
using namespace std;
class Books 
{ 
    public:
    int price; 
    string name;
    void display() { 
    cout << name << "\t" << price << endl; }
    void sort(Books b[], int n){ 
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (b[j].price > b[j + 1].price) { 
                Books temp = b[j]; 
                b[j] = b[j + 1];
                b[j + 1] = temp;
                } 
            } 
        }
        cout << "Sorted book Price:"<<endl;
        for (int i = 0; i < n; i++) {
        cout << b[i].name << "\t" << b[i].price <<endl;;
        } 
    }
    void non_dups_arr(Books b[], int n) { 
        int newSize = 0;
        Books uniqueBooks[10]; 
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < newSize; j++) {
                if (b[i].price == uniqueBooks[j].price && b[i].name == uniqueBooks[j].name) {
                flag = 1;
                break;
                } 
            }
            if (flag == 0) {
            uniqueBooks[newSize] = b[i];
            newSize++; 
            }
        }
        cout << "Unique Books :"<<endl;
        for (int i = 0; i < newSize; i++) {
            cout << uniqueBooks[i].name <<"\t"<< uniqueBooks[i].price << "\n";
        } 
        cout << endl;
    }
    void non_dups_var(Books b[], int &n) { 
        int newIndex = 0; 
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = 0; j < newIndex; j++) {
                if (b[i].price == b[j].price && b[i].name == b[j].name) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                b[newIndex] = b[i];
                newIndex++;
            }
        }
        n = newIndex;
        cout << "Books after removing duplicates:"<<endl;
        for (int i = 0; i < n; i++) {
            b[i].display();
        } 
    } 
};

int main(){
    Books b[10]; 
    int less_price[10], more_price[10];
    string less_name[10], more_name[10];
    int less_count = 0,more_count = 0;
    int n, N = 0, choice, i,ch;
    do { 
        cout << "\n1.Insert details\n2.Books with price less than 500\n3.Books with price more than 500\n";
        cout << "4.Sorted price list\n5.New array with non-duplicate books\n6.Original array with non-duplicate books\n7.Display books\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:cout << "Enter no. of Books: "; 
                cin >> n;
                for (int i = N; i < n + N; i++) { 
                    cout << "Enter the name of book: ";
                    cin >> b[i].name;
                    cout << "Enter price of book: ";
                    cin >> b[i].price;
                    if (b[i].price < 500) { 
                        less_price[less_count] = b[i].price;
                        less_name[less_count] = b[i].name;
                        less_count++; 
                    }
                    else {
                        more_price[more_count] = b[i].price;
                        more_name[more_count] = b[i].name;
                        more_count++;
                    } 
                }
                N += n;
                break;
            case 2:cout << "Books with price less than 500:\n";
                for (int i = 0; i < less_count; i++) {
                    cout << less_name[i] << "\t" << less_price[i] << "\n";
                }
                cout<<"Count of Books= "<<less_count;
                break;
            case 3:cout << "Books with price more than 500:\n";
                for (int i = 0; i < more_count; i++) {
                    cout << more_name[i] << "\t" << more_price[i] << "\n";
                } 
                cout<<"Count of Books= "<<more_count;
                break;
            case 4:b[0].sort(b, N);
                break;
            case 5:b[0].non_dups_arr(b, N);
                break;
            case 6:b[0].non_dups_var(b, N);
                break;
            case 7:cout << "Name\tPrice\n";
                for(i = 0; i < N; i++) {
                    b[i].display(); 
                }
                break;
            default:cout << "Please enter a valid choice!!"; 
        }
        cout<<"\nEnter 1 to Continue:";
        cin>>ch;
    }while(ch==1);
    return 0;
} 