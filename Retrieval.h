#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>

#include "HashTable.h"

#ifndef RETRIEVAL_RETRIEVAL_H
#define RETRIEVAL_RETRIEVAL_H

using namespace std;

class Retrieval {
private:
    /**
     * L'attributo di tipo HashTable corrisponde alla HashTable di radice dell'albero RETRIEVAL,
     * esso quindi è inizializzato con l'istanza della classe HashTable, che eseguirà le sue
     * operazioni di inizializzazione.
     */
    HashTable rootHashTable = HashTable();

public:
    Retrieval();
    void getWordsFromFile(string fileName);
    void searchWord(string word);
};

#endif //RETRIEVAL_RETRIEVAL_H
