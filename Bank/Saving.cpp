//
//  Saving.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include "Saving.hpp"

Saving::Saving(std::string type, float balance) : Account(type, balance) {}

void Saving::display() {
    
    cout << "Account ID: " << id_number << " Acccount type: " << accountType << " Balance: $" << accountBalance << " Withdraw Limit: " << withdrawLimit << " Interest rate: " << interestRate << endl;
    
    if(contact_info) {
        contact_info->display();
    }
}

void Saving::initialize() {
    cout << "Initial Deposit to the account: ";
    cin >> accountBalance;
    
    cout << "Please set withdraw limit: ";
    cin >> withdrawLimit;
    
    cout << "Please set a interest rate: ";
    cin >> interestRate;
}
