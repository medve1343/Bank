//
//  Account.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include "Account.hpp"

int Account::next_ID = 0;

Account::Account(std::string type, float balance) : accountType(type), id_number(next_ID++), contact_info(nullptr), accountBalance(balance) { }

void Account::addContact(){
    contact_info = make_shared<Contact>();
    contact_info->updateAddress();
}

int Account::getID() const { return id_number; }

std::string Account::getType() const {
    return accountType;
}

float Account::getBalance() const {
    return accountBalance;
}

Account &Account::operator+=(float deposit) {
    this->accountBalance+=deposit;
    return *this;
}

Account &Account::operator-= (float cashout) {
    this->accountBalance-=cashout;
    return *this;
}

Account &Account::operator*=(float inflation) {
    this->accountBalance+=((inflation/100) * accountBalance);
    return *this;
}
