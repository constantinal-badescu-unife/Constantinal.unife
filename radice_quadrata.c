/*
1 scrivere una funzione media che restituisca la media aritmetica 
dei suoi due parametri di tipo float;
2 scrivere una funzone radq che approssimi con metodo 
babilonese la radice quadrata del suo parametro di tipo float, 
chiamando la funzione media dove opportuno;
3 chiamare la funzione radq nel main dove opportuno.
Testare il programma invocandolo con input significativi.
*/
#include <math.h>
#include <stdio.h>
float media(float m,float n)
{
  return (m+n)/2.0;
}

float radq(float a)
{
  float x;
  x = 1.0;
  while (fabsf(x * x - a) > 1e-5)
    x = media(x,a / x);//media di x e a/x
  return x;
}

int main(void) {
  float a;
  printf("Digita un numero\n");
  scanf("%f", &a);
  if (a < 0) {
    printf("%f e` negativo\n", a);
    return -1;
  }
  printf("La radice quadrata di %.2f e` circa %f\n", a, radq(a));
  return 0;
}
