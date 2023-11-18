//
//  Contact.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/18/23.
//

#include "Contact.hpp"

Contact::Contact() : address_street(""), city(""), state(""), zip_code(""), phone_number("") {}

void Contact::updateAddress() {
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address_street);
    cout << "Enter City: ";
    getline(cin, city);
    cout << "Enter State: ";
    getline(cin, state);
    cout << "Enter Zip Code: ";
    getline(cin, zip_code);
    cout << "Enter Phone Number: ";
    getline(cin, phone_number);
}

void Contact::display() const{
    cout << "+ Contact Information: Address: " << address_street <<
    " City: " << city << " State: " << state << " Zip: " << zip_code << " Phone: " << phone_number << endl;
}
