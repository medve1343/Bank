//
//  CD.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include "CD.hpp"

CD::CD(std::string type, float balance) :Account(type, balance) {}

void CD::display() {
    cout << "Account ID: " << id_number << " Acccount type: " << accountType << " Balance: $" << accountBalance << " Term: " << term << " Interest rate: " << interestRate << endl;
    
    if(contact_info) {
        contact_info->display();
    }
}

void CD::initialize() {
    cout << "Initial Deposit to the account: ";
    cin >> accountBalance;
    
    cout << "Please set term: ";
    cin >> term;
    
    cout << "Please set a interest rate: ";
    cin >> interestRate;
}
