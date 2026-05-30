
### Regole Comuni Fondamentali (Valide per tutto il progetto)

* **Requisiti tecnici:** Il codice deve utilizzare **Python 3.10 o successivo** e rispettare lo standard di codifica `flakes`.


* **Controlli di tipo:** Tutte le funzioni e i metodi devono includere i *type hints* (indicazioni di tipo), verificabili tramite lo strumento `mypy`.


* **Gestione degli errori:** I programmi devono gestire le eccezioni in modo grazioso (*gracefully*) per evitare crash improvvisi.


* **Divieto I/O:** **Non è permesso** leggere o scrivere file. Tutti i dati vanno elaborati in memoria o tramite passaggi di argomenti da riga di comando. I soli tipi standard inizialmente ammessi sono `str`, `int` e `float`.



---

### Capitolo II: AI Instructions (Istruzioni sull'uso dell'IA)

* **Domanda in blu implicitamente posta dagli esempi sulle "Buone e Cattive Pratiche":** *Cosa succede se copio-incollo codice dall'IA senza capirlo?*
* **Risposta:** Perdi credibilità e **fallisci il progetto**. L'IA va usata per ridurre compiti ripetitivi e tediosi, ma devi accettare e utilizzare solo codice che hai compreso appieno e di cui puoi assumerti la responsabilità durante la correzione tra pari (*peer-evaluation*).





---

### Esercizio 0: Command Quest (`ex0/`)

* **Focus:** Introduzione alle liste tramite i parametri da riga di comando (`sys.argv`).


* **Funzioni permesse:** `import sys`, `sys.argv`, `len()`, `print()`.


* **Risposta alla domanda/suggerimento in blu:** *Ci sono molteplici modi per evitare di stampare il nome del programma insieme agli argomenti. Preparati a discutere soluzioni alternative.*
* **Spiegazione:** In Python, `sys.argv[0]` contiene sempre il nome dello script. Per escluderlo e prendere solo gli argomenti veri e propri passati dall'utente, il metodo più comune ed elegante è lo **slicing** della lista: `sys.argv[1:]`. Un'alternativa (che modifica però la lista originale) è l'uso di `.pop(0)`.





---

### Esercizio 1: Score Cruncher (`ex1/`)

* **Focus:** Uso delle liste per memorizzare punteggi numerici presi da riga di comando e blocchi `try/except` per scartare input non validi.


* **Funzioni permesse:** `import sys`, `sys.argv`, `len()`, `sum()`, `max()`, `min()`, `print()`.


* **Spiegazione importante:** Se l'utente inserisce parametri misti (es. numeri e lettere), il programma deve scartare quelli non numerici stampando un errore per ciascuno, ma deve comunque procedere al calcolo delle statistiche (totale, media, massimo, minimo, range) sui rimanenti dati validi.



---

### Esercizio 2: Position Tracker (`ex2/`)

* **Focus:** Uso delle **tuple** per tracciare coordinate 3D `(x, y, z)`.


* **Funzioni permesse:** `import math`, `math.sqrt()`, `input()`, `round()`, `print()`.


* **Risposta alla nota in blu:** *Le tuple sono come dati scolpiti nella pietra. Una volta create, non cambiano.*
* **Spiegazione:** Le tuple sono strutture dati **immutabili**. A differenza delle liste, una volta definita una coordinata non puoi fare operazioni come `tupla[0] = 5.0`. Se la posizione del giocatore cambia, va creata una tupla completamente nuova. Per l'esercizio dovrai implementare la formula della distanza euclidea usando `math.sqrt()`.





---

### Esercizio 3: Achievement Hunter (`ex3/`)

* **Focus:** Uso dei **set (insieme)** per gestire i trofei dei giocatori.


* **Funzioni permesse:** `len()`, `print()`, `import random`, `random.*`, `set()`, `set.union()`, `set.intersection()`, `set.difference()`.


* **Risposta alla domanda in blu:** *Come stampa Python un insieme vuoto, e perché?*
* **Risposta:** Python stampa un insieme vuoto come `set()`. Non lo stampa come `{}` perché le parentesi graffe vuote `{}` sono utilizzate per definire un **dizionario vuoto**. Per evitare ambiguità sintattiche, i set vuoti hanno questa rappresentazione letterale unica.


* **Spiegazione importante:** I set non contengono duplicati e sono disordinati. Dovrai usare `.union()` per trovare tutti i trofei distinti, `.intersection()` per quelli comuni a tutti, e `.difference()` per scovare i trofei unici di un giocatore o quelli mancanti.



---

### Esercizio 4: Inventory Master (`ex4/`)

* **Focus:** Uso dei **dizionari** (`chiave: valore`) per gestire l'inventario degli oggetti.


* **Funzioni permesse:** `import sys`, `sys.argv`, `len()`, `print()`, `sum()`, `list()`, `round()`, `dict.keys()`, `dict.values()`, `dict.update()`.


* **Risposta alla nota in blu:** *All'inizio del gioco, il tuo inventario è solitamente vuoto ;)*
* **Spiegazione:** Dovrai inizializzare un dizionario vuoto `inventario = {}` (o `dict()`). Successivamente, analizzerai gli argomenti della riga di comando formattati come `nome_oggetto:quantità`. Se un oggetto viene ripetuto, va scartato come ridondante anziché aggiornato (come mostrato nell'output di esempio: *Redundant item 'sword' discarding*). Dovrai infine calcolare le percentuali di abbondanza e aggiungere un nuovo elemento alla fine con `.update()` o assegnazione diretta.





---

### Esercizio 5: Stream Wizard (`ex5/`)

* **Focus:** Uso dei **generatori** con la parola chiave `yield` per creare flussi di dati infiniti o su richiesta, risparmiando memoria.


* **Funzioni permesse:** `next()`, `range()`, `len()`, `print()`, `import typing`, `typing.Generator`, `import random`, `random.*`.


* **Spiegazione importante:** La funzione `gen_event()` non deve usare `return`, ma `yield` per generare un evento alla volta ogni volta che viene invocato `next()`. Il secondo generatore richiesto, `consume_event`, estrarrà e rimuoverà casualmente elementi da una lista fino a svuotarla, e deve essere strutturato per funzionare direttamente dentro un ciclo `for ... in ...`.



---

### Esercizio 6: Data Alchemist (`ex6/`)

* **Focus:** Uso delle **comprehensions** per liste e dizionari, per trasformare e filtrare dati in modo compatto.


* **Funzioni permesse:** `import random`, `random.*`, `print()`, `len()`, `sum()`, `round()`.


* **Risposta alla nota in blu:** *È possibile usare le comprehensions anche sui set. Ogni comprehension dovrebbe stare su una singola riga (a meno che non superi la lunghezza massima della riga).*
* **Spiegazione:** Le *comprehensions* sono uno strumento potentissimo in Python per rimpiazzare i classici cicli `for` lunghi. Per i set la sintassi usa le graffe `{oggetto for oggetto in lista}`. L'esercizio richiede tassativamente che le tue conversioni (es. nomi maiuscoli, filtraggio dei punteggi sopra la media) siano scritte in **un'unica riga di codice** per ciascuna operazione richiesta.