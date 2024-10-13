#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the message using Caesar Cipher
string caesarEncrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        else {
            result += ch;
        }
    }
    return result;
}

// Function to decrypt the message using Caesar Cipher
string caesarDecrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch)) {
            result += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        else if (islower(ch)) {
            result += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string message;
    int shift;
    int choice;

    cout << "Caesar Cipher Tool\n";
    cout << "1. Encrypt a message\n";
    cout << "2. Decrypt a message\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // To consume the newline left by cin

    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Enter the shift value (1-25): ";
    cin >> shift;

    if (choice == 1) {
        // Encrypt the message
        string encryptedMessage = caesarEncrypt(message, shift);
        cout << "Encrypted Message: " << encryptedMessage << endl;
    } else if (choice == 2) {
        // Decrypt the message
        string decryptedMessage = caesarDecrypt(message, shift);
        cout << "Decrypted Message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Exiting program." << endl;
    }

    return 0;
}
