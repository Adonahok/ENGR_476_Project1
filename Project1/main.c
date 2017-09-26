/*
 * ENGR 476 - Project 1 - C Code
 *
 * Code reads from a file called "FinalScores.txt" and 
 * gathers information about 7 students:
 * name, ID No., Subject A Score, and Subject B Score.
 * After opening and reading the file, the averages
 * for subject A and subject B are calculated, followed
 * by the standard deviation of each. 
 * Subject A is then sorted in ascending order with
 * the rest of the information following that order.
 * In the end, whoever recieved a score of 50 or 
 * higher in each subject passes, or recieves their diploma;
 * any less in either subject and the student fails.
 * Who has passed and who has failed is written in a file
 * called "Results.txt," as well as printed in the terminal.
 * The standard deviations and the averages for each 
 * subject are also displayed subsequently. 
 */

/* 
 * File:   main.c
 * Author: Cody Estes
 *
 * Created on September 19, 2017, 11:50 AM
 * Submitted September 30, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
 
 // Build a struct to hold an array of 
 // an array of characters
 struct Names 
 {
 	char sn[10] ; // names of students
 };
 
 struct Lines
 {
 	char r[512];
 };
 
 // Method used to return average
 float getAverage(float subject[7]) {
 	int avg, i;
 	
 	for(i = 0; i < 8; i++) {
   		avg += subject[i];
    }
   
   return avg /= 7;
 }
 
 // Method used to return standard deviation
 float getStandardDev(float sub[7], float avg) {
 	
 	int std = 0;
 	int i;
 	
 	for(i = 0; i < 7; i++) {
 		std += (sub[i] - avg)*(sub[i] - avg);
	 }
 	
 	return sqrt(std);
 }
 
 // Method used to sort Subjects in 
 // ascending order
 void SortAscending(int *id, float *sub, int count) {

	// Sorting Algorithm
   int i, j, k, tid;
   float ta;
   for (j = 0; j < count-1; j++)
   {
      for (k = 0; k < count-1; k++)
      {
         if (sub[k+1] > sub[k])
         {
         	// Sort SubA and ID
         	// use ID to sort rest of
         	// Names and SubB
            ta = sub[k];
            tid = id[k];
            
            sub[k] = sub[k+1];
            id[k] = id[k+1];
            
            sub[k+1] = ta;
            id[k+1] = tid;
            
         }
      }
   }
 	
 	
 }
 
 
int main(int argc, char** argv) {
    
    struct Names names[7];
    struct Lines lines[8];
    
    int i, j, k;
    int ID[7] = {};
    float SubA[7] = {};
    float SubB[7] = {};
    
    
   // Create file pointers
   FILE *fread, *fwptr, *fail;
   
   // open file 
   // 'FinalScores.txt' 
   fread = fopen("FinalScores.txt", "r");
   
   if(fread == NULL)
   {
      printf("Error, No 'Final Scores' File Detected");   
      exit(1);             
   }
   
   // Read, scan, and store each line from file
   fgets(lines[0].r, 512, fread);
   k = 1;
   while(!feof(fread)){
    	fgets(lines[k].r, 512, fread);
    	sscanf(lines[k].r, "%s %d %f %f", 
			&names[k-1].sn, &ID[k-1], &SubA[k-1], &SubB[k-1]);
		k++;
	}
   
   //close file and stop reading
   fclose(fread);

   
   // Calculate average 
   // all students included
   int avg_A = getAverage(SubA);
   int avg_B = getAverage(SubB);
   
   // Calculate Standard Deviation 
   // all students included
   float SubAStd = getStandardDev(SubA, avg_A);
   float SubBStd = getStandardDev(SubB, avg_B);
   
   // Resort in ascending order
   SortAscending(ID, SubA, 7);
   
   for(j = 0; j < 8; j++) {
   	float kk;
   	int t = ID[j];
   	sscanf(lines[t].r, "%s %d %f %f", &names[j].sn, &i, &kk, &SubB[j]);
   }
   
   // Begin writing to other file
   fwptr = fopen("Results.txt","w");
   
   
   // Write & Print header
   // Who Recieved their diploma
   fprintf(fwptr, "WHO PASSED:\n\n");
   fprintf(fwptr, lines[0].r);
   
   printf("WHO PASSED:\n\n");
   printf(lines[0].r);
   
   // Write and Print information
    for(j = 0; j < 7; j++) {
    	
    	if(SubA[j] >= 50 && SubB[j] >= 50){
    		// Write to file
			fprintf(fwptr, "%s\t\t%d\t\t%.2f\t\t%.2f\n", 
                &names[j].sn, ID[j], SubA[j], SubB[j]);
                
            // Print for user    
        	printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", 
                &names[j].sn, ID[j], SubA[j], SubB[j]);
        }
    }
    
    fprintf(fwptr, "----------------------------------------------------------");
    printf("----------------------------------------------------------");
    
    // Write and Print header
    // Who didn't recieve their diploma
    fprintf(fwptr, "\n\nWHO FAILED:\n\n");
    fprintf(fwptr, lines[0].r);
    
    printf("\n\nWHO FAILED:\n\n");
    printf(lines[0].r);
    
    // Write and Print information
    for(j = 0; j < 7; j++) {
    	
    	if(SubA[j] < 50 || SubB[j] < 50){
    		// Write to file
			fprintf(fwptr, "%s\t\t%d\t\t%.2f\t\t%.2f\n", 
                &names[j].sn, ID[j], SubA[j], SubB[j]);
                
            // Print for user    
        	printf("%s\t\t%d\t\t%.2f\t\t%.2f\n", 
                &names[j].sn, ID[j], SubA[j], SubB[j]);
        }
    }
    
    fprintf(fwptr, "----------------------------------------------------------");
    printf("----------------------------------------------------------");
    
    // Write and Print Standard Deviations
    // and Averages of all students
    fprintf(fwptr, "\n\n\tSTANDARD DEVIATION:\tAVERAGE: \n"
			"SUBJECT A: \t%.2f \t\t  %d\nSUBJECT B: \t%.2f \t\t  %d",
				SubAStd, avg_A, SubBStd, avg_B);
    
    printf( "\n\n\t\tSTANDARD DEVIATION:\tAVERAGE: \n"
			"SUBJECT A: \t\t%.2f  \t\t  %d\nSUBJECT B: \t\t%.2f  \t\t  %d",
				SubAStd, avg_A, SubBStd, avg_B);
   
   fclose(fwptr);

    return (EXIT_SUCCESS);
}



