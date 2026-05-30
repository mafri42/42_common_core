# ## **Informazioni Generali Preliminari**

* **Versione Python richiesta:** Python 3.10+.

* **Standard di formattazione:** Codice conforme a `flake8` e controllo dei tipi obbligatorio con `mypy` (tutte le funzioni e i metodi devono avere i *type hints*).

* **Convenzioni sui nomi:** Classi in `PascalCase`, funzioni e variabili in `snake_case`.

* Ogni esercizio deve risiedere nella propria cartella e nel proprio file dedicato.

---

# ## **Definizioni Chiave della OOP (Da sapere per la difesa)**

> * **Classe:** È il *progetto* iniziale o lo stampo (es. il concetto astratto di `Plant`). Definisce quali caratteristiche e comportamenti avranno gli oggetti creati da essa.
>
> * **Oggetto (o Istanza):** È l'elemento reale e concreto creato partendo dal progetto della classe (es. una specifica `Rose` di 25cm).
>
> * **`self`:** Rappresenta l'oggetto specifico che sta eseguendo l'azione in quel momento. Serve a indicare a Python di modificare o leggere i dati di *quella* precisa istanza (es. l'altezza di *quella* rosa) e non di un'altra.

---

# ## **Esercizio 0: Planting Your First Seed**

* **Directory / File:** `ex0/ft_garden_intro.py`.

* **Cosa fare:** Creare un semplice programma che salvi le informazioni di una pianta (nome, altezza, età) in variabili semplici e le stampi a schermo imitando l'output dell'esempio. È obbligatorio usare il costrutto `if __name__ == "__main__":`.

* **Funzioni autorizzate:** `print()`.

> ### 💡 Concetti Teorici Importanti (Box Blu):
>
> * **A cosa serve `if __name__ == "__main__":`?** Isola il codice di test. Impedisce che il codice di visualizzazione venga eseguito automaticamente se il file viene importato come modulo in un altro script in futuro.
>
> * **Cos'è la linea "Shebang" (`#!`)?** È la prima riga di uno script (es. `#!/usr/bin/env python3`) che dice al sistema operativo Unix quale interprete usare per avviare il file. *Nota: il valutatore ti chiederà di aggiungerla live per rendere lo script direttamente eseguibile*.

---

# ## **Esercizio 1: Garden Data Organizer**

* **Directory / File:** `ex1/ft_garden_data.py`.

* **Cosa fare:** Creare una classe `Plant` che faccia da modello. Deve avere gli attributi `name`, `height` (in cm) e `age` (in giorni). Bisogna istanziare almeno 3 piante diverse, impostare i loro attributi e mostrare le informazioni nel terminale tramite un metodo della classe chiamato `show()`.

* **Funzioni autorizzate:** `print()` (e il metodo `.capitalize()` delle stringhe per l'output).

> ### 💡 Concetti Teorici Importanti (Box Blu):
>
> * **Limiti dell'approccio:** Se si impostano gli attributi manualmente dopo l'istanza (es. `p1.name = "Rose"`), all'aumentare delle piante il codice diventa ridondante, disordinato e difficile da scalare. Diventa quindi necessario evolvere l'approccio automatizzando la creazione con un costruttore.

---

# ## **Esercizio 2: Plant Growth Simulator**

* **Directory / File:** `ex2/ft_plant_growth.py`.

* **Cosa fare:** Riutilizzare la classe `Plant` dell'Esercizio 1 aggiungendo i metodi `grow()` (crescere) e `age()` (invecchiare) che modificano lo stato interno dell'oggetto. Il programma deve simulare una settimana di crescita (7 giorni), mostrando l'evoluzione giorno per giorno e un riassunto finale della crescita totale.

* **Funzioni autorizzate:** `print()`, `range()`, `round()`.

---

# ## **Esercizio 3: Plant Factory**

* **Directory / File:** `ex3/ft_plant_factory.py`.

* **Cosa fare:** Ottimizzare il processo di creazione delle piante. Modificare la classe `Plant` in modo che possa essere istanziata e inizializzata contemporaneamente passando i dati di partenza direttamente alla costruzione. Creare almeno 5 piante diverse e stamparle usando lo stesso metodo `show()` invariato.

* **Funzioni autorizzate:** `print()`, `range()`, `round()`.

> ### 💡 Concetti Teorici Importanti:
>
> * **Il metodo `__init__` (Costruttore):** È il metodo speciale di Python che viene eseguito automaticamente nel momento esatto in cui crei un oggetto. Serve ad assegnare i valori iniziali ai campi dell'oggetto in modo immediato e pulito.

---
---

# ## **Esercizio 4: Garden Security System**

* 
**Directory / File:** `ex4/ft_garden_security.py`.


* 
**Cosa fare:** Proteggere l'integrità dei dati dagli errori dei volontari. Gli attributi della classe non devono essere accessibili direttamente (usa la convenzione "protetta" con un singolo underscore, es. `_height`, non il name mangling con il doppio underscore). Bisogna implementare i metodi sicuri `get_height()`, `get_age()`, `set_height()`, `set_age()`. I metodi "set" devono validare che i valori non siano negativi, altrimenti stampano un errore e rifiutano la modifica.


* 
**Funzioni autorizzate:** `print()`, `range()`, `round()`.



> ### 💡 Concetti Teorici Importanti:
> 
> 
> * **Incapsulamento:** Consiste nel nascondere i dati interni di un oggetto (rendendoli "protetti") e consentirne la modifica o la lettura solo tramite metodi controllati (chiamati **Getter** per leggere e **Setter** per scrivere) , garantendo la validazione dei dati.
> 
> 

---

# ## **Esercizio 5: Specialized Plant Types**

* 
**Directory / File:** `ex5/ft_plant_types.py`.


* 
**Cosa fare:** Creare tre sottoclassi specifiche a partire dalla classe madre `Plant`:


1. 
`Flower`: aggiunge l'attributo `color` e il metodo `bloom()`.


2. 
`Tree`: aggiunge l'attributo `trunk_diameter` e il metodo `produce_shade()`.


3. 
`Vegetable`: aggiunge `harvest_season` e `nutritional_value` (quest'ultimo aumenta quando si chiamano `age()` e `grow()`).




* All'interno delle sottoclassi bisogna usare `super()` per richiamare i metodi della classe madre (compresi `__init__` e `show()`) per estendere le funzionalità senza duplicare il codice.


* 
**Funzioni autorizzate:** `super()`, `print()`, `range()`, `round()`.



> ### 💡 Concetti Teorici Importanti (Box Blu):
> 
> 
> * **Sottoclasse ed Ereditarietà:** Consente a una classe figlia di ereditare automaticamente tutti gli attributi e i metodi della classe madre.
> * **`super()` ed Overriding (Sovrascrittura):** L'overriding avviene quando la sottoclasse riscrive un metodo della classe madre (es. `show()`) per fargli fare cose in più. Tramite `super().show()` si richiama prima il comportamento base della classe madre per poi aggiungere le stampe degli attributi specifici della sottoclasse, evitando ripetizioni inutili di codice.
> 
> 

---

# ## **Esercizio 6: Garden Analytics**

* 
**Directory / File:** `ex6/ft_garden_analytics.py`.


* 
**Cosa fare:** Integrare le classi precedenti con strumenti analitici avanzati:


* Un metodo statico in `Plant` che verifica se un'età passata come parametro è maggiore di un anno (365 giorni).


* Un metodo di classe in `Plant` per generare una pianta "anonima" (`Unknown plant`) se mancano i dati iniziali.


* Una classe `Seed` che eredita da `Flower` e gestisce il numero di semi dopo la fioritura.


* Una classe interna (**nested class**) in `Plant` che funge da contatore privato per tracciare il numero di chiamate effettuate ai metodi `grow()`, `age()` e `show()`. I `Tree` tracciano anche le chiamate a `produce_shade()`.


* Una funzione esterna (non parte di nessuna classe) che accetta una pianta qualsiasi e ne stampa le statistiche a schermo.




* 
**Funzioni autorizzate:** `super()`, `print()`, `range()`, `round()`, `staticmethod()`, `classmethod()` (è accettata anche la sintassi con i decoratori `@staticmethod` e `@classmethod`).



> ### 💡 Concetti Teorici Importanti:
> 
> 
> * **`@staticmethod`:** Una funzione normale inserita nella classe solo per motivi di organizzazione logica. Non ha accesso né a `self` (all'oggetto) né a `cls` (alla classe).
> * **`@classmethod`:** Un metodo che riceve come primo parametro la classe stessa (`cls`) anziché l'oggetto (`self`). Viene utilizzato principalmente come costruttore alternativo per istanziare oggetti in modi particolari.
> * **Nested Class (Classe Interna):** Una classe definita dentro un'altra classe. Serve a strutturare componenti complessi che hanno senso solo all'interno del sistema principale (come il rilevatore di statistiche di una specifica pianta).
> 
>