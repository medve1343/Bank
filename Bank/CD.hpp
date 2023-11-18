//
//  CD.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#ifndef CD_hpp
#define CD_hpp
#include "Account.hpp"
#include <stdio.h>
#include <iostream>

class CD : public Account {
private:
    unsigned int term;
    float interestRate;
public:
    CD(std::string type, float balance);
    
    virtual void display();
    virtual void initialize();
};

#endif /* CD_hpp */
