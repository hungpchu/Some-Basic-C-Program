#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int trace;
  int address;
  struct Node *next;
}Node;


int main(int argc, char **argv) {
   
  if (argc < 1) {
    fprintf(stderr, "Not enough arguments\n");
    exit(EXIT_FAILURE);
  } 
  
  // take input file as the first argument and outputfile as the 2nd argument
  FILE *inputFile = fopen(argv[1], "r");
  FILE *outputFile = fopen(argv[2], "w+");
  
  
  // Innitialize the head
  int access = 0, address = 0;
  fscanf(inputFile, "%d %d", &access , &address);
  Node *head = ( Node *) malloc(sizeof( Node));
  head->trace = 1;
  head->address = address;
  
   // Use current to point at the head of linked list
     Node *current;
   current = head;
  
  // using fscanf to read two integer from file and store it in the access and address integer.
  while (fscanf(inputFile, "%d %d\n", &access , &address) != EOF) {
    
    // increase the trace value of the node if there is matching address
    if ( head->address == address){
      head->trace++;
    }
    
    else {
      
      Node *temp;
      temp = ( Node *) malloc(sizeof( Node));
      
      temp->trace = 1;
      temp->address = address;
      head->next = temp;
      head = temp;
    
    }
    
  }
  
 
 // if the node is not null then write out its trace and address value to the file
  while (current != NULL) {
    
    fprintf(outputFile, "%4d %d\n", current->trace , current->address);
    current = current->next;
    
  }
  
  fclose(inputFile);
  fclose(outputFile);
}
