#include <stdlib.h>
#include <stdio.h>

//El caracter extra (41°) es agregado para el null '\0'
#define MAX 41

//Creamos el tipo de dato bool
typedef int bool;
enum { false, true };

struct charEspecial
{
  char caracter;
  int posicion;
};

void ingresarOracion(char*);
void ordenarOracion(char*, char*);
void mostrarOracionTransformada(char*);
void mostrarCaracteresEspeciales(charEspecial*);

int main()
{
  char oracion[MAX];
  char oracionTransformada[MAX];
  charEspecial caracteres[MAX];

  ingresarOracion(oracion);
  ordenarOracion(oracion, oracionTransformada, caracteres);
  mostrarOracionTransformada(oracionTransformada);
  mostrarCaracteresEspeciales(caracteres);

  system("pause");

  return 0;
}

void ingresarOracion(char* oracion)
{
  printf("Ingrese una oracion (max. 40 caracteres): ");
  scanf("%s", oracion);
}

void inicializarStrings(char* string, int largo)
{
  for(int i=0; i<largo; i++)
  {
    string[i]=0;
  }
}

void inicializarCharEspeciales(charEspecial* caracteres, int largo)
{
  for(int i=0; i<largo; i++)
  {
    caracteres[i].caracter=0;
    caracteres[i].posicion=0;
  }
}

void ordenarOracion(char* oracion, char* oracionTransformada, charEspecial* caracteres)
{
    int pos = 0;
    int posVocales = 0;
    int posConsonantes = 0;
    int posInicioPalabra = 0;
    int posOracionTransformada = 0;
    int posCaracteresEspeciales = 0;
    char vocales[MAX];
    char consonantes[MAX]
    int caracterInicial = 0; // 1 = vocal  2 = consonante//
    while(oracion[pos] != '\0')
    {
        posInicioPalabra=pos;
        while(esCaracterEspecial(oracion[posInicioPalabra]))
        {
            posInicioPalabra++;
        }
        if(esVocal(oracion[posInicioPalabra]) caracterInicial = 1;
        if(esConsonante(oracion[posInicioPalabra])) caracterInicial = 2;
        while(oracion[pos] != ' ')
        {
            if(esVocal(oracion[pos]))
            {
                vocales[posVocales] = oracion[pos];
                posVocales++;
            }
            if(esConsonante[oracion[pos]])
            {
                consonantes[posConsonantes] = oracion[pos];
                posConsonantes++;
            }
            if(esCaracterEspecial)
            {
                if(oracion[pos + 1] == ' ')
                {

                }
            }
        }

        pos++;
    }
}

void mostrarOracionTransformada(char* oracionTransformada)
{
  printf("Oracion transformada: %s\n", oracionTransformada);
}

void mostrarCaracteresEspeciales(charEspecial* caracteres)
{
  int pos = 0;
  printf("Caracteres especiales:\n");
  while(caracteres[pos] != '\0')
  {
    printf("%c - Posicion: %i\n", caracteres[pos].caracter, caracteres[pos].posicion);
    pos++;
  }
}
