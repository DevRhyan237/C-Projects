#include <stdio.h>

float conversor_farenheit(float temperaturaC){
    float tF = ((9.0/5.0)*(temperaturaC)) + 32;
    return tF;
}

float conversor_kelvin(float temperaturaC){
    float tK = 273 + temperaturaC;
    return tK;
}

int main(){
   float temperaturaC;
   float res1, res2;
   int op;
   printf("Informe a temperatura da sua região\nem °C:");
   scanf("%f",&temperaturaC);
   printf("\nInforme a escala para a conversão:\n1-Farenheit\n2-Kelvin\nR:");
   scanf("%d",&op);
   switch(op){
      case 1: 
      {
          res1 = conversor_farenheit(temperaturaC);
          printf("\nA sua temperatura\nem Fahrenheit = %.2f °F",res1);
          break;
      }    
      case 2: 
      {
          res2 = conversor_kelvin(temperaturaC);
          printf("\nA sua temperatura\nem Kelvin = %.2f °K",res2);
          break;
      }    
      default:
      {
          printf("Inválido!");
          break;
      }
   
   }       
}