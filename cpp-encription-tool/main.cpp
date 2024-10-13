#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the message using Caesar Cipher
string caesarEncrypt(string text, int shift) {
    string result = "";

    // Traverse through each character of the text
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        // Leave non-alphabet characters unchanged
        else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string message;
    int shift;

    // Get the message from the user
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    // Get the shift value from the user
    cout << "Enter shift value (1-25): ";
    cin >> shift;

    // Encrypt the message
    string encryptedMessage = caesarEncrypt(message, shift);

    // Output the encrypted message
    cout << "Encrypted Message: " << encryptedMessage << endl;

    return 0;
}
