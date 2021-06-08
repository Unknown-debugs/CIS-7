/* 
 * File:   main.cpp
 * Author: Junhwan Lee
 * Purpose: Create a Vignere Cipher in C++ and simulate
 * Created on June 7, 2021, 12:13 PM
 */

// CIS-7 Final Project Case 3 - Vigenere Cipher

// Standard Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include "Cipher.h"

using namespace std;

void menu();

// Display menu
void menu() {
    cout << "Welcome to Vigenere Cipher\n";
    cout << "1. Encryption\n" << "2. Decryption\n" << "3. Exit\n";
    cout<<"Your choice: ";
}

// Begin main
int main() {
    
    // Initialize Cypher class
    Cipher c;
    // Initialize choice
    int choice;
    // Repeat loop until user inputs 3
    do {
        // Display menu and user inputs choice
        menu();
        cin>> choice;
              
        // Input validation
        while (choice > 3 || choice < 0) {
            cout << "Invalid selection, enter 1, 2, or 3: ";
            cin>>choice;
        }
        
        // initialize strings
        string input, key;
        
        // If action taken
        if (choice == 1 || choice == 2) {

            // Ask user for plain text and key strings
            cout << "Enter plain text: ";
            cin>>input;
            cout << "Enter key: ";
            cin>>key;
            c.initInput(input);
            c.genKey(key);
            
            
            // Encryption
            if (choice == 1){
                cout<<"Encrypted text: ";
                c.encryption();
            }
            // Decryption
            else{
                cout<<"Decrypted text: ";
                c.decryption();
            }
            cout<<endl;
        }
        // Clear vectors
        c.clear();        
    } while (choice != 3);

    // Exit right
    return 0;
}
