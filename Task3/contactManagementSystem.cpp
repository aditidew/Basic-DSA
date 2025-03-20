#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Struct to represent a contact
struct Contact {
    string name;
    string phone;
    string email;
};

// Function to load contacts from a file
vector<Contact> loadContacts(const string& filename) {
    vector<Contact> contacts;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Contact contact;
            getline(ss, contact.name, ',');
            getline(ss, contact.phone, ',');
            getline(ss, contact.email, ',');
            contacts.push_back(contact);
        }
        file.close();
    }
    return contacts;
}

// Function to save contacts to a file
void saveContacts(const vector<Contact>& contacts, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phone << "," << contact.email << "\n";
        }
        file.close();
    }
}

// Function to display all contacts
void displayContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }
    cout << "Contacts List:\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phone
             << ", Email: " << contacts[i].email << "\n";
    }
}

// Function to add a new contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email address: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    cout << "Contact added successfully.\n";
}

// Function to edit an existing contact
void editContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available to edit.\n";
        return;
    }
    displayContacts(contacts);
    size_t index;
    cout << "Enter the number of the contact to edit: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number.\n";
        return;
    }
    Contact& contact = contacts[index - 1];
    cout << "Editing contact: " << contact.name << "\n";
    cout << "Enter new name (leave blank to keep current): ";
    cin.ignore();
    string input;
    getline(cin, input);
    if (!input.empty()) contact.name = input;
    cout << "Enter new phone number (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) contact.phone = input;
    cout << "Enter new email address (leave blank to keep current): ";
    getline(cin, input);
    if (!input.empty()) contact.email = input;
    cout << "Contact updated successfully.\n";
}

// Function to delete a contact
void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available to delete.\n";
        return;
    }
    displayContacts(contacts);
    size_t index;
    cout << "Enter the number of the contact to delete: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number.\n";
        return;
    }
    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully.\n";
}

// Main program
int main() {
    const string filename = "contacts.txt";
    vector<Contact> contacts = loadContacts(filename);
    int choice;

    do {
        cout << "\nContact Management System\n";
        cout << "1. View Contacts\n";
        cout << "2. Add Contact\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayContacts(contacts);
                break;
            case 2:
                addContact(contacts);
                saveContacts(contacts, filename);
                break;
            case 3:
                editContact(contacts);
                saveContacts(contacts, filename);
                break;
            case 4:
                deleteContact(contacts);
                saveContacts(contacts, filename);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
