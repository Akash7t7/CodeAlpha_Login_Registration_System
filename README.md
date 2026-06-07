# CodeAlpha_Login_Registration_System
# Login & Registration System — CodeAlpha Internship Task 2

A simple C++ console application that allows users to register and login securely using file-based storage.

## Features
- User Registration with username and password
- Duplicate username check
- Password validation (minimum 6 characters)
- Secure login with credential verification
- Data stored in local file (users.txt)
- Success and error messages for all actions

## How to Compile & Run

g++ login_registration.cpp -o login_registration
./login_registration

## Example Output

==============================
  Login & Registration System
==============================

--- Main Menu ---
1. Register
2. Login
3. Exit
Enter your choice (1/2/3): 1

===== Register =====
Enter username (no spaces): ali
Enter password (min 6 characters): pass123
Registration Successful! Welcome, ali!

--- Main Menu ---
1. Register
2. Login
3. Exit
Enter your choice (1/2/3): 2

===== Login =====
Enter username: ali
Enter password: pass123
Login Successful! Welcome back, ali!

## Language
C++

## Author
Developed as part of CodeAlpha C++ Programming Internship
