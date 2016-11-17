#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

enum tipoChar
{
  vocal,
  consonante,
  especial,
  espacio
};

tipoChar queTipoEs(char);

void ingresarOracion(char*);
void ordenarOracion(char*, char*, charEspecial*);
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

void ordenarOracion(char* oracion, char* oracionTransformada, charEspecial* caracteres)
{
  //la magia ha vuelto
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

tipoChar queTipoEs(char letra)
{
  if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
      letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
  {
    return tipoChar.vocal;
  }
  else if (((int)letra >= 65 && (int)letra <= 90) || ((int)letra >= 97 && (int)letra <= 122))
  {
    return tipoChar.consonante;
  }
  else if ((int)letra == 32)
  {
    return tipoChar.espacio;
  }
  else
  {
    return tipoChar.especial;
  }
}
