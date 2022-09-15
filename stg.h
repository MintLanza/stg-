/*
  github: Rayseis 
  -->D
*/
class stg{
    private:
    char* date = 0;
    typedef long long ulong;
       long lengthCa(char* txt){
         if (!txt) {
          return 0;
        }
        long tmp = 0;
        while (txt[tmp] != '\0') {
               tmp++;
        }

          return tmp;
    }

    char* sumCa(char* txt,char* add){
      char* res = new char[sizeof(txt) + sizeof(add)];
      char* deb = res;
      do
      {
        *res=*txt;
        *res++;
      }
      while( *txt++!='\0' );

      res--;
      do
      {
        *res=*add;
        *res++;
      }
      while( *add++!='\0' );


      *res='\0';

      return deb;
    }


    public:
    stg(const char* text){
        date = (char*)text;
    }

    long length(){
      return lengthCa(date);
    }

    void operator +=(const char* text){
        date = sumCa(date, (char*)text);
    }
    ::stg operator+(stg const &text){
        date = sumCa(date, text.date);
    }
    :: stg operator+(char* const &text){
        date = sumCa(date, (char*)text);
    }
    const char* get(){
        return date;
    }

    char* replace(ulong __s, ulong __e, char* newText){
            long tmp = lengthCa(date);
            char* cn = new char[tmp];
            long n1 = 0;
            __s += 1;
            while(n1 != __s){
                cn[n1] = date[n1];
                n1 += 1;
            }
            cn = sumCa(cn, newText);
            n1 += lengthCa(newText);
            tmp = (tmp - (__e - __s)) + lengthCa(newText); 
            __e++;
            while(__e != tmp){
                cn[n1] = date[__e];
              n1 += 1;
              __e += 1;
            }
            /*
            ulong tmp2 = 0;
            char* tg2 = date;
            cn = sumCa(cn, newText);
            ulong tmp1 = 0;
            n1 += __e;
            while(true){
                if(tg2[n1] == '\0'){
                    break;
                }
                cn[tmp2] = tg2[n1];
                tmp2 += 1;
                n1 += 1;
            }
          */
            date = cn;
            return cn;
        }
    
    char operator[](long num){
        return date[num];
    }
    void edit(long num, char character){
        date[num] = character;
    }
};
