#include<stdio.h>
#include<math.h>
#include<complex.h>

//Function to input coefficients

void getCoeff(float* a,float* b,float* c)
 {
  printf("Enter the coefficients:\n");
  scanf("%f%f%f",a,b,c);
 }

//Function to computem the discriminant

void getDiscriminant(float* discriminant,float a,float b,float c)
 {
  *discriminant = (b*b)-(4*a*c);
 }

//Function to compute the roots

void computeRoots(float complex* root1,float complex* root2,float a,float b,float c,float discriminant)
 {
  if(discriminant>=0)
   {
    *root1= (-b+sqrt(discriminant))/(2*a);
    *root2= (-b-sqrt(discriminant))/(2*a);
   }
  else
   {
    *root1= CMPLX((-b/(2*a)),(sqrt(discriminant))/(2*a));
    *root2= CMPLX((-b/(2*a)),(sqrt(discriminant))/(2*a));
   }
 }

//Function to display the roots

void displayRoots(float root1,float root2,float discriminant) 
 {
  if(discriminant<=0)
   {
    printf("The real roots of the quadratic equation are: \n");
    printf("Root 1: %.2f\n",root1);
    printf("Root 2: %.2f\n",root2);
   }
  else
   {
    printf("The complex roots of the quadratic equations are: \n");
    printf("Root 1: %.2f + %.2fi\n",creal(root1),cimag(root1));
    printf("Root 2: %.2f + %.2fi\n",creal(root2),cimag(root2));
   }
 }

//main

int main()
 {
  float a,b,c,discriminant;

  getCoeff(&a,&b,&c);
  
  getDiscriminant(&discriminant,a,b,c);
 
  if(discriminant>=0)
   {
    float root1,root2;
    computeRoots(&root1,&root2,a,b,c,discriminant);
    displayRoots(root1,root2,discriminant);
   }
  else
   {
    float complex root1,root2;
    computeRoots(&root1,&root2,a,b,c,discriminant);
    displayRoots(root1,root2,discriminant);
   }
  return 0;
 }
    
