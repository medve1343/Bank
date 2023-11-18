//
//  Account.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include "Contact.hpp"
#include <memory>
class Account {
protected:
    std::string accountType;
    static int next_ID;
    int id_number;
    std::shared_ptr<Contact> contact_info;
    float accountBalance;
public:
    Account(std::string type, float balance);
    virtual void display() = 0;
    virtual void initialize() = 0;
    
    void addContact();
    int getID() const;
    std::string getType() const;
    float getBalance() const;
    
    Account& operator+= (float deposit);
    Account& operator-= (float cashout);
    Account& operator*= (float inflation);
};

#endif /* Account_hpp */
