virtual enviroment "stanza privata dove solo io vedo i pacchetti installati" 

global enviroment "stanza pubblica dove tutti vedono i pacchetti installati"

# Spiegazione del codice EX0

## Perché usi `sys.prefix != sys.base_prefix`?

`sys.base_prefix` punta sempre all'installazione Python originale.

`sys.prefix` invece punta all'ambiente attualmente utilizzato.

Se sono diversi significa che sto usando una virtual environment.

---

## A cosa serve `sys.executable`?

```python
print(sys.executable)
```

Mostra il percorso dell'interprete Python in esecuzione.

Esempio:

```text
/usr/bin/python3
```

oppure:

```text
/home/user/matrix_env/bin/python
```

---

## A cosa serve `os.path.basename()`?

Se ho:

```python
sys.prefix
```

che vale:

```text
/home/user/matrix_env
```

allora:

```python
os.path.basename(sys.prefix)
```

restituisce:

```text
matrix_env
```

cioè solo l'ultimo pezzo del percorso.

---

## A cosa serve `site.getsitepackages()`?

Restituisce le cartelle dove Python installa i pacchetti.

Esempio:

```python
site.getsitepackages()
```

può restituire:

```python
[
    "/home/user/matrix_env/lib/python3.11/site-packages"
]
```

Noi stampiamo il primo elemento:

```python
site.getsitepackages()[0]
```

---

# Come testarlo prima della consegna

## 1. Verifica fuori dalla virtual environment

Esegui:

```bash
python3 construct.py
```

Dovresti vedere qualcosa come:

```text
MATRIX STATUS: You're still plugged in
```

---

## 2. Crea la virtual environment

```bash
python3 -m venv matrix_env
```

---

e controlla che sia stata creata (ls)

## 3. Attivala

### Linux/macOS

```bash
source matrix_env/bin/activate
```

```bash
python3 -c "import sys; print(sys.prefix); print(sys.base_prefix)"
```

## 4. Riesegui il programma

```bash
python3 construct.py
```

Dovresti vedere:

```text
MATRIX STATUS: Welcome to the construct
```

insieme al percorso della virtual environment e alla cartella dei pacchetti installati.

---

## 5. Disattiva la virtual environment

```bash
deactivate
```

eliminare la env prima di pushare!!!!!

e tornerai all'ambiente Python globale.
# Gestione della virtual environment

## 1. Se sei DENTRO la virtual environment

Prima esci:

```bash
deactivate
```

Se il prompt non mostra più `(matrix_env)`, sei fuori.

---

## 🗑️ 2. Eliminare la virtual environment

La virtual environment è solo una cartella, quindi si cancella così:

```bash
rm -rf matrix_env
```

---

## ⚠️ Cosa fa questo comando?

- `rm` = remove (cancella)
- `-r` = ricorsivo (cancella anche file dentro cartelle)
- `-f` = forzato (non chiede conferma)

👉 Quindi elimina completamente la venv.

---

## ✅ 3. Verifica che sia sparita

```bash
ls
```

Dovresti vedere solo:

```text
construct.py
```

(o gli altri file del progetto)

---

## 💡 Importante (da 42 evaluator)

Non devi mai consegnare `matrix_env` nel repository.

---

## 🔁 Workflow corretto

```bash
python3 -m venv matrix_env
source matrix_env/bin/activate
python3 construct.py
deactivate
rm -rf matrix_env
```

## EX1

🥇 1. loading.py (PRIMA COSA DA FARE)

Perché:

è il cuore dell’esercizio
ti dice quali librerie ti servono davvero
ti fa capire cosa mettere nei file requirements.txt e pyproject.toml

👉 Senza loading.py, gli altri due file sono “a caso”

🥈 2. requirements.txt

Lo fai dopo perché:

nasce da quello che IMPORTI nel codice
serve per pip
🥉 3. pyproject.toml

Ultimo perché:

è la versione Poetry degli stessi identici requisiti
lo scrivi quando sai già cosa ti serve davvero

````md
# ex1 - Loading Programs (Matrix Data Analysis)

## 📌 Obiettivo dell’esercizio

Questo progetto simula il caricamento di “Matrix data” e serve a dimostrare:

- gestione delle dipendenze Python
- uso di ambienti virtuali
- differenza tra pip e Poetry
- analisi dati con librerie scientifiche
- generazione di grafici

---

# 🧠 Concetti fondamentali

## 🟢 Virtual Environment (venv)

