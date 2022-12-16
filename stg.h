/*
    union de operaciones basicas para la cadena char*, seria como usar string pero va para el puntero
    y codigo basico +entendible,  
    entre sus funciones esta:
      calcular longitud de la cadena, 
      concatenar dos cadenas, y 
      reemplazar una parte de una cadena por otra,
      concatenar otra cadena a la original
      reemplazar una parte de la cadena con otra
      cambiar un caracter
      con todo esto facilita la modificacion de la cadena contra ella 
        ..
   ::7777/    .   \\
    7*777777\     77777s\          creado por @MintLanza
       77*777777/ /7777_777/s/      
        7*7777777777s/''  '           github: https://github.com/MintLanza
        /7777777s  ______               creado por: ian
       /7777s       s77iP           programacion en lenguage: c++ >:/
       \77777777///77ii/            
         \777777777                 

*/

class stg{
  private:
  char *date = 0; // almacen
  typedef long long ulong; // mas numeros xd
  long lengthCa(char *txt) // contador
  {
    if (!txt)
    {
      return 0;
    }
    long tmp = 0;
    while (txt[tmp] != '\0')
    {
      tmp++;
    }

    return tmp;
  }

  char *sumCa(char *txt, char *add) // suma de datos
  {
    char *res = new char[sizeof(txt) + sizeof(add)];
    char *deb = res;
    do
    {
      *res = *txt;
      *res++;
    } while (*txt++ != '\0');

    res--;
    do
    {
      *res = *add;
      *res++;
    } while (*add++ != '\0');

    *res = '\0';

    return deb;
  }

public:
  stg(const char *text)
  {
    date = (char *)text;
  }
  long length(){
    return lengthCa(date);
  }
  void operator+=(const char *text)
  {
    date = sumCa(date, (char *)text);
  }
  ::stg operator+(stg &text){
    return sumCa(date, text.date);
    }
    
  const char *get()
  {
    return date;
  }

  char *replace(ulong __s, ulong __e, char *newText) // remplazar
  {
    long tmp = lengthCa(date);
    char *cn = new char[tmp];
    long n1 = 0;
    __s += 1;
    while (n1 != __s)
    {
      cn[n1] = date[n1];
      n1 += 1;
    }
    cn = sumCa(cn, newText);
    n1 += lengthCa(newText);
    tmp = (tmp - (__e - __s)) + lengthCa(newText);
    __e++;
    while (__e != tmp)
    {
      cn[n1] = date[__e];
      n1 += 1;
      __e += 1;
    }
    date = cn;
    return cn;
  }

  char operator[](long num)
  {
    return date[num];
  }
  void edit(long num, char character)
  {
    date[num] = character;
  }

  char *getLoc(int start, int end) // obtencion
  {
    char *IO = new char[end - start];
    char *res = IO;
    long long i = start;

    end += 1;
    do
    {
      *IO = date[i];
      *IO++;
      i += 1;
    } while (!(end < i+1));
    return res;
  }
};

