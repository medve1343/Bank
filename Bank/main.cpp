//
//  main.cpp
//  Bank
//
//  Created by Gergo Medveczky on 11/17/23.
//

#include <iostream>
#include <string>
#include "Debit.hpp"
#include "Account.hpp"
#include "Credit.hpp"
#include "Saving.hpp"
#include "CD.hpp"
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

void add_account(list<Account*>& account_list, Account* account);
void display_accounts(list<Account*>& account_list);

list<Account*>::iterator find_by_id(list<Account*>& account_list, int id);

int main(int argc, const char * argv[]) {
    
    list<Account*> account_list;
    
    int choice = 1;
    
    while (choice != 0) {
        std::cout << std::endl << "Account Menu:"
        << std::endl << "0. Quit Program"
        << std::endl << "1. Display Account Information"
        << std::endl << "2. Add a deposit to an account"
        << std::endl << "3. Withdraw from an account"
        << std::endl << "4. Add new account"
        << std::endl << "5. Find account by ID"
        << std::endl << "6. Remove account"
        << std::endl << "7. Show total balance for all accounts"
        << std::endl << "8. Add a dividend to all accounts"
        << std::endl << "9. Add contact information to an account" << std::endl;
        
        
        std::cout << "Your choice: ";
        std::cin >> choice;
     
        
        switch (choice) {
            case 1:
                display_accounts(account_list);
                break;
            case 2: {
                // Search for a Account in the list matching a specific ID
                int id = 0;
                cout << "Enter the ID of the account to find: ";
                cin >> id;
                    
                list<Account*>::iterator it;
                    
                it = find_by_id(account_list, id);

                // Check whether there was a Account in the list matching
                // that ID
                if (it != account_list.end()) {
                    cout << "Found Account: ";
                    (*it)->display();
                    float cashIn = 0;
                    cout << "Amount to deposit: ";
                    cin >> cashIn;
                    (*(*it)) += cashIn;
                    
                }
                else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 3: {
                int id = 0;
                cout << "Enter the ID of the account to find: ";
                cin >> id;
                    
                list<Account*>::iterator it;
                    
                it = find_by_id(account_list, id);

                // Check whether there was a Account in the list matching
                // that ID
                if (it != account_list.end()) {
                    cout << "Found Account: ";
                    (*it)->display();
                    float cashOut = 0;
                    cout << "Amount to withdraw: ";
                    cin >> cashOut;
                    (*(*it)) -= cashOut;
                    
                }
                else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4: {
                
                int option = 0;
                cout << "What account would you like to create? " << endl << "1. Debit" << endl << "2. Credit" << endl << "3. Saving" << endl << "4. CD" << endl << "Choose one of the options: ";
                cin >> option;
                switch(option) {
                    case 1: {
                        Debit* d = new Debit("Debit", 0);
                        d->initialize();
                        add_account(account_list, d);
                        break;
                    }
                    case 2: {
                        Credit* c = new Credit("Credit", 0);
                        c->initialize();
                        add_account(account_list, c);
                        break;
                    }
                    case 3: {
                        Saving* s = new Saving("Saving", 0);
                        s->initialize();
                        add_account(account_list, s);
                        break;
                    }
                    case 4: {
                        CD* cd = new CD("CD", 0);
                        cd->initialize();
                        add_account(account_list, cd);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case 5: {
            // Search for a Account in the list matching a specific ID
            int id = 0;
            cout << "Enter the ID of the account to find: ";
            cin >> id;
                
            list<Account*>::iterator it;
                
            it = find_by_id(account_list, id);

            // Check whether there was a Account in the list matching
            // that ID
            if (it != account_list.end()) {
                (*it)->display();
            }
            else {
                cout << "Account not found." << endl;
            }
                break;
            }
            
            case 6: {
                
                int id = 0;
                cout << "Enter account ID to remove: ";
                cin >> id;
                
                auto new_end = remove_if(account_list.begin(), account_list.end(),
                [id](auto& list_item){
                  return id == list_item->getID();
                });
                
                account_list.erase(new_end, account_list.end());
                
                break;
            }
            
            case 7: {
                    // Use accumulate to get total balance
                    
                    float total = accumulate(account_list.begin(), account_list.end(), 0.0f,
                        [](auto accumulator, auto& account) {
                            return accumulator + account->getBalance();
                        }
                    );
                cout << "Total in all accounts: $" << total;
                break;
            }
                
            case 8: {
                float dividend = 0;
                cout << "Enter the dividend as a percentage: ";
                cin >> dividend;
                
                transform(account_list.begin(), account_list.end(), account_list.begin(),
                    [dividend](auto& account) {
                    (*account) *= dividend;
                    return account;
                    }
                );
                break;
            }
            case 9: {
                int id = 0;
                cout << "Enter the ID of the account to find: ";
                cin >> id;
                
                list<Account*>::iterator it;
                it = find_by_id(account_list, id);
                
                // Check whether there was a Account in the list matching
                // that ID
                if (it != account_list.end()) {
                    (*it)->display();
                    (*it)->addContact();
                    
                }
                else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            default:
                break;
        }
            }
                
                
    return 0;
}
        
    
//    Debit* d = new Debit("Debit", 25);
//    d->display();
////    d->addContact();
//    Credit* c = new Credit("Credit", 15);
//    c->display();
//    Saving* s = new Saving("Saving", 35);
//    s->display();
//    CD* cd = new CD("CD", 10);
//    cd->display();
    
    
    
    
    
//    add_account(account_list, d);
    
//    list<Account*>::iterator it;
//        
//    it = find_by_id(account_list, 0);
//
//    // Check whether there was a Account in the list matching
//    // that ID
//    if (it != account_list.end()) {
//        cout << "Found Account: ";
//        (*it)->display();
//        float cashIn = 0;
//        cout << "Amount to deposit: ";
//        cin >> cashIn;
//        (*(*it)) += cashIn;
//        
//    }
//    else {
//        cout << "Account not found." << endl;
//    }
//    
//    display_accounts(account_list);




/* Add account to the list */
void add_account(list<Account*>& account_list, Account* account)
{
    account_list.push_back(account); // Add the Account to the list
}

/* Display all Account objects in the list */
void display_accounts(list<Account*>& account_list)
{
    for_each(account_list.begin(), account_list.end(),
            [](auto& account) {
                account->display();
            }
        );
}

/* Search for a Account object in the list using an ID number */
list<Account*>::iterator find_by_id(list<Account*>& account, int id)
{
    list<Account*>::iterator it;
    for (it = account.begin(); it != account.end(); it++)
    {
        if ((*it)->getID() == id)
        {
            return it; // Return iterator to Account matching the ID
        }
    }

    return it; // Account with that ID was not found
}
