#include "HashTable.h"

/**
 * Il metodo viene utilizzato per poter inizializzare i vettori contenuti nel vettore che
 * fa da HashTable, aggiungendo dei caratteri dummy, ossia caratteri che non sono da
 * considerare all'interno delle elaborazioni. Quindi scorre semplicemente il primo vettore
 * ed esegue un inserimento di un semplice elemento all'interno dei vettori di ogni singolo
 * elemento (del primo vettore). Questo per evitare che si incorra in un segfault nel momento
 * in cui si vuole inserire una parola all'interno dell'albero.
 */
void HashTable::initializeHashTableLists() {
    for(int index = 0; index < HASH_SIZE; index++) {
        this->hashLists.push_back(vector<HashElement>(1, HashElement('_')));
    }
}

/**
 * Il metodo non fa altro che restituire un intero che è la posizione calcolata dell'elemento
 * da inserire all'interno della HashTable. Viene applicato il metodo della moltiplicazione,
 * ossia si moltiplica la costante di KNUTH per il carattere prendendo la parte frazionaria di
 * questo risultato. Poi si moltiplica questo risultato per la lunghezza della HashTable e si
 * preleva da questo la parte intera inferiore. Quest'ultima deve essere restituita, ed equivale
 * alla posizione che deve assumere quell'elemento.
 */
int HashTable::hashingMoltiplicationMethod(char character) {
    return floor(fmod(this->A_KNUTH*character, 1)*HASH_SIZE);
}

/**
 * Il metodo prende in input un vettore di elementi di tipo HashElement ed un carattere, quindi
 * non fa altro che scorrere questo vettore di elementi e verificare che il carattere dato in
 * input è presente nel vettore. Se si, viene restituita la posizione dell'elemento, altrimenti
 * viene restituito -1, che sta ad indicare il fatto che l'elemento non è presente in esso.
 */
int HashTable::getCharacterIndex(vector<HashElement> hashElements, char character) {
    for(int index = 0; index < hashElements.size(); index++) {
        if(hashElements.at(index).getHashElement() == character) {
            return index;
        }
    }

    return -1;
}

/**
 * Il metodo prende in input un carattere da aggiungere all'interno dell'albero ed un booleano
 * che sta ad indicare il fatto che il carattere può essere o meno un carattere di fine parola.
 * Di questo carattere ne viene calcolata la posizione mediante il metodo della moltiplicazione
 * che è stato visto prima e sia la posizione, che il carattere, che il booleano vengono dati al
 * metodo che si occupa effettivamente dell'inserimento dell'elemento all'interno del vettore.
 * Il metodo restituisce una HashTable che corrisponde alla HashTable successiva, cioè quella che
 * dovrà contenere il successivo carattere della parola (se esiste).
 */
HashTable* HashTable::insertIntoHashTable(char character, bool end) {
    int position = this->hashingMoltiplicationMethod(character);
    return this->insertIntoHashTableList(position, character, end);
}

/**
 * Il metodo prende in input la posizione dell'elemento da aggiungere all'interno della HashTable,
 * il carattere da aggiungere e un booleano che indica se quel carattere è di fine parola o meno.
 * Prima di tutto si va a verificare se la HashTable relativa a quel carattere esiste o meno, cioè
 * la HashTable puntata da quel carattere esiste o meno. Questo lo si fa attraverso il metodo della
 * classe getCharacterIndex(...), se questo metodo restituisce un numero minore di 0 allora vuol dire
 * che quel carattere non puntava a nessuna HashTable e quindi dobbiamo inserire in quella posizione
 * un nuovo elemento che ha come carattere proprio il carattere da voler aggiungere, che ha una nuova
 * HashTable istanziata, ed un booleano che è uguale a quello dato in input al metodo stesso. Eseguite
 * queste operazioni viene restituita la HashTable di questo nuovo elemento. Viceversa se il metodo di
 * controllo restituisce un numero maggiore di 0, che corrisponde poi all'indice dell'elemento trovato
 * nel vettore, allora vuol dire che quell'elemento già esiste e quindi non c'è bisogno di creare un
 * nuovo elemento. Le operazioni che infatti vengono fatte in questo momento sono quelle di controllare
 * prima di tutto che il booleano all'interno dell'elemento sia falso, se è cosi allora lo risettiamo
 * con l'apposito metodo al nuovo valore booleano dato in input se e solo se quest'ultimo è vero. Alla
 * fine restituiamo la HashTable già costruita in precedenza per quell'elemento.
 */
HashTable* HashTable::insertIntoHashTableList(int position, char character, bool end) {
    int hashPosition = this->getCharacterIndex(this->hashLists.at(position), character);

    if(hashPosition < 0) {
        this->hashLists.at(position).push_back(HashElement(character, new HashTable(), end));
        return this->hashLists.at(position).back().getHashTable();
    } else {
        if(!this->hashLists.at(position).at(hashPosition).getEndWord() && end) {
            this->hashLists.at(position).at(hashPosition).setEndWord(end);
        }

        return this->hashLists.at(position).at(hashPosition).getHashTable();
    }
}

void HashTable::printHashList(vector<HashElement> hashList) {
    for(int index = 1; index < hashList.size(); index++) {
        cout << hashList.at(index).getHashElement() << "(" << hashList.at(index).getEndWord() << ")";

        if(hashList.at(index).getHashTable() != NULL) {
            cout << endl;
            this->printHashTable(hashList.at(index).getHashTable());
        }
    }
}

