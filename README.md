# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Author: Nathan Mukooba

This program was made with intention of better understanding crypto-currency through Blockchaining
The blackchaining of the currency is titled "Buff-CUoin"

Within the program multiple data structures were used. For example, Hashing and Vectors combined to make the structure for "Blockchain".

Specifically files such as;
  
  Block.cpp
  Block.hpp
  
    -Useful for manipulating the blocks to do tasks
    
        *mining the block itself
        
        *converting transactions and strings to hashes (using sha256.cpp & sha256.hpp files)
        
        *acessing the transaction class
        
        *the storage of "timestamps" and the "nonce"
        
  Transaction.cpp
  Transaction.hpp
  
    -Useful for accessing user information (sender, reciever, amount)
    
  BlockChain.cpp
  BlockChain.hpp
  
    -Used to manipulate all above  files to create the Blockchain structure
    
    -For here the program hold the functions to be used by th euser in the program
    
      *1) adding transactions, 2) mining pending transactions, 3) checking the validity of the blockchain, 4) checking the balance of a given user, and 5) printing the blockchain.
      
      * all of which are options in the main.cpp/driver file of the program
  
  