Una virtual environment è un ambiente Python isolato.

### Perché serve?

- evita conflitti tra progetti diversi
- non modifica Python di sistema
- permette installazioni indipendenti

### Creazione:

```bash
python3 -m venv matrix_env
```

### Attivazione:

```bash
source matrix_env/bin/activate
```

### Uscita:

```bash
deactivate
```

### Eliminazione:

```bash
rm -rf matrix_env
```

---

## 🟡 pip (package manager)

pip serve per installare librerie Python.

### Installazione da file:

```bash
pip install -r requirements.txt
```

### Cos’è requirements.txt?

È un file che contiene le dipendenze del progetto.

Esempio:

```txt
numpy
pandas
matplotlib
requests
```

### Idea chiave:

pip installa pacchetti **dentro la venv**, non globalmente.

---

## 🔵 Poetry (dependency manager moderno)

Poetry è uno strumento più avanzato di pip.

### Cosa fa:

- gestisce dipendenze
- crea ambienti isolati
- usa pyproject.toml

### Installazione:

```bash
poetry install
```

### Esecuzione:

```bash
poetry run python loading.py
```

### Differenza con pip:

| pip | Poetry |
|-----|--------|
| requirements.txt | pyproject.toml |
| manuale | automatico |
| semplice | più strutturato |

---

## 🟣 numpy

Libreria per numeri e array.

### Nel progetto:

```python
np.random.normal(0, 1, 1000)
```

👉 genera 1000 numeri casuali con distribuzione normale

---

## 🟠 pandas

Serve per analisi dati strutturati.

### Nel progetto:

```python
pd.DataFrame({"matrix": data})
```

👉 trasforma array in tabella

---

## 🔴 matplotlib

Serve per creare grafici.

### Nel progetto:

```python
plt.hist(df["matrix"], bins=50)
```

👉 crea istogramma della distribuzione

```python
plt.savefig("matrix_analysis.png")
```

👉 salva il grafico su file

---

## 🟤 requests (opzionale)

Serve per fare richieste HTTP.

Non è usato obbligatoriamente, ma incluso per simulare dipendenze reali.

---

# 🚀 Esecuzione del programma

```bash
python3 loading.py
```

---

# 📊 Output atteso

```text
LOADING STATUS: Loading programs...
Checking dependencies:
[OK] pandas (2.1.0) - Data manipulation ready
[OK] numpy (1.25.0) - Numerical computation ready
[OK] requests (2.31.0) - Network access ready
[OK] matplotlib (3.7.2) - Visualization ready

Analyzing Matrix data...
Processing 1000 data points...
Generating visualization...

Analysis complete!
Results saved to: matrix_analysis.png

Package versions:
numpy: ...
pandas: ...
matplotlib: ...
```

---

# 📈 Output grafico

Il programma genera:

```text
matrix_analysis.png
```

👉 istogramma della distribuzione dei dati

---

# ⚙️ requirements.txt (pip)

```txt
numpy
pandas
matplotlib
requests
```

---

# 🧾 pyproject.toml (Poetry)

```toml
[tool.poetry]
name = "matrix-loading"
version = "1.0.0"
description = "Matrix data analysis"
package-mode = false

[tool.poetry.dependencies]
python = "^3.10"
numpy = "*"
pandas = "*"
matplotlib = "*"
requests = "*"

[build-system]
requires = ["poetry-core"]
build-backend = "poetry-core.masonry.api"
```

---

# 📦 Installazione pip

```bash
python3 -m venv matrix_env
source matrix_env/bin/activate
pip install -r requirements.txt
```

---

# 📦 Installazione Poetry

```bash
poetry install
poetry run python loading.py
```

---

# ⚠️ Gestione errori nel codice

Il programma usa:

```python
try:
    import numpy
except ImportError:
    print("Missing dependency")
```

👉 serve a gestire librerie mancanti in modo controllato

---

# 🧪 Concetti imparati

- virtual environments
- isolamento delle dipendenze
- pip vs Poetry
- generazione dati con numpy
- analisi con pandas
- visualizzazione con matplotlib
- gestione errori import

---

# 📁 Struttura progetto

```text
ex1/
├── loading.py
├── requirements.txt
├── pyproject.toml
├── matrix_analysis.png
└── matrix_env/   ❌ NON consegnare
```

---

# ❌ Nota importante

Mai pushare la venv nel repository:

```bash
rm -rf matrix_env
```

---
```
````
