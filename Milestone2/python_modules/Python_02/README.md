
### 🛠️ Regole Generali da Sapere (Prima degli Esercizi)
* **Requisiti tecnici:** Il codice deve usare Python 3.10+, rispettare il linter `flake8` e includere i *type hints* (da verificare con `mypy`)
* **Obiettivo principale:** I programmi **non devono mai crashare**. Devono usare blocchi `try/except` per intercettare gli errori  e garantire l'integrità del sistema anche in caso di anomalie dei sensori

---

### 🪴 Esercizio 0: Agricultural Data Validation
* **Cosa fa:** Prende una stringa di testo (es. la temperatura inviata da un sensore), la converte in intero e gestisce l'errore se la stringa contiene testo non valido (es. `"abc"`)  senza far crashare il programma.

---

### 🌡️ Esercizio 1: Agricultural Data Validation Pipeline
* **Cosa fa:** Estende l'esercizio 0. Oltre a convertire il dato in numero, controlla se la temperatura è accettabile per le piante (tra `0` e `40` gradi inclusi). Se è fuori range, lancia un'eccezione personalizzata con un messaggio di errore specifico (troppo caldo / troppo freddo).

---

### 🔍 Esercizio 2: Different Types of Problems

#### 📝 Risposte alle Domande in Blu (Cap. VII):
1. **Perché Python ha diversi tipi di errore?** 
   Python utilizza diversi tipi di eccezioni (es. `ValueError`, `TypeError`) per identificare la natura esatta del problema. Questo permette allo sviluppatore (e al programma) di capire *cosa* è andato storto (un calcolo errato, un file mancante, un dato del tipo sbagliato) e di rispondere a ogni problema nel modo più appropriato.
2. **Come si possono catturare più tipi di errore con un singolo `try`?** 
   Si possono catturare inserendo più blocchi `except` di seguito sotto lo stesso `try` , oppure inserendo le diverse eccezioni all'interno di una tupla in un unico blocco `except`. 
   *Nota del documento: Non è consentito usare la funzione `type()` per identificare l'errore.* 

#### 💡 Spiegazioni importanti aggiuntive per l'Ex 2:
* L'esercizio richiede di simulare volutamente 4 errori specifici in base a un numero operazione (da 0 a 3) : `ValueError` (testo convertito in numero) , `ZeroDivisionError` (divisione per zero) , `FileNotFoundError` (apertura di un file inesistente)  e `TypeError` (sommare testo e numeri).
* **Attenzione a mypy:** `mypy` segnalerà giustamente l'errore di tipo nel codice del `TypeError`. Questo errore va lasciato di proposito per poter testare il comportamento del programma.

---

### ⚠️ Esercizio 3: Making Your Own Error Types

#### 📝 Risposte alle Domande in Blu (Cap. VIII):
1. **Quando dovresti creare i tuoi tipi di errore invece di usare quelli predefiniti di Python?** 
   Si creano eccezioni personalizzate quando gli errori standard di Python sono troppo generici per il contesto del programma. Nel caso di questa serra digitale, ricevere un `ValueError` non spiega se il problema è legato alla salute della pianta o al sistema di irrigazione. Un errore personalizzato rende il codice molto più chiaro, parlante e facile da manutenere.
2. **In che modo l'ereditarietà aiuta a organizzare i diversi tipi di errore?** 
   L'ereditarietà permette di creare una gerarchia logica. Se crei un errore base chiamato `GardenError` e fai ereditare da esso `PlantError` (problemi alle piante) e `WaterError` (problemi d'acqua) , puoi decidere di catturare in modo specifico solo i problemi idrici , oppure usare un unico `except GardenError` per catturare *qualsiasi* problema legato al giardino in un colpo solo.

#### 💡 Spiegazioni importanti aggiuntive per l'Ex 3:
* Le classi di errore personalizzate devono essere semplici e devono ereditare da `Exception` o da un'altra tua eccezione personalizzata. Devono includere un messaggio di errore di default (es. `"Unknown plant error"`) nel caso in cui non venga specificato un messaggio al momento del lancio.

---

### 🧹 Esercizio 4: Finally Block - Always Clean Up

#### 📝 Risposte alle Domande in Blu (Cap. IX):
1. **Perché è importante ripulire las risorse anche quando si verificano errori?** 
   Perché risorse come file aperti, connessioni di rete o, in questo scenario reale, le *valvole di irrigazione fisiche*, potrebbero rimanere "bloccate" o aperte se il programma si interrompe bruscamente a causa di un errore. Questo potrebbe causare sprechi d'acqua, allagamenti o corruzione dei dati.
2. **In che modo il blocco `finally` aiuta a garantire che la pulizia avvenga sempre?** 
   Il blocco `finally` è una garanzia assoluta in Python: il codice al suo interno **viene eseguito sempre**, sia se il blocco `try` viene completato con successo, sia se viene intercettato un errore nel blocco `except` , e persino se il programma esegue un'istruzione di chiusura immediata (`return`).

#### 💡 Spiegazioni importanti aggiuntive per l'Ex 4:
* La funzione deve simulare l'irrigazione di diverse piante. L'irrigazione ha successo solo se il nome della pianta è scritto con la prima lettera maiuscola (es. "Tomato" è OK, "lettuce" lancia un `PlantError`).
* **Logica di interruzione:** Se una pianta non è valida, il test deve bloccarsi immediatamente e ritornare al `main`. Anche in questo caso di uscita forzata, il blocco `finally` si attiverà prima del ritorno al main per "chiudere il sistema di irrigazione".