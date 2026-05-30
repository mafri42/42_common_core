
## 📌 Regole Generali Utili (Valide per tutto il progetto)

Prima di passare ai singoli esercizi, ci sono alcune specifiche tecniche tassative da rispettare:

* 
**Versione Python:** Il codice deve essere scritto in Python 3.10 o successivo.


* 
**Stile e Qualità:** Obbligatorio rispettare gli standard del linter `flake8` e includere i **type hints** in tutte le funzioni e metodi, verificandoli con `mypy`.


* 
**Gestione Errori:** I programmi devono gestire le eccezioni con grazia senza crashare.


* 
**Restrizione `with`:** Non puoi usare l'istruzione `with` fino all'esercizio 3. Negli esercizi 0, 1 e 2 devi gestire l'apertura e la chiusura dei file manualmente.



---

## 📁 Esercizio 0: Ancient Text Recovery

* **Directory:** `ex0/` | **File da consegnare:** `ft_ancient_text.py` 


* 
**Obiettivo:** Creare uno script che prenda il nome di un file come argomento da riga di comando (`sys.argv`), ne legga il contenuto e lo stampi a schermo imitando il comando `cat`, aggiungendo un'intestazione e un piè di pagina personalizzati. Deve saper gestire file inesistenti o non accessibili.



> ### ❓ Risposta alla domanda dell'esercizio:
> 
> 
> 1. What is the type of the data returned by `open()`? 
> 
> 
> In Python, la funzione `open()` in modalità di lettura testo predefinita (`'r'`) restituisce un oggetto che appartiene a una delle sottoclassi di **`io.TextIOBase`** (nello specifico, solitamente un’istanza di `_io.TextIOWrapper`). Questo oggetto è un file object di tipo testuale (stream di testo) dotato di metodi propri come `.read()`, `.readline()` e `.close()`.

* 
**Spiegazione extra importante:** Ricordati che l'argomento del file si recupera tramite `sys.argv[1]`. Se l'utente non passa argomenti o ne passa troppi, il programma deve mostrare il corretto messaggio di utilizzo (`Usage: ft_ancient_text.py <file>`) anziché rompersi. Ricordati sempre di invocare `.close()` sul file nel blocco `finally` o dopo la lettura.



---

## 📝 Esercizio 1: Archive Creation

* **Directory:** `ex1/` | **File da consegnare:** `ft_archive_creation.py` 


* 
**Obiettivo:** Estendere il codice dell'esercizio precedente. Dopo aver letto e mostrato il file originario, il programma deve:


1. Aggiungere il carattere `#` alla fine di ogni riga letta.


2. Mostrare a schermo il testo modificato.


3. Chiedere all'utente (tramite `input()`) il nome di un nuovo file in cui salvare la versione modificata. Se l'utente lascia vuoto, non si salva nulla.




* 
**Spiegazione extra importante:** Se il file di destinazione esiste già, il codice deve sovrascriverlo completamente (apertura in modalità `'w'`). Non ci sono domande specifiche in questo esercizio, ma è fondamentale gestire l'input vuoto in modo pulito stampando un messaggio di conferma come `"Not saving data."`.



---

## 🔀 Esercizio 2: Stream Management

* **Directory:** `ex2/` | **File da consegnare:** `ft_stream_management.py` 


* 
**Obiettivo:** Evolvere ulteriormente il codice dell'esercizio 1 per padroneggiare i flussi di input/output standard del sistema (`sys.stdin`, `sys.stdout`, `sys.stderr`).


* **Modifiche richieste:**
1. 
**Errori su STDERR:** Tutti i messaggi di errore derivanti dalle eccezioni (es. file non trovato o permessi negati) **non** devono più essere stampati sul canale standard (`stdout`), ma diretti esplicitamente su `sys.stderr` preceduti dal prefisso `[STDERR]`.


2. 
**Vietato `input()`:** Non puoi più usare la funzione nativa `input()` per chiedere il nome del file. Devi invece leggere direttamente dallo standard input sfruttando `sys.stdin.readline()` o `sys.stdin.read()`.




* **Spiegazione extra importante:** Quando leggi da `sys.stdin.readline()`, il testo catturato conterrà il carattere di "a capo" (`\n`) alla fine. Ricordati di rimuoverlo usando `.strip()` o `.replace('\n', '')` prima di provare ad aprire il file, altrimenti l'apertura fallirà sistematicamente.

---

## 🔒 Esercizio 3: Vault Security

* **Directory:** `ex3/` | **File da consegnare:** `ft_vault_security.py` 


* 
**Obiettivo:** Cambiare completamente struttura e approccio implementando la funzione `secure_archive()`. Questo esercizio **impone l'uso del costrutto `with**` (context manager) , che garantisce la chiusura automatica dei file liberando le risorse di sistema anche in caso di eccezioni.


* **Specifiche della funzione `secure_archive()`:**
* 
**Parametri:** 1. Nome del file (`str`, obbligatorio).
2. Azione da compiere (`int` o `str`, facoltativo) per definire se leggere o scrivere.
3. Contenuto da scrivere (`str`, facoltativo, usato solo in caso di scrittura).


* 
**Output:** Deve restituire una tupla composta da un booleano e una stringa `(True|False, str)`.


* In caso di successo: `(True, "Contenuto del file o messaggio di successo")`.


* In caso di errore: `(False, "Messaggio dell'eccezione catturata")`.


* 
**Spiegazione extra importante:** Durante la valutazione/difesa orale, i professori verificheranno con attenzione la struttura del codice per assicurarsi che tu sappia spiegare dettagliatamente come il context manager (`with`) gestisca i metodi magici `__enter__` e `__exit__` dietro le quinte per prevenire i leak di memoria.