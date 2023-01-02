# stg-
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
      
            creado por @MintLanza   
            github: https://github.com/MintLanza
            creado por: ian
            programacion en lenguage: c++ >:/
     
me pillo un error en sumCa, estube usando sizeof cual es incorrecto, genero un problema en la redaccion de muchas sumas ya que este declaraba cadenas con un tamaño de 2 punteros incorrectamente 
generando un clip en la sumas de todo el texto a sumas ya que ordena asignar un caracter en una localidad no exstente:
````
res por sizeof es de 2 caracters
    res[3] = txt[3] // genera error ya que no hat mas de 2 caracteres
````
solucion mejor ordenar el temao por la misma funcionn de stg, length()
