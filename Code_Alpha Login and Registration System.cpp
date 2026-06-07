#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===== Check if username already exists =====
bool usernameExists(string username) {
    ifstream file("users.txt");
    if (!file.is_open()) return false;

    string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// ===== REGISTER FUNCTION =====
void registerUser() {
    string username, password;

    cout << "\n===== Register =====" << endl;
    cout << "Enter username (no spaces): ";
    cin >> username;

    if (username.empty()) {
        cout << "Username cannot be empty!" << endl;
        return;
    }

    if (usernameExists(username)) {
        cout << "Username already exists! Please choose another." << endl;
        return;
    }

    cout << "Enter password (min 6 characters, no spaces): ";
    cin >> password;

    if (password.length() < 6) {
        cout << "Password too short! Must be at least 6 characters." << endl;
        return;
    }

    ofstream file("users.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: Could not open file!" << endl;
        return;
    }

    file << username << " " << password << "\n";
    file.close();

    cout << "Registration Successful! Welcome, " << username << "!" << endl;
}

// ===== LOGIN FUNCTION =====
void loginUser() {
    string username, password;

    cout << "\n===== Login =====" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (!file.is_open()) {
        cout << "No users registered yet! Please register first." << endl;
        return;
    }

    string storedUser, storedPass;
    bool found = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login Successful! Welcome back, " << username << "!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

// ===== MAIN MENU =====
int main() {
    int choice;

    cout << "=============================" << endl;
    cout << "  Login & Registration System" << endl;
    cout << "=============================" << endl;

    do {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1/2/3): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number!" << endl;
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Goodbye! See you next time." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }

    } while (choice != 3);

    return 0;
}
