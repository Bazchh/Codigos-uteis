#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Tentativas de se implementar a matematica da curva eliptica em um algoritmo em C++ */
/* OBS: ainda incompleto */

struct pontos{
  
  float x;
  float y;

        
};

/*
DADOS UTILIZADOS PARA MATEMATICA DA CURVA ELIPTICA

P(x1,y1)
Q(x2,y)

Equação da curva eliptica:
y^2 = x^3+Ax+B

Condição de contorno para realizar a criptografia:
Desta forma necessitamos de uma curva eliptica não singular, ou seja, que satifaz a condição abaixo
4A^3+27B^2≠0

CASO P DIFERENTE DE Q {

Equação da reta:
y = mx+b

Para encontrar o m:

m = y2 - y1/x2-x1

Para encontrar o b da reta devemos primeiro encontrar o m, segue:
b = y1 - mx1
}

CASO P = Q = (x1,y1) {

Realizar a derivada da equação da curva eliptica, segue:

d(y^2) = d(x^3+Ax+B)
2ydy = (3x^2+A)dx
dy/dx = 3x^2+A/2y


Para calcular o coeficiente angular m neste caso, segue:

m = 3x1^2+A/2y1

Para calcular o b neste caso, segue o mesmo metodo:

b = y1 - mx1
    
}
*/

float coefiecienteM1(pontos P, pontos Q){
float m;

    m = (Q.y - P.y)/Q.x - P.x;
    
    return m;
}

float coefiecienteM2(pontos P, pontos Q, float A){
float m;

    m = (3*(pow(P.x,2))+A)/2*P.y;
    
    return m;
}

void imprimePonto(pontos P){
    printf("\nPonto x = %f", P.x);
    printf("\nPonto y = %f", P.y);
}

int main(){
    
pontos P, Q, R;
float m, n, A;

//Implementação do caso P diferente de Q

printf("\nInsira valores para os pontos Px1 e Py1: ");
scanf("%f %f", &P.x, &P.y);

printf("\nInsira valores para os pontos Qx2 e Qy2: ");
scanf("%f %f", &Q.x, &Q.y);

A = rand()%1000;

if(P.x != Q.x && P.y != Q.y){
        
m = coefiecienteM1(P,Q);   
n = P.y - m*P.x;    
R.x = (pow(m,2))- P.x - Q.x; //Descobrindo o terceiro ponto em x3
R.y = m*R.x + n; //Descobrindo o terceiro ponto em y3
R.y = -1*R.y;//Conjugado
    } 
else if (P.x == Q.x && P.y == Q.y ){

m = coefiecienteM2(P, Q, A); //Equação já na forma derivada da equação da curva eliptica
n = P.y - m*P.x;

R.x = (pow(m,2))- P.x - Q.x; //Descobrindo o terceiro ponto em x3
R.y = m*R.x + n; //Descobrindo o terceiro ponto em y3
R.y = -1*R.y; //Conjugado
    }   
    
imprimePonto(R);

printf("\n\n");

}


/*
Alguns dados obtidos:

Para obtermos o terceiro ponto, x3 e y3 temos a equação de formato (mx+n)^2 = x3 + Ax + B
logo, igualamos a equação a 0, segue

 0 = x^3 + Ax + B - (mx+n)^2

 Temos que encontrar agora os zeros da equação, porém, já obtemos 2 desses zeros, o de x1 e x2 e precisamos agora do zero do terceiro ponto x3 e construimos uma equação 
 com o seguinte formato:

0 = A(x - x1)(x - x2)(x - x3)

Abrindo a equação, tem-se:

0 = x^3 - (x1+x2+x3)x^2 + (x1x2+x2x3+x3x1)x - x1x2x3

Agora comparamos a primeira equação com a ultima obtida e criamos relação entre os termos para encontrarmos o terceiro ponto

x^3 - (x1+x2+x3)x^2 + (x1x2+x2x3+x3x1)x - x1x2x3 = x3 + Ax + B - (mx+n)^2

*/
