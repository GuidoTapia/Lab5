#include <iostream>

using namespace std;

int main(){
    string inp,outp;//se define un srting de entrada y uno de salida el cual se imprimira corregido
    bool space=true;//variable binaria para saber si es la primera letra de una palabra
    getline(cin,inp,'\n');//funcion getline en complemento de cin debido a que no se permitia el ingreso de espacios
    for(int i=0;i<inp.length();i++){//for que recorre el texto de entrada
        /*se trabaja con los caracteres de la cadena y su ascii si se trata de una letra la alamcena en el
        string de salida realizando los cambios necesarios, la primera letra de cada palabra se imprimira en mayuscula
        y el resto en minuscula, se ignoraran todos los caracteres que no sean letras*/
        if(inp[i]>64 && inp[i]<91){
            if(space){
                outp+=inp[i];
                space=false;
            }else
                outp+=(inp[i]+32);
        }else if(inp[i]>96 && inp[i]<123){
            if(space){
                space=false;
                outp+=(inp[i]-32);
            }else
                outp+=inp[i];
        }else if(inp[i]==' '){
            space=true;
            outp+=inp[i];
        }
    }
    cout <<"texto de entrada corregido\n"<< outp;
    return 0;
}
