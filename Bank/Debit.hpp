//
//  Debit.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#ifndef Debit_hpp
#define Debit_hpp
#include "Account.hpp"
#include <stdio.h>
#include <iostream>
using namespace std;

class Debit : public Account {
private:
    unsigned int dailyTransactionLimit;
    std::string password;
public:
    Debit(std::string type, float balance);
    virtual void display();
    virtual void initialize();
    
};
#endif /* Debit_hpp */
