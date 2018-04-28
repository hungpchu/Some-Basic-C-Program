#include<stdio.h>


int main(){


int i, space, star = 0, rows = 7;

for ( i =1 ; i <= rows ; i++){
/*
HHHHHH
HHHHH
HHHH
HHH
HH
H

*/
 for ( space = 1; space <= rows - i; space++)
                {
                  printf(" ");
                 }
 /*               
*
*H*
*HHH*
*HHHHH*
*HHHHHHH*
*HHHHHHHHH*
*HHHHHHHHHHH*
     */         
 
             
               
        while( star != 2*i - 1){
        if ( star == 0 || star == 2*i - 2){
                    printf("*");
        }
   else printf(" ");
    star++;
    }
    
    // khoi tao luc xet xong
    star= 0;
    printf("\n");
    }
    
    
    // bien dong duoi tu 7 thanh 6
    rows--;
    
   
   
    for ( i = rows ; i >= 1 ; i--){

        for ( space = 0; space <= rows - i; space++)
                {
                  printf(" ");
                 }
        
         star = 0;    
        while( star != 2*i - 1){
        if ( star == 0 || star == 2*i - 2){
                    printf("*");
    }
    else printf(" ");
    star++;
    }
    star = 0;
   printf("\n");
    }
  
  
    return 0;
    }
