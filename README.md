# Push_swap

**push_swap** è un progetto che ha come obiettivo l'implementazione di un algoritmo per ordinare una pila di numeri interi utilizzando un set limitato di operazioni e un'architettura basata su due pile (`A` e `B`).

---

## 📜 Descrizione

Il progetto consiste nello sviluppo di due componenti principali:
1. **push_swap**: Un programma che calcola e stampa la sequenza ottimale di operazioni necessarie per ordinare la pila `A`.
2. **checker** (opzionale): Un programma che verifica se una sequenza di operazioni fornita ordina correttamente la pila `A`.

### Obiettivi principali:
- Ordinare una pila di numeri nel minor numero possibile di mosse.
- Utilizzare solo le operazioni fornite dal progetto.
- Gestire pile di dimensioni variabili, ottimizzando le prestazioni.

---

## ⚙️ Operazioni disponibili

Le operazioni valide sono:

- **Swap**: Scambia i primi due elementi della pila.
  - `sa`: Scambia i primi due elementi di `A`.
  - `sb`: Scambia i primi due elementi di `B`.
  - `ss`: Esegue `sa` e `sb` contemporaneamente.

- **Push**: Sposta il primo elemento da una pila all'altra.
  - `pa`: Sposta il primo elemento di `B` in `A`.
  - `pb`: Sposta il primo elemento di `A` in `B`.

- **Rotate**: Ruota la pila, spostando il primo elemento in fondo.
  - `ra`: Ruota `A`.
  - `rb`: Ruota `B`.
  - `rr`: Esegue `ra` e `rb` contemporaneamente.

- **Reverse rotate**: Ruota la pila al contrario, spostando l'ultimo elemento in cima.
  - `rra`: Ruota `A` al contrario.
  - `rrb`: Ruota `B` al contrario.
  - `rrr`: Esegue `rra` e `rrb` contemporaneamente.

---

## 🛠️ Requisiti

Per compilare ed eseguire il progetto, assicurati di avere:
- Un compilatore C (es. GCC).

---

## ⚙️ Compilazione
make
Dopo la compilazione, verranno generati gli eseguibili:

- push_swap
- checker

## 🚀 Esecuzione

### 1. Utilizzo di `push_swap`
Il programma `push_swap` calcola la sequenza di operazioni necessaria per ordinare una lista di numeri.

**Comando:**
```
./push_swap <numeri>
Esempio:
./push_swap 4 3 2 1
Output atteso:

pb
pb
sa
pa
pa
```
### 2. Utilizzo di `checker`

Il programma `checker` verifica se una sequenza di operazioni ordina correttamente la pila `A`.

**Comando:**
```
./checker 4 3 2 1   (uscira l'input da inserire)
pb
pb
sa
pa
pa
```
a quuesto punto se la pila risulta ordinata uscira in output `ok` altrimenti `ko`

## 📝 Debug e Test

### Test delle operazioni
Puoi verificare l'esattezza del tuo algoritmo testandolo con diverse combinazioni di numeri, utilizzando:

```
ARG="4 3 2 1"; ./push_swap $ARG | ./checker $ARG
Output atteso:


OK
Verifica del numero di mosse
Puoi calcolare il numero di operazioni generate da push_swap con il seguente comando:
./push_swap 4 3 2 1 | wc -l
```
##🎯 Obiettivi di ottimizzazione
- Pile piccole (3-5 numeri):
L'algoritmo deve essere in grado di ordinare i numeri nel minor numero possibile di mosse.

- Pile grandi (100-500 numeri):
Mira a ottimizzare l'algoritmo per ottenere un punteggio basso secondo i criteri del progetto.


> **💡 Suggerimento:**
> ci sono diversi tester grafici su github 
