#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    

    // cout << "ashutosh mining first block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh paid maciej 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 1);

    // cout << "ashutosh paid asa 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","asa", 1);
    // cout << "asa mining second block ... " << endl;
    // buffCUoin.minePendingTransactions("asa");
    // buffCUoin.prettyPrint(); 
    
    // cout << "asa paid ashutosh 1 BFC ... " << endl;
    // buffCUoin.addTransaction("asa","ashutosh", 1);    
    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    // cout << "maciej mining third block ... " << endl;
    // buffCUoin.minePendingTransactions("maciej");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh mining fourth block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint();

    bool quit = true;
    while (quit) {
        int option;
        string inputLine;
        cout << "======Main Menu======" << endl;
        cout << "1. Build Default" << endl;
        cout << "2. Add a transation" << endl;
        cout << "3. Verify Blockchain" << endl;
        cout << "4. Mine Pending Transactions" << endl;
        cout << "5. Get Balance of Address" << endl;
        cout << "6. Pretty Print" << endl;
        cout << "7. Quit" << endl;
        getline(cin, inputLine);
        option = stoi(inputLine);
        switch (option)
        {
            case 1: //build default
            {
                Blockchain buffCUoin;

                cout << "ashutosh mining first block ... " << endl;
                buffCUoin.minePendingTransactions("ashutosh");
                buffCUoin.prettyPrint(); 
                
                cout << "ashutosh paid maciej 1 BFC ... " << endl;
                buffCUoin.addTransaction("ashutosh","maciej", 1);

                cout << "ashutosh paid asa 1 BFC ... " << endl;
                buffCUoin.addTransaction("ashutosh","asa", 1);
                cout << "asa mining second block ... " << endl;
                buffCUoin.minePendingTransactions("asa");
                buffCUoin.prettyPrint(); 
                
                cout << "asa paid ashutosh 1 BFC ... " << endl;
                buffCUoin.addTransaction("asa","ashutosh", 1);    
                cout << "ashutosh paid maciej 2 BFC ... " << endl;
                buffCUoin.addTransaction("ashutosh","maciej", 2);
                
                cout << "maciej mining third block ... " << endl;
                buffCUoin.minePendingTransactions("maciej");
                buffCUoin.prettyPrint(); 
                
                cout << "ashutosh mining fourth block ... " << endl;
                buffCUoin.minePendingTransactions("ashutosh");
                buffCUoin.prettyPrint();
                
                break;
            }
            case 2:// add tranactions
            {
                string src;
                string dst;
                int amount;
                cout << "Enter an source: " << endl;
                cin >> src;
                cout << "Enter an receiver: " << endl;
                cin >> dst;
                cout << "Enter an amout: " << endl;
                cin >> amount;

                buffCUoin.addTransaction(src,dst,amount);
                break;
            }
            case 3://verify blockchain
            {
                if (buffCUoin.isChainValid() != true)
                {
                    cout << "Invalid BlockChain: difficulty not matched" << endl;
                }
                else
                {
                    cout << "Valid BlockChain :) " << endl;
                }
                break;
            }
              case 4:// mine pending
            {
                
            }
            case 5:// get balance address
            {
                string name;
                int balance;
                cout << "Of the names made in Default check their balance:" << endl;
                cout << "Enter name: " << endl;
                cin >> name;

                balance = buffCUoin.getBalanceOfAddress(name);

                cout << name << "'s " << "balance is: " << balance << endl;

            }
               case 6://print
            {
                buffCUoin.prettyPrint(); 
                break;
            }
            case 7:{
                quit = false;
                cout << "Goodbye.." << endl;
            }
            default:{
                break;
            }
        }
    }
    
    return 0;
}