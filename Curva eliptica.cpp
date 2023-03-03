#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct pontos{
  
  float x1;
  float x2;
  float y1;
  float y2;
        
};

/*
DADOS UTILIZADOS PARA MATEMATICA DA CURVA ELIPTICA

P(x1,y1)
Q(x2,y2)

Equação da curva eliptica:
y^2 = x^3+Ax+B

Condição de contorno para realizar a criptografia:
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
int main(){
    
pontos P, Q;
float x3, y3, m, b, A;

//Implementação do caso P diferente de Q

printf("\nInsira valores para os pontos Px1 e Py1: ");
scanf("%f %f", &P.x1, &P.y1);

printf("\nInsira valores para os pontos Qx2 e Qy2: ");
scanf("%f %f", &Q.x2, &Q.y2);

srand((unsigned)time(NULL));
A = rand();

if(P.x1 != Q.x1 && P.y1 != Q.y1){

        
m = (Q.y2 - P.y1)/Q.x2 - P.x2;    
b = P.y1 - m*P.x1;    
x3 = (pow(m,2))- P.x1 - Q.x2; //Descobrindo o terceiro ponto em x3
y3 = m*x3 + b; //Descobrindo o terceiro ponto em y3

    } 

else if (P.x1 == Q.x1 && P.y1 == Q.y1 ){

m = (3*(pow(P.x1,2))+A)/2*P.y1; //Equação já na forma derivada da equação da curva eliptica
b = P.y1 - m*P.x1;

x3 = (pow(m,2))- P.x1 - Q.x2; //Descobrindo o terceiro ponto em x3
y3 = m*x3 + b; //Descobrindo o terceiro ponto em y3

    }   
    
}