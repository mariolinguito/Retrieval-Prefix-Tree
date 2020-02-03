#include "HashElement.h"

HashElement::HashElement(char hashElement) {
    this->hashElement = hashElement;
    this->endWord     = false;
    this->hashTable   = NULL;
}

HashElement::HashElement(char hashElement, HashTable *hashTable, bool endWord) {
    this->hashElement = hashElement;
    this->endWord     = endWord;
    this->hashTable   = hashTable;
}

char HashElement::getHashElement() {
    return this->hashElement;
}

bool HashElement::getEndWord() {
    return this->endWord;
}

void HashElement::setEndWord(bool endWord) {
    this->endWord = endWord;
}

HashTable* HashElement::getHashTable() {
    return this->hashTable;
}