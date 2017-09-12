#include <iostream>

using namespace std;

const int filas=3,columnas=4;

void orden(float m[][columnas]){
    /*algoritmo de ordenamiento por seleccion se recorre la matriz buscando el elemento menor e insertarlo de forma ordenada*/
    int mini;
    int im,jm;
    for(int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            mini=m[i][j];
            im=i;
            jm=j;
            int i2=i;
            int j2=j+1;
            if(j>=columnas){
                i2++;
                j2=0;
            }
            while(i2<filas){
                while(j2<columnas){
                    if(m[i2][j2]<mini){
                        im=i2;
                        jm=j2;
                        mini=m[i2][j2];
                    }
                    j2++;
                }
                i2++;
                j2=0;
            }
            if(im!=i||jm!=j){
                //intercambio del elemento seleccionado con el indice actual
                float aux;
                aux=m[i][j];
                m[i][j]=m[im][jm];
                m[im][jm]=aux;
            }

        }
    }
    return;
}
void resultados(float m[][columnas],float r[]){
    //primero se imprime la matriz ordenada a la vez que se realiza la suma de los elementos para poder hallar el promedio
    cout<<"------------------------------------"<<endl;
    cout<< "matriz ordenada:"<< endl;
    for(int i=0;i<filas;i++){
        cout<< "|\t";
        for (int j=0;j<columnas;j++){
            r[2]+=m[i][j];//se suma los elementos para hallar el promedio
            cout<< m[i][j]<<"\t";
        }
        cout<<"|"<<endl;
    }
    cout<<"------------------------------------"<<endl;
    cout<< "resultados:"<< endl;
    r[0]= (float)m[0][0];// minimo es decir el primer elemento en la matriz ordenada
    r[1]= (float)m[filas-1][columnas-1];//maximo es decir el ultimo elemento en la matriz ordenada
    r[2]= r[2]/(filas*columnas);//se divide la suma de todos los elementos entre el numero de elementos
    /*tres posibles casos para la mediana:
        si la cantidad de filas es par se tomaran el ultimo y el primer elemento de las filas del medio-semisuma
        si la cantidad de filas es impar y la de columnas par se tomaran dos elementos medios de la fila media-semisuma
        si tanto la cantidad de filas y columnas es impar se tomara el elemento medio de la fila media*/
    if (filas%2==0){
        r[3]=(m[(filas/2)-1][columnas-1]+m[filas/2][0])/2;
    }else if (filas%2==1&&columnas%2==0){
        r[3]=(m[filas/2][(columnas/2)-1]+m[filas/2][columnas/2])/2;
    }else{
        r[3]=m[filas/2][columnas/2];
    }
    //Se imprimen los resultados almacenados
    cout<< "min\tmax\tprom\tmediana"<< endl;
    for(int i=0;i<4;i++){
        cout<<r[i]<< "\t";
    }
    cout << endl;
}
int main()
{
    float m[filas][columnas];
    float r[]={0.0,0.0,0.0,0.0};
    for(int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            cin>> m[i][j];
        }
    }
    orden(m);
    //con la matriz ordenada se procede a hallar el minimo,maximo,promedio y mediana y almacenarlos en un arreglo r
    resultados(m,r);
    return 0;
}
