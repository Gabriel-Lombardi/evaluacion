#include <stdio.h>
#include <stdlib.h>

// Imprimir un menu de informacion, con las viandas que existen
void print_menu(char* viandas[4], int precio[4]) {
  int cantidad;
  printf("VIANDAS PARA OFICINA\nMenu:\n");
  for(int i = 0; i < 4; i++) {
    printf("%d. %s ($%d)\n", i+1, viandas[i], precio[i]);
  }
}

// Pedir la cantidad de viandas que se quiere
int unidades(void) {
  int cantidad;
  printf("Ingrese la cantidad de viandas que vendio: ");
  scanf("%d", &cantidad);
  return cantidad;
}

// Pedir las viandas que se quiere
int eleccion(int n) {
  int producto;
  printf("Ingrese la vianda numero %d que vendio: ", n+1);
  scanf("%d", &producto);
  return producto-1;
}

int main(void) {
  // Declaramos los operadores, los precios de las viandas, la cantidad de
  // viandas que se quiere y los tipos de viandas
  int operadores[7] = {1,2,3,4,5,6,7};
  int precios[4] = {2500,5000,3500,4000};
  int ganancias_operador[7] = {0,0,0,0,0,0,0};
  int ventas_operador[7] = {0,0,0,0,0,0,0};
  int cantidad;
  char* viandas[4] = {"Vegetales","Carnes","Pescado","Frutas"};
  print_menu(viandas,precios);
  printf("Aclaracion.\nCada tipo de vianda es UN pedido, por lo tanto se debe solicitar la cantidad total por vianda.\n");
  for(int i = 0; i < 7; i++){
    printf("\nVentas del operador numero %d\n", i+1);
    cantidad = unidades();
    ventas_operador[i] = cantidad;
    int productos[cantidad];
    for(int j = 0; j < cantidad; j++) {
      productos[j] = eleccion(j);
    }
    if(cantidad > 4) {
      for(int k = 0; k < cantidad; k++) {
        ganancias_operador[i] = (ganancias_operador[i] + precios[productos[k]]) * 0.13;
      }
    }
    else {
      for(int k = 0; k < cantidad; k++) {
        ganancias_operador[i] = (ganancias_operador[i] + precios[productos[k]]) * 0.1;
      }
    }
  }
  // imprimir ventas por operadores
  for(int i = 0; i < 7; i++) {
    printf("Operador numero %d\n", i+1);
    printf("Numero de ventas: %d\nGanancias: %d\n", ventas_operador[i], ganancias_operador[i]);
  }
}
