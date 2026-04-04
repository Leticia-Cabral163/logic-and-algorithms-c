#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
  Exercício: Cálculo de Área de uma circuferência
  Objetivo: Praticar entrada de dados e condicionais.
  Data: Abril/2024
 */
float raio, area;
int main()
{
    printf ("\n calcular a area de uma circunferencia\n");	
	printf  ("\n digite o raio da circunferencia....:");
	scanf   ("\%f", &raio);
	area = 3.14 * pow(raio, 2);
    printf ("\n A area da circunferencia de raio %.2f..: %.2f\n\n", raio, area );
    system ("pause");
     return 0;

}
