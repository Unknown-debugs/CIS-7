/* 
 * File:   Cypher.h
 * Author: Junhwan Lee
 * Purpose: Create a cipher class and utilize multiple methods to encryt/decrypt
 * Created on June 7, 2021, 12:14 PM
 */

#ifndef CYPHER_H
#define CYPHER_H

// Standard Libraries
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

// Cipher class
class Cipher {
private:
    // Vectors holding char 
    vector<char> keyword;
    vector<char> input;
    vector<char> output;
    
    // Plain text and key string sizes
    int keysize;
    int inputsize;

public:
    // Constructor
    Cipher();
    // Initialize input
    void initInput(string&);
    // Generate key
    void genKey(string&);
    // Display vector
    void display(vector<char>);
    // Decryption function
    void decryption();
    // Encryption function
    void encryption();
    // Clear contents
    void clear();
};

// Constructor
Cipher::Cipher() {
    keysize = 0;
    inputsize = 0;
}

// Clear contents
void Cipher::clear(){
    keysize = 0;
    inputsize = 0;
    keyword.clear();
    input.clear();
    output.clear();
}

// Initialize input vector
void Cipher::initInput(string& str){
    
    // Record the length of the string
    inputsize = str.length();
    // Push back the characters from string to vector
    for (int i = 0; i < inputsize; i++) {
        input.push_back(str[i]);
    }
    // Reserve space for key vector for time complexity
    keyword.reserve(inputsize * 2);
}

// Generate key vector
void Cipher::genKey(string & key) {
    
    // Record the length of string
    keysize = key.length();
    // String iterator
    string::iterator itr;
    // Push back the characters from string to vector
    for (itr = key.begin(); itr != key.end(); ++itr) {
        keyword.push_back(*itr);
    }
    // Copy the recorded string size to the new variable
    int size = keysize;
    // Loop to match the size of two vectors
    while (keysize != inputsize) {
        // Difference in size
        int diff = abs(keysize - inputsize);
        // If the key size is bigger
        if (keysize > inputsize) {
            // Reduce to match the input size
            for (int i = 0; i < diff; i++) {
                keyword.pop_back();
            }
            // Exit loop
            break;
        } else {
            // If the key size is smaller
            for (int i = 0; i < diff; i++) {
                // Repeat loop and fill to make it bigger
                for (int i = 0; i < size; i++) {
                    // Push back char from string
                    keyword.push_back(key[i]);
                    // Increment the size
                    keysize++;
                }
            }
        }
    }
}

// Begin decryption
void Cipher::decryption() {
    
    // Repeat process for each character
    for (int i = 0; i < inputsize; i++) {
        // Conversion to 0 - 25
        int k = int(keyword[i]) - int('A');
        int p = int(input[i]) - int('A');
        // n = difference in key char and input char
        int n = p - k;
        // If negative, add 26
        if(n < 0)
            n += 26;
        // Ascii conversion back to character
        char c = n + 'A';
        // Push back to the output vector
        output.push_back(c);
    }
    // Display the decrypted text
    display(output);
}

// Begin encryption
void Cipher::encryption() {
    
    // Repeat process for each character
    for (int i = 0; i < inputsize; i++) {
        // Conversion to 0 - 25
        int k = int(keyword[i]) - int('A');
        int p = int(input[i]) - int('A');
        // plain char + key char modulo 26 to encrypt
        int e = (k + p) % 26;
        // Ascii conversion back to character
        char c = e + 'A';
        // Push back to the output vector
        output.push_back(c);
    }
    // Display the encrypted text
    display(output);
}

// Display the output 
void Cipher::display(vector<char> v) {
    
    // Vector iterator
    vector<char>::iterator itr;
    // Iterate each char to display
    for (itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr;
    }
    cout << endl;
}

#endif /* CYPHER_H */

