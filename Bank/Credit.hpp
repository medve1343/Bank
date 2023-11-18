//
//  Credit.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#ifndef Credit_hpp
#define Credit_hpp
#include "Account.hpp"
#include <stdio.h>
#include <iostream>
class Credit : public Account {
private:
    int creditlimit;
    float interestRate;
public:
    Credit(std::string type, float balance);
    virtual void display();
    virtual void initialize();
  
};
#endif /* Credit_hpp */
