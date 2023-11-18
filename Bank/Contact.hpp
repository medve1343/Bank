//
//  Contact.hpp
//  Bank
//
//  Created by Gergo Medveczky on 11/18/23.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Contact
{
private:
    string address_street;
    string city;
    string state;
    string zip_code;
    string phone_number;
    
public:
    Contact();
    void updateAddress();
    void display() const;
};


#endif /* Contact_hpp */
