#include <iostream>
#include <cstdlib>

#include "Retrieval.h"

using namespace std;

int main(int argc, char *argv[]) {
    /**
     * In input da linea di comando prendiamo il file che contiene le parole,
     * ed inoltre la parola da ricercare.
     */
    if(argc < 3) {
        cout << "Usage: ./main [file_of_words].[txt] [word_to_search]" << endl;
        exit(-1);
    }

    /**
     * Se il numero di input corrisponde allora istanziamo un oggetto di tipo
     * Retrieval e richiamiamo i metodi per poter inserire le parole contenute
     * nel file nell'albero e per ricercare una parola all'interno dell'albero
     * stesso.
     */
    Retrieval retrieval = Retrieval();
    retrieval.getWordsFromFile(argv[1]);
    retrieval.searchWord(argv[2]);

    return 0;
}