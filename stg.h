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


bool isFont(char character){
    try{
    if((character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
        return true;
    }
    }catch(const std::exception& e){
        return false;
    }
    
    
    return false;
}
bool FontIsNumber(char character){
    try{
    if(character == 48 || 48 < character && character < 58 || character == 57){
        return true;
    }
    }catch(const std::exception& e){
        return false;
    }
    return false;
}
bool FontINum(char character){
    try{
    if(isFont(character) || FontIsNumber(character)){
        return true;
    }
    }catch(const std::exception& e){
        return false;
    }
    return false;
}

class stg {
private:
    const char* data = 0;
    char* sumCa(char *txt, char *add) {
        char *res = new char[stg(txt).length() + stg(add).length()];
        char *deb = res;
            do{
                *res = *txt;
                *res++;
            } while (*txt++ != '\0');
        res--;
        do{
            *res = *add;
            *res++;
        } while (*add++ != '\0');
        *res = '\0';
        return deb;
     }
public:
    stg(const char* text = ""){
        data = text;
    }

    stg operator+(const stg &_adder_text)  {
         data = sumCa((char*)data, (char*)_adder_text.data);
    }

    stg operator+(const char* _adder_text)  {
         data = sumCa((char*)data, (char*)_adder_text);
    }
    stg operator+(char c)  {
         data = sumCa((char*)data,(char*)c);
    }
    stg operator+=(const char* _adder_Text) {
         data = sumCa((char*)data, (char*)_adder_Text);
    }
    stg operator+=(char c) {
         data = sumCa((char*)data, (char*)c);
    }

    long length() const {
            if (!data){
                return 0;
            }
            long tmp = 0;
            while (data[tmp] != '\0'){
                tmp++;
            }
        return tmp;
    }

    char operator[](long localidad) const {
        return data[localidad];
    }

    const char* get(long start, long end){
        if(start < 0 || end <= start || end < 0){
            return "";
        }
        if(end < 1){
            return "";
        }
        char *IO = new char[end - start];
        char *res = IO;
        long long i = start;
        do{
            *IO = data[i];
            *IO++;
            i += 1;
        } while (!(end < i+1));
        return (const char*)res;
    }
    const char* get() const {
        return data;
    }
    const char* operator()() const {
        return data;
    }
    char* operator()() {
        return (char*)data;
    }
    bool IS(const char* argm, long type = 0){
        if(type == 1){
            if(stg(argm).length() < length()){
                return false;
            }
            for (size_t i = 0; i < stg(argm).length(); i++){
                if(argm[i] !=  data[i]){
                    return false;
                }
            }
            return true;
        }
        if(argm == data){
            return true;
        }
        return false;
    }
    const char* replace(const char* adder_text, long start, long end){
        stg io = get(0, start);
        io += adder_text;
        io += get(end, length());
        data = io.get();
        return data;
    }

};
