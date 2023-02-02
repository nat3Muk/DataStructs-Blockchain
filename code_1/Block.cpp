#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // TODO
    string toHash = "";
    toHash = toString();
    return sha256(toHash);   
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    //Proof_of_work
    //string toBeHashed = calculateHash();
    bool verify = false;
    while(!verify)
    {
        unsigned int counter = 0;
        string toBeHashed = calculateHash();
        for(unsigned int i = 0; i < difficulty; i++)
        {
            if(toBeHashed[i] == '0')
            {
                counter++;
            }
        }
        if (counter == difficulty) verify = true;
        else{
            nonce++;
        }
    }
    
}
string Block::toString() {
    // TODO
    stringstream ss;
    for (unsigned int i = 0; i < transactions.size(); i++ )
    {
        //gets string = (sender, receiver, amount)
        ss << transactions[i].toString();
    }
    ss << "Timestamp:" << timestamp << " PrevHash:" << previousHash << " Nonce:" << nonce;
   
    return ss.str();
}
vector<Transaction> Block::getTransactions()
{ 
    return transactions;
}
string Block::getPreviousHash()
{
    return previousHash;
}
string Block::getHash()
{
    return hash;
}