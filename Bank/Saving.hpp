//
//  Saving.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#ifndef Saving_hpp
#define Saving_hpp
#include "Account.hpp"
#include <stdio.h>
#include <iostream>
class Saving : public Account {
private:
    unsigned int withdrawLimit;
    float interestRate;
public:
    Saving(std::string type, float balance);
    virtual void display();
    virtual void initialize();

};
#endif /* Saving_hpp */
