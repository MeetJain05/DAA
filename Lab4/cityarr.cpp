#include <bits/stdc++.h>
using namespace std;

#define MAX_CITIES 100

struct City {
    string name;
    double x, y;
};

City cities[MAX_CITIES];
int size = 0;

void insertCity() {
    if (size >= MAX_CITIES) {
        cout << "Database is full. Cannot insert more cities.\n";
        return;
    }
    string name;
    double x, y;
    cout << "Enter city name: ";
    cin >> name;
    cout << "Enter x and y coordinates: ";
    cin >> x >> y;
    cities[size++] = {name, x, y};
    cout << "City added successfully.\n";
}

void deleteByName() {
    string name;
    cout << "Enter city name to delete: ";
    cin >> name;
    for (int i = 0; i < size; i++) {
        if (cities[i].name == name) {
            cities[i] = cities[size - 1]; 
            size--;
            cout << "City deleted successfully.\n";
            return;
        }
    }
    cout << "No city found with name: " << name << endl;
}

void deleteByCoordinates() {
    double x, y;
    cout << "Enter x and y coordinates to delete: ";
    cin >> x >> y;
    for (int i = 0; i < size; i++) {
        if (cities[i].x == x && cities[i].y == y) {
            cities[i] = cities[size - 1]; 
            size--;
            cout << "City deleted successfully.\n";
            return;
        }
    }
    cout << "No city found at coordinates: (" << x << ", " << y << ")\n";
}

void searchByName() {
    string name;
    cout << "Enter city name to search: ";
    cin >> name;
    for (int i = 0; i < size; i++) {
        if (cities[i].name == name) {
            cout << "City found: " << cities[i].name << " (" << cities[i].x << ", " << cities[i].y << ")\n";
            return;
        }
    }
    cout << "No city found with name: " << name << endl;
}

void searchByCoordinates() {
    double x, y;
    cout << "Enter x and y coordinates to search: ";
    cin >> x >> y;
    for (int i = 0; i < size; i++) {
        if (cities[i].x == x && cities[i].y == y) {
            cout << "City found: " << cities[i].name << " (" << cities[i].x << ", " << cities[i].y << ")\n";
            return;
        }
    }
    cout << "No city found at coordinates: (" << x << ", " << y << ")\n";
}

void printWithinDistance() {
    double x, y, d;
    cout << "Enter x and y coordinates and distance: ";
    cin >> x >> y >> d;
    cout << "Cities within distance " << d << " from (" << x << ", " << y << "):\n";
    for (int i = 0; i < size; i++) {
        double dist = sqrt(pow(cities[i].x - x, 2) + pow(cities[i].y - y, 2));
        if (dist <= d) {
            cout << cities[i].name << " (" << cities[i].x << ", " << cities[i].y << ")\n";
        }
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert city\n2. Delete by name\n3. Delete by coordinates\n";
        cout << "4. Search by name\n5. Search by coordinates\n6. Print cities within distance\n";
        cout << "7. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertCity(); break;
            case 2: deleteByName(); break;
            case 3: deleteByCoordinates(); break;
            case 4: searchByName(); break;
            case 5: searchByCoordinates(); break;
            case 6: printWithinDistance(); break;
            case 7: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
