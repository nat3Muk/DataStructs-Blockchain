#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10; // fixed at 10
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
    
    int srcAmount = 0;
    srcAmount = getBalanceOfAddress(src);
    if (srcAmount >= coins || src == "BFC")
    {
        Transaction insert(src, dst, coins);
        pending.push_back(insert);
    }
    else
    {
        cout << "Error: Insufficient funds" << endl;
    }
}

bool Blockchain::isChainValid() { 
    // TODO (incomplete)
    for(unsigned int i = 1; i < chain.size(); i++)
    {
        //travese blockchain and compare hashses of blocks
        if (chain[i-1].calculateHash() != chain[i].getPreviousHash())
        {
            return false;
        }
        for(unsigned int j = 0; j < difficulty; j++)
        {
            if(chain[i].getPreviousHash()[j] != '0')
            {
                return false;
            }
        }
    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO (incomplete)
    /*
        Create a new Block with the list of transactions = list of pending transactions, 
        timestamp = current time (using time(nullptr) instruction), 
        and the field previousHash = hash of the latest block in the chain.
    */
    Block newBlock(pending, time(nullptr), getLatestBlock().getHash());
    //check if mine returned successfully...clear list of pending
        //making sure the mine block funtion return a valid value of nonce so check nonce and difficulty is done right in mineBlock func.
    newBlock.mineBlock(difficulty);
    pending.clear();
    //push newBlock to Blockchain
    chain.push_back(newBlock);
    /*
        To reward the minerAddress, 
        add a new transaction to the (now empty) list of pending transactions with src="BFC", dst=minerAddress, and amount=miningReward.
    */
   Transaction insertNew("BFC", minerAddress, miningReward);
   pending.push_back(insertNew);

    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int balance = 0;
    for (unsigned int i = 0; i < chain.size(); i++)
    {
        for(unsigned int j = 0; j < chain[i].getTransactions().size(); j++)
        {
            if (chain[i].getTransactions()[j].getSender() == address)
            {
                balance = balance - chain[i].getTransactions()[j].getAmount();

            }
            if (chain[i].getTransactions()[j].getReceiver() == address)
            {
                balance = balance + chain[i].getTransactions()[j].getAmount();
            }
        }
    }
    //check balance is not negative (not sure on this one if statement) 
    if (balance < 0)
    {
        return -1;
    }
    else
        return balance;
}

void Blockchain::prettyPrint() {
    // TODO (non-pretty)
    if (chain.size() == 0)
    {
        cout<< "Empty BlockChain" << endl;
        return;
    }
    else{
        for(unsigned int i = 0; i < chain.size(); i++)
        {
            cout << chain[i].toString() << " || " << endl;
        }
    }
    
}