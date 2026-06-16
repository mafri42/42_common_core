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



