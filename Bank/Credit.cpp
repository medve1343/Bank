//
//  Credit.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include "Credit.hpp"

Credit::Credit(std::string type, float balance):Account(type, balance) {}

void Credit::display() {
    
    cout << "Account ID: " << id_number << " Acccount type: " << accountType << " Balance: $" << accountBalance << " Credit Limit: "<< creditlimit << " Interest rate: " << interestRate << endl;
    
    if(contact_info) {
        contact_info->display();
    }
}

void Credit::initialize() {
        
    cout << "Initial Deposit to the account: ";
    cin >> accountBalance;
    
    cout << "Please set credit limit: ";
    cin >> creditlimit;
    
    cout << "Please set a interest rate: ";
    cin >> interestRate;
}
