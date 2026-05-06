*This project has been created as part of the 42 curriculum by masacco.*
***
# 📚 PUSH_SWAP
***
## Table of Contents
1. [Description](#Description)
2. [Instructions](#Instructions)
3. [Resources](#Resources)
4. [Structure](#Structure)
4. [Algorithm](#Algorithm)
***
## 📝 Description
Questo progetto implementa una soluzione al problema di ordinamento utilizzando due stack (`a` e `b`) e un set limitato di operazioni.
L’obiettivo è ordinare una lista di numeri interi nel minor numero possibile di mosse, rispettando i vincoli imposti dal progetto.
---
## 🛠️ Instructions
Il progetto è gestito da un Makefile che compila:
• l'eseguibile pushswap  
• le librerie necessarie (libft, ft_printf)

Per compilare il progetto, esegui:
```bash
make

```
## 🤖 Resources
- Strutture dati: linked lists
- Algoritmi di ordinamento:
  - Bubble sort (utilizzato per il calcolo della mediana)
- Concetti:
  - Greedy algorithms
  - Cost-based optimization
  - Stack operations

## 🔗 Structure
Il progetto è organizzato nei seguenti file:

- `push_swap.c`
  - Entry point del programma
  - Gestisce parsing, controlli iniziali e avvio dell’algoritmo

- `algorithm.c`
  - Contiene la logica principale dell’algoritmo
  - Gestione della mediana e strategia di ordinamento

- `moves.c`
  - Calcolo dei costi di rotazione
  - Scelta del nodo migliore da muovere (`push_count`)
  - Esecuzione delle mosse ottimizzate

- `index.c`
  - Assegna un indice a ogni nodo dello stack
  - Necessario per il calcolo dei costi

- `stack.c`
  - Funzioni per la gestione dello stack
  - Controllo ordinamento
  - Gestione casi piccoli (es. `sort_three`)

- `operations_*.c`
  - Implementazione delle operazioni richieste dal progetto:
    - `sa`, `sb`, `ss` (swap)
    - `pa`, `pb` (push)
    - `ra`, `rb`, `rr` (rotate)
    - `rra`, `rrb`, `rrr` (reverse rotate)

- `ps_utils.c` / `ps_utils1.c`
  - Funzioni di utilità:
    - parsing e validazione input
    - gestione memoria
    - funzioni matematiche (abs, max, cost calculation)

## Algorithm
L'algoritmo turco (rivisitato) implementato segue questi passaggi:

- Calcolo della mediana dello stack A
- Push iniziale degli elementi da A a B basato sulla mediana
- Ordinamento diretto dei casi piccoli (2 o 3 elementi)
- Calcolo del costo di rotazione per ogni elemento
- Selezione del nodo con il costo minimo
- Reinserimento ottimizzato da B ad A
- Rotazione finale per portare il minimo in cima

L’approccio è quindi basato su:
- divisione del problema (median split)
- ottimizzazione delle mosse (cost calculation)
- rotazioni combinate (rr / rrr)