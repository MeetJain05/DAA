#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    double x, y;
    Node* next;

    Node(string name, double x, double y, Node* next = nullptr) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->next = next;
    }
};

Node* createNode(string name, double x, double y) {
    return new Node(name, x, y);
}

void inserthead(Node*& head, string name, double x, double y) {
    Node* temp = createNode(name, x, y);
    temp->next = head;
    head = temp;
}

void deleterec(Node*& head, string name) {
    Node* ptr = head;
    Node* prev = nullptr;

    while (ptr) {
        if (ptr->name == name) {
            if (ptr == head) {
                head = head->next;
                delete ptr;
            } else {
                prev->next = ptr->next;
                delete ptr;
            }
            cout << "Record deleted successfully.\n";
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    cout << "No record found with name: " << name << endl;
}

void deleteco(Node*& head, double x, double y) {
    Node* ptr = head;
    Node* prev = nullptr;

    while (ptr) {
        if (ptr->x == x && ptr->y == y) {
            if (ptr == head) {
                head = head->next;
                delete ptr;
            } else {
                prev->next = ptr->next;
                delete ptr;
            }
            cout << "Record deleted successfully.\n";
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    cout << "No record found at coordinates: (" << x << ", " << y << ")" << endl;
}

void printnode(Node* temp) {
    if (temp)
        cout << temp->name << " (" << temp->x << ", " << temp->y << ")\n";
}

void searchname(Node* head, string name) {
    Node* ptr = head;

    while (ptr) {
        if (ptr->name == name) {
            cout << "Record found: ";
            printnode(ptr);
            return;
        }
        ptr = ptr->next;
    }
    cout << "No record found with name: " << name << endl;
}

void searchco(Node* head, double x, double y) {
    Node* ptr = head;

    while (ptr) {
        if (ptr->x == x && ptr->y == y) {
            cout << "Record found: ";
            printnode(ptr);
            return;
        }
        ptr = ptr->next;
    }
    cout << "No record found at coordinates: (" << x << ", " << y << ")" << endl;
}

void printrec(Node* head, double x, double y, double d) {
    Node* ptr = head;
    bool found = false;

    cout << "Records within radius " << d << ":\n";
    while (ptr) {
        double dist = sqrt(pow(x - ptr->x, 2) + pow(y - ptr->y, 2));
        if (dist <= d) {
            printnode(ptr);
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found) cout << "No records found within the given radius.\n";
}

void displayAll(Node* head) {
    if (!head) {
        cout << "Database is empty.\n";
        return;
    }

    cout << "City Records:\n";
    while (head) {
        printnode(head);
        head = head->next;
    }
}

int main() {
    Node* cityList = nullptr;
    int choice;

    while (true) {
        cout << "\n1) Insert Record\n2) Delete by Name\n3) Delete by Coordinates\n";
        cout << "4) Search by Name\n5) Search by Coordinates\n6) Display All\n";
        cout << "7) Find Cities in Range\n8) Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 8) {
            cout << "Exiting...\n";
            break;
        }

        string name;
        double x, y, d;

        switch (choice) {
            case 1:
                cout << "Enter City Name: ";
                cin >> name;
                cout << "Enter Coordinates (x y): ";
                cin >> x >> y;
                inserthead(cityList, name, x, y);
                break;
            case 2:
                cout << "Enter City Name: ";
                cin >> name;
                deleterec(cityList, name);
                break;
            case 3:
                cout << "Enter Coordinates (x y): ";
                cin >> x >> y;
                deleteco(cityList, x, y);
                break;
            case 4:
                cout << "Enter City Name: ";
                cin >> name;
                searchname(cityList, name);
                break;
            case 5:
                cout << "Enter Coordinates (x y): ";
                cin >> x >> y;
                searchco(cityList, x, y);
                break;
            case 6:
                displayAll(cityList);
                break;
            case 7:
                cout << "Enter Reference Point (x y): ";
                cin >> x >> y;
                cout << "Enter Search Radius: ";
                cin >> d;
                printrec(cityList, x, y, d);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
