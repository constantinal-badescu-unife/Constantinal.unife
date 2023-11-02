/*
Si scriva una funzione in linguaggio C che calcola, 
per un numero n ě 1, il valore della
funzione matematica Πpnq, definita come il 
numero di numeri primi minori o uguali a n.

Πp1q “ 0
Πp2q “ 1 t2u
Πp3q “ 2 t2, 3u
Πp4q “ 2 t2, 3u
Πp5q “ 3 t2, 3, 5u

Scrivere un programma per testare la funzione.
*/

#include <stdio.h>

// vale 1 se n è primo e 0 altrimenti
int primo(int n) {
  int i;  // Si = [1,2,...,n]
  int l;  // l = reduce(++,0,Sd)
  l = 0;  // inizializzazione accumulatore
  if (n < 2)
    return 0;
  for (i = 2; i * i <= n && l == 0; i++) {
    // Si = [1,2,...,n]
    if (n % i == 0) {
      // So = [divisori di n] = filter(i divide n,Si)
      l++;
    }
  }
  if (l == 0)
    return 1;
  else
    return 0;
}

// numero di numeri primi <= m
int PI(int m) {
  int i;
  int contatore;
  contatore = 0;  // inizializzo accumulatore
  for (i = 1; i <= m; i++) {
    // i assume i valori di S1
    if (primo(i)) {
      // i assume i valori di S2 = filter(primo, S1)
      contatore++;
    }
  }
  return contatore;
}

int main() {
  int n;

  printf("Inserisci un numero intero positivo\n");
  scanf("%d", &n);
  printf("PI(%d) = %d\n", n, PI(n));
  return 0;
}