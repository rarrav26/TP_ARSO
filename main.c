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

enum tipoChar
{
  vocal,
  consonante,
  especial,
  espacio,
  null
};

enum tipoChar queTipoEs(char);
void vaciarVector(char*);
void vaciarCharsEsp(struct charEspecial*);

void ingresarOracion(char*);
void ordenarOracion(char*, char*, struct charEspecial*);
void agregarNuevaPalabra(char*, int*, char*, char*, char, enum tipoChar, bool);
void mostrarNuevaOracion(char*);
void mostrarCaracteresEspeciales(struct charEspecial*);

int main()
{
  char oracion[MAX];
  char nuevaOracion[MAX];
  struct charEspecial caracteres[MAX];

  vaciarVector(oracion);
  vaciarVector(nuevaOracion);
  vaciarCharsEsp(caracteres);

  ingresarOracion(oracion);
  ordenarOracion(oracion, nuevaOracion, caracteres);
  mostrarNuevaOracion(nuevaOracion);
  mostrarCaracteresEspeciales(caracteres);

  system("pause");

  return 0;
}

void ingresarOracion(char* oracion)
{
  printf("Ingrese una oracion (max. 40 caracteres): ");
  fgets(oracion, MAX, stdin);
}

void ordenarOracion(char* oracion, char* nuevaOracion, struct charEspecial* caracteres)
{
  int pos = 0, posPalabra = 0, posNuevaOracion = 0, posCaracteres = 0;
  //Mientras que no sea el fin de la oracion
  while (queTipoEs(oracion[pos]) != null)
  {
    //Si es un espacio, lo tiramos a la nuevaOracion
    if (queTipoEs(oracion[pos]) == espacio)
    {
      nuevaOracion[posNuevaOracion] = oracion[pos];
      posNuevaOracion++;
    }
    else
    {
      bool primerLetra = false;
      enum tipoChar ordenarPrimero;
      char vocales[MAX], consonantes[MAX], caracterFinal = '\0';
      int posVocal = 0, posConsonante = 0;
      vaciarVector(vocales);
      vaciarVector(consonantes);
      posPalabra = pos;

      //Mientras que no sea un espacio y no sea un nulo
      while (queTipoEs(oracion[posPalabra]) != espacio && queTipoEs(oracion[posPalabra]) != null)
      {
        if (!primerLetra)
        {
          if (queTipoEs(oracion[posPalabra]) == vocal)
          {
            primerLetra = true;
            ordenarPrimero = vocal;
          }
          else if (queTipoEs(oracion[posPalabra]) == consonante)
          {
            primerLetra = true;
            ordenarPrimero = consonante;
          }
        }

        //Si es un caracter especial y le sigue un espacio o un nulo, lo tiramos a la nuevaOracion
        if (queTipoEs(oracion[posPalabra]) == especial && (queTipoEs(oracion[posPalabra+1]) == espacio || queTipoEs(oracion[posPalabra+1]) == null))
        {
          caracterFinal = oracion[posPalabra];
        }
        //Si es un caracter especial, lo guardamos para después mostrarlo
        else if (queTipoEs(oracion[posPalabra]) == especial)
        {
          caracteres[posCaracteres].caracter = oracion[posPalabra];
          caracteres[posCaracteres].posicion = posPalabra + 1;
          posCaracteres++;
        }
        //Si es una vocal, la guardamos en vocales
        else if (queTipoEs(oracion[posPalabra]) == vocal)
        {
          vocales[posVocal] = oracion[posPalabra];
          posVocal++;
        }
        //Si es una consonante, la guardamos en consonantes
        else if (queTipoEs(oracion[posPalabra]) == consonante)
        {
          consonantes[posConsonante] = oracion[posPalabra];
          posConsonante++;
        }

        posPalabra++;
      }

      agregarNuevaPalabra(nuevaOracion, &posNuevaOracion, vocales, consonantes, caracterFinal, ordenarPrimero, primerLetra);
      pos = posPalabra - 1;
    }
    pos++;
  }
}

void agregarNuevaPalabra(char* nuevaOracion, int* posNuevaOracion, char* vocales, char* consonantes, char caracterFinal, enum tipoChar ordenarPrimero, bool primerLetra)
{
  int posVocales = 0, posConsonantes = 0;
  if (primerLetra)
  {
    if (ordenarPrimero == vocal)
    {
      while (vocales[posVocales] != '\0')
      {
        nuevaOracion[*posNuevaOracion] = vocales[posVocales];
        *posNuevaOracion = *posNuevaOracion + 1;
        posVocales++;
      }
      while (consonantes[posConsonantes] != '\0')
      {
        nuevaOracion[*posNuevaOracion] = consonantes[posConsonantes];
        *posNuevaOracion = *posNuevaOracion + 1;
        posConsonantes++;
      }
    }
    else if (ordenarPrimero == consonante)
    {
      while (consonantes[posConsonantes] != '\0')
      {
        nuevaOracion[*posNuevaOracion] = consonantes[posConsonantes];
        *posNuevaOracion = *posNuevaOracion + 1;
        posConsonantes++;
      }
      while (vocales[posVocales] != '\0')
      {
        nuevaOracion[*posNuevaOracion] = vocales[posVocales];
        *posNuevaOracion = *posNuevaOracion + 1;
        posVocales++;
      }
    }
  }

  if (caracterFinal != '\0')
  {
    nuevaOracion[*posNuevaOracion] = caracterFinal;
    *posNuevaOracion = *posNuevaOracion + 1;
  }
}

void mostrarNuevaOracion(char* nuevaOracion)
{
  printf("Nueva oracion: %s\n", nuevaOracion);
}

void mostrarCaracteresEspeciales(struct charEspecial* caracteres)
{
  int pos = 0;
  if (caracteres[pos].caracter != '\0')
  {
    printf("Caracteres\tPosicion\n");
  }
  else
  {
    printf("No se extrajeron caracteres especiales.\n");
  }
  while(caracteres[pos].caracter != '\0')
  {
    printf("%c\t\t%i\n", caracteres[pos].caracter, caracteres[pos].posicion);
    pos++;
  }
}

enum tipoChar queTipoEs(char letra)
{
  if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
      letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
  {
    return vocal;
  }
  else if (((int)letra >= 65 && (int)letra <= 90) || ((int)letra >= 97 && (int)letra <= 122))
  {
    return consonante;
  }
  else if ((int)letra == 32)
  {
    return espacio;
  }
  else if ((int)letra == 0 || (int)letra == 10)
  {
    return null;
  }
  else
  {
    return especial;
  }
}

void vaciarVector(char* vec)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    vec[i] = '\0';
  }
}

void vaciarCharsEsp(struct charEspecial* vec)
{
  int i;
  for (i = 0; i < MAX; i++)
  {
    vec[i].caracter = '\0';
    vec[i].posicion = 0;
  }
}
