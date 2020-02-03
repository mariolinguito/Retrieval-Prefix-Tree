#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>

#include "HashElement.h"

/**
 * Definisce la lunghezza della HashTable, ossia del vettore di vettori.
 * Chiaramente se questa diminuisce avremo più collisioni, se questa aumenta
 * avremo meno collisioni dato che ci saranno più posizioni disponibili.
 */
#define HASH_SIZE 24

#ifndef RETRIEVAL_HASHTABLE_H
#define RETRIEVAL_HASHTABLE_H

using namespace std;

/**
 * Il tipo definito è stato definito come un vettore di vettori di elementi
 * e questo ci occorre per poter definire la struttura dati che conterrà per
 * l'appunto gli elementi della HashTable che ha necessità di risolvere le
 * eventuali collisioni attraverso una lista concatenata. Quindi avremo che
 * ogni elemento del vettore principale è esso stesso un vettore di elementi
 * la cui posizione calcolata dalla funzione di hash è la stessa. In pratica
 * avremo una struttura del genere:
 *
 * [*] -> [A, E, R, T]
 * [*] -> [W, Y, Z]
 * [*] -> [C, H, L, P]
 * [...]
 */
typedef vector<vector<HashElement>> DoubleVectorElements;

/**
 * La classe principale è quella della HashTable. Essa possiede metodi (pubblici e privati)
 * che permettono una corretta gestione dell'HashTable e della struttura dati che in generale
 * si vuole costruire (l'albero RETRIEVAL). Gli attributi sono semplicemente la costante di
 * KNUTH che verrà utilizzata per poter calcolare la posizione di ogni singolo elemento nel
 * vettore relativo alla HashTable. Ed infatti abbiamo come secondo attributo il vettore di
 * vettori esplicitato precedentemente.
 */
class HashTable {
private:
    double const         A_KNUTH = (sqrt(5)-1)/2;
    DoubleVectorElements hashLists;

    void initializeHashTableLists();
    int hashingMoltiplicationMethod(char character);
    int getCharacterIndex(vector<HashElement> hashElements, char character);
    HashTable* insertIntoHashTable(char character, bool end);
    HashTable* insertIntoHashTableList(int position, char character, bool end);
    void printHashList(vector<HashElement> hashList);

public:
    HashTable();
    void insertWordIntoHashTable(string word);
    void printHashTable(HashTable* hashTable);
    bool searchWordIntoRetrieval(HashTable* hashTable, string word);
};

#endif //RETRIEVAL_HASHTABLE_H
