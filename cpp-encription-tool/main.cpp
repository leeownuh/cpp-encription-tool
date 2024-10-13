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

// Function to check if the shift value is valid
bool isValidShift(int shift) {
    return shift >= 1 && shift <= 25;
}

int main() {
    string message;
    int shift;
    int choice;
    char repeat;

    do {
        cout << "\n--- Caesar Cipher Tool ---\n";
        cout << "1. Encrypt a message\n";
        cout << "2. Decrypt a message\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To consume the newline left by cin

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice! Please enter 1 to Encrypt or 2 to Decrypt." << endl;
            continue;
        }

        // Get the message from the user
        cout << "Enter the message: ";
        getline(cin, message);

        // Get a valid shift value from the user
        do {
            cout << "Enter the shift value (1-25): ";
            cin >> shift;
            if (!isValidShift(shift)) {
                cout << "Invalid shift value! Please enter a number between 1 and 25." << endl;
            }
        } while (!isValidShift(shift));

        // Perform encryption or decryption
        if (choice == 1) {
            string encryptedMessage = caesarEncrypt(message, shift);
            cout << "\nEncrypted Message: " << encryptedMessage << endl;
        } else {
            string decryptedMessage = caesarDecrypt(message, shift);
            cout << "\nDecrypted Message: " << decryptedMessage << endl;
        }

        // Ask the user if they want to perform another operation
        cout << "\nDo you want to encrypt/decrypt another message? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}
