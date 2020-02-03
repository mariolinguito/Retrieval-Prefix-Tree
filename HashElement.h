#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>

#ifndef RETRIEVAL_HASHELEMENT_H
#define RETRIEVAL_HASHELEMENT_H

using namespace std;

class HashTable;

/**
 * La classe HashElement definisce un particolare elemento della HashTable,
 * essa infatti contiene un elemento di tipo char, ed un puntatore ad un'altra
 * HashTable, per i motivi che saranno ben più chiari in seguito. Oltre questo
 * vi è anche un booleano che indica che l'elemento in questione è la lettera
 * finale di una parola, questo perchè nella ricerca della parola nell'albero
 * ci troveremo di fronte al caso in cui una parola ne contiene un'altra, cioè
 * il caso in cui una parola è prefisso di un'altra parola, quindi ci occorre
 * conoscere quali sono le terminazioni di ogni parola. Chiaramente essa possiede
 * un costruttore che oltre ad inizializzare il carattere nella classe, inizializza
 * anche il puntatore a NULL; Del costruttore viene fatto un overload nel caso
 * in cui esso prenda in input sia il carattere da inizializzare, sia la HashTable
 * alla quale puntare, oltre al valore booleano da settare. I tre metodi get per
 * il carattere e per la HashTable ci permettono semplicemente di accedere agli
 * attributi privati della classe. Mentre l'unico metodo set ha il compito di
 * settare il booleano ad un certo valore, ad esempio nel caso in cui nel file
 * viene aggiunta una nuova parola che fa da prefisso ad un'altra parola o che
 * abbia come prefisso qualche altra parola nel file.
 */
class HashElement {
private:
    char       hashElement;
    bool       endWord;
    HashTable* hashTable;

public:
    HashElement(char hashElement);
    HashElement(char hashElement, HashTable* hashTable, bool endWord);
    char getHashElement();
    bool getEndWord();
    void setEndWord(bool endWord);
    HashTable* getHashTable();
};

#endif //RETRIEVAL_HASHELEMENT_H
