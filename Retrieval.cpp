#include "Retrieval.h"

Retrieval::Retrieval() {}

/**
 * Il metodo si occupa di prendere in input il nome del file di testo dalla quale prendere le
 * parole da inserire all'interno dell'albero. Infatti legge da un file parola per parola con
 * un ciclo while e richiama il metodo per l'inserimento di quelle parole all'interno dell'albero.
 * Al termine del ciclo quindi avremo un albero costruito con le parole che sono state prelevate
 * dal file.
 */
void Retrieval::getWordsFromFile(string fileName) {
    ifstream inputWords(fileName);
    string   word;

    while(inputWords >> word) {
        this->rootHashTable.insertWordIntoHashTable(word);
    }   this->rootHashTable.printHashTable(&this->rootHashTable);
}

/**
 * Il metodo non fa altro che richiamare il metodo per la ricerca di una parola all'interno
 * dell'albero dandogli in input la HashTable di root dalla quale partire e la parola da
 * ricercare nell'albero. Se questa viene trovata allora il metodo di ricerca definito nella
 * classe HashTable restituisce un true, altrimenti restituisce un false.
 */
void Retrieval::searchWord(string word) {
    if(this->rootHashTable.searchWordIntoRetrieval(&this->rootHashTable, word)) {
        cout << word << " is found!" << endl;
    } else {
        cout << word << " isn't found!" << endl;
    }
}
