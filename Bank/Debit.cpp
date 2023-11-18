//
//  Debit.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include "Debit.hpp"

Debit::Debit(std::string type, float balance) : Account(type, balance) {}

void Debit::display() {
    
    cout << "Account ID: " << id_number << " Acccount type: " << accountType << " Balance: $" << accountBalance << " Transaction limit: " << dailyTransactionLimit << endl;
    
    if(contact_info) {
        contact_info->display();
    }
}

void Debit::initialize() {
    
    cout << "Initial Deposit to the account: ";
    cin >> accountBalance;
    
    cout << "Please set daily transaction limit: ";
    cin >> dailyTransactionLimit;
    
    cout << "Please set a password: ";
    cin >> password;
    
}
