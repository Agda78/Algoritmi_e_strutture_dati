#!/bin/bash

# Controlla se è stato fornito un argomento
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <file sorgente cpp>"
    exit 1
fi

# Salva il nome del file sorgente
SOURCE_FILE="$1"

# Controlla se il file sorgente esiste
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Errore: Il file $SOURCE_FILE non esiste."
    exit 1
fi

# Ottieni il nome base del file senza estensione
EXECUTABLE_NAME="${SOURCE_FILE%.cpp}"

# Compila il file sorgente
if ! g++ "$SOURCE_FILE" -o "$EXECUTABLE_NAME"; then
    echo "Errore durante la compilazione di $SOURCE_FILE."
    exit 1
fi

# Esegui l'eseguibile
echo "--------> ESECUZIONE <--------"
echo ""
"./$EXECUTABLE_NAME"

# Salva il codice di uscita del programma
EXIT_CODE=$?

# Rimuovi l'eseguibile
echo ""
echo "--------> FINE ESECUZIONE <--------"
echo "Pulizia: rimuovo l'eseguibile $EXECUTABLE_NAME"
rm -f "$EXECUTABLE_NAME"

# Restituisci il codice di uscita del programma
exit $EXIT_CODE
