#include <stdio.h>

/* Concepto: paso por referencia mediante apuntadores (ver 5.3.2 y 6.1).
   La función recibe la dirección del primer elemento y modifica el arreglo original. */
void duplicar(int *ptr, int n){
   int i;
   for(i=0;i<n;i++){
      *(ptr+i) = *(ptr+i) * 2;   /* indirección: se modifica el valor apuntado */
   }
}

int main(){
   int datos[8] = {5, 12, 18, 25, 31, 7, 40, 22};
   int *p, *q;
   int i, n = 8;
   int valor, pos, mayores = 0;
   FILE *archivo;

   /* & devuelve la dirección de memoria de su operando. Se usa al asignar
      a un apuntador para guardar en él la DIRECCIÓN de la variable (6.1).
      Un apuntador guarda direcciones, no valores. Sin & se asignaría un
      entero a un apuntador, lo cual es un error. */
   p = &datos[0];   /* equivale a p = datos; */

   /* Diferencia entre p y *p:
      - p  es el apuntador: contiene una dirección de memoria.
      - *p es el valor almacenado en esa dirección (indirección). */
   printf("Recorrido con aritmética de apuntadores:\n");
   for(i=0;i<n;i++){
      printf("Dirección: %p  Valor: %d\n", (void *)p, *p);
      /* Al incrementar un apuntador a int, avanza sizeof(int) bytes (normalmente 4),
         es decir, apunta al siguiente entero del arreglo: la aritmética de
         apuntadores se hace en relación a su tipo base (6.1). */
      p++;
   }

   /* Después del recorrido p quedó al final del arreglo; se reinicia. */
   p = &datos[0];

   duplicar(p, n);
   printf("\nArreglo duplicado:\n");
   for(i=0;i<n;i++){
      printf("%d ", *(p+i));
   }
   printf("\n");

   /* q apunta al tercer elemento (posición 2). */
   q = p + 2;
   /* La diferencia q - p NO es en bytes: es el número de elementos (enteros)
      que separan a ambos apuntadores. Aquí vale 2, porque el tercer elemento
      está dos posiciones después del primero. */
   printf("\nDiferencia q - p = %ld elementos\n", (long)(q - p));

   /* Escritura: cada valor con su posición, uno por línea. */
   archivo = fopen("resultados.txt", "w");
   if(archivo == NULL){
      printf("No se pudo abrir resultados.txt para escritura\n");
      return 1;
   }
   for(i=0;i<n;i++){
      fprintf(archivo, "%d %d\n", i, *(p+i));
   }
   fclose(archivo);

   /* Lectura: se muestran los datos y se cuentan los mayores que 50. */
   archivo = fopen("resultados.txt", "r");
   if(archivo == NULL){
      printf("No se pudo abrir resultados.txt para lectura\n");
      return 1;
   }
   printf("\nContenido de resultados.txt (posición valor):\n");
   while(fscanf(archivo, "%d %d", &pos, &valor) == 2){
      printf("Posición %d: %d\n", pos, valor);
      if(valor > 50){
         mayores++;
      }
   }
   fclose(archivo);

   printf("\nValores mayores que 50: %d\n", mayores);
   return 0;
}