/**
 * Il costruttore richiama il metodo che permette di inizializzare i vector
 * che contengono i vector relativi agli elementi la cui posizione è la stessa.
 */
HashTable::HashTable() {
    this->initializeHashTableLists();
}

/**
 * Il metodo si occupa di inserire una parola all'interno dell'albero, quindi
 * in input prende proprio la stringa relativa alla parola. Il booleano nel
 * metodo viene inizializzato a true nel caso in cui la parola abbia dimensione
 * pari a 1, cioè è una singola lettera, per tale ragione essa stessa è la fine
 * della parola, oppure a false nel caso in cui la sua lunghezza è almeno pari a
 * 2. Inizializziamo la prima HashTable con l'inserimento della prima lettera
 * della parola e il booleano che indica se quella lettera è di fine parola o meno
 * (chiaramente non lo è). Si entra all'interno di un ciclo for che parte dalla
 * seconda lettera e arriva fino alla fine della lunghezza della parola. All'interno
 * del ciclo for il booleano endWord assume il valore true o false in relazione al
 * fatto che la lettera successiva a quella che si sta prendendo in considerazione
 * (determinata dall'indice index) è di fine parola o meno. In seguito la variabile
 * hashTable diventa la HashTable successiva nella quale deve essere inserita la
 * successiva lettera della parola.
 */
void HashTable::insertWordIntoHashTable(string word) {
    bool endWord         = word.size() < 2 ? true : false;
    HashTable* hashTable = this->insertIntoHashTable(word.at(0), endWord);

    for(int index = 1; index < word.size(); index++) {
        endWord   = index+1 < word.size() ? false : true;
        hashTable = hashTable->insertIntoHashTable(word.at(index), endWord);
    }
}

void HashTable::printHashTable(HashTable *hashTable) {
    for(int index = 0; index < hashTable->hashLists.size(); index++) {
        this->printHashList(hashTable->hashLists.at(index));
    }
}

/**
 * Fondamentale è il metodo di ricerca di una parola all'interno dell'albero. Esso
 * prende in input una HashTable e la parola da ricercare. Si dichiarano alcune
 * variabili di supporto:
 *
 * wordSize:  Indica la lunghezza della parola da ricercare,
 * index:     Indica l'indice relativo alla lettera della parola da ricercare nell'albero,
 * checkWord: È un contatore che viene incrementato ogni volta che si trova una lettera
 *            della parola lungo l'albero di HashTable,
 * endWord:   È un booleano che indica se la lettera è di fine parola o meno;
 *
 * Con un ciclo while (incrementando l'indice) si procede fino ad arrivare eventualmente
 * alla fine della parola, e ad ogni iteraizone si calcola la posizione della lettera con
 * il metodo che è stato già esplicitato in precedenza, che dovrebbe essere la posizione
 * in cui si trova l'elemento se esiste all'interno dell'albero. Poi, attraverso il metodo
 * getCharacterIndex(...) si cerca all'interno del vector (che contiene quegli elementi che
 * hanno la stessa posizione) si cerca la lettera corrente, quindi se esiste viene restituita
 * la sua posizione all'interno del vector, altrimenti viene restituito un -1. La variabile
 * booleana endWord assume il valore contenuto all'interno dell'oggetto HashElement se esso
 * esiste, per poter capire se è una fine parola o meno, oppure assume il valore false. Se
 * l'elemento è stato trovato, quindi la variabile hashPosition è maggiore di 0, allora la
 * lettera è stata trovata e la nuova hashTable è quella restituita dal metodo get contenuto
 * nell'oggetto HashElement. Altrimenti si esce dal ciclo while con un break. Quando si esce
 * dal ciclo while, per essere arrivati alla fine della parola da cercare o per il break, si
 * controlla se il valore di checkWord sia uguale al valore di wordSize, ma soprattutto si
 * verifica che endWord sia vero, perchè se è vero allora si è arrivati ad un fine parola e
 * quindi quella parola esiste nell'albero e si può restituire un true, altrimenti quella
 * non è una fine parola (nonostante magari sia prefisso di qualche altra parola) e deve essere
 * restituito un false.
 */
bool HashTable::searchWordIntoRetrieval(HashTable *hashTable, string word) {
    int  wordSize  = word.size();
    int  index     = -1;
    int  checkWord = 0;
    bool endWord   = false;

    while(++index < wordSize) {
        int  position     = this->hashingMoltiplicationMethod(word.at(index));
        int  hashPosition = this->getCharacterIndex(hashTable->hashLists.at(position), word.at(index));
        endWord           = hashPosition > 0 ? hashTable->hashLists.at(position).at(hashPosition).getEndWord() : false;

        if(hashPosition > 0) {
            checkWord++;
            hashTable = hashTable->hashLists.at(position).at(hashPosition).getHashTable();
        } else {
            break;
        }
    }

    /**
     * La prima condizione deve essere che il valore di checkWord aggiornato ogni volta che
     * una lettera esiste e corrisponde all'interno della HashTable di quel livello è uguale
     * al valore di wordSize, cioè alla lunghezza della parola; La seconda condizione è che
     * il valore di endWord deve essere vero, cioè si deve arrivare necessariamente ad una
     * fine parola, se non si è arrivati alla fine di una parola, allora non si può dire che
     * quella parola stessa esiste all'interno dell'albero.
     */
    return ((checkWord == wordSize && endWord) ? true : false);
}
