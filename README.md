# Retrieval
Implementation of a retrieval tree, that is a prefix tree, with hash table and multiplication method as hash function. 

This is an example: 

![Example of retrieval tree](https://camo.githubusercontent.com/9bf75187b0b760703655ad1700feaa98b3c59ae0/68747470733a2f2f69312e77702e636f6d2f7468656f72796f6670726f6772616d6d696e672e636f6d2f77702d636f6e74656e742f75706c6f6164732f323031352f30362f7472696531322e6a7067)

1. The algorithm get the words from an input file, and word for word, it places the word in the correct place in the tree, so the words that share the same prefix will have the same branch. 
2. Throgh the command line we now can lunch the algorithm with the command: ./main [file of words].[txt] [word to search]
