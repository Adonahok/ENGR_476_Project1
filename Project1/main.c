/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Cody Estes
 *
 * Created on September 19, 2017, 11:50 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    char students[7][7];
    int i = 0, j = 0;
    int ID[7];
    int k = 0;
    float SubA[7];
    int l = 0;
    float SubB[7];
    int m = 0;
    
    int p = 0;
    
    int c;
    
    // open file 
    // 'Final Scores' 
    int num;
   FILE *frptr;
   frptr = fopen("C:\\Final Scores.txt","r");

   if(frptr == NULL)
   {
      printf("Error, No 'Final Scores' File Detected");   
      exit(1);             
   }
   
   while(frptr != EOF) {
       c = getc(frptr);
       
       if(c == '\t') {
           c = getc(frptr);
       }
       else {
           switch(p){
               case 0:
                   students[i][j] = c;
                   j++;
                   break;
               case 1:
                   ID[k] = c;
                   k++;
                   break;
               case 2:
                   SubA[l] = c;
                   l++;
                   break;
               case 3:
                   SubB[m] = c;
                   m++;
                   break;
               default:
                   break;
           }
                           
           }
       }
   }

   
    
    //read data from file
    // either use a tokenizer or parser
    
    //collect:
    // Name
    // ID#
    // A
    // B
    
    // Save Information
    // Redo order in ascending order for A 
    
    //calculate average standard deviation
    // A then B
    
    //Output to screen
    
    //Open new file to write
    // send information to file

    return (EXIT_SUCCESS);
}



