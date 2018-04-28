#include <stdio.h>

// Returns the number of times target_char appears in the file pointed to by fp
int char_count(FILE* fp, char target_char);

int main(int argc, char** argv) {
    // Make sure we have exactly 3 arguments
    if(argc != 3) {
        printf("Usage: %s <character> <filename>\n", argv[0]);
        return 1;
    }

    // argv[1] contains the character we want to search for. It is a string
    // though, so we need to get the first (and only) character in the string,
    // thus argv[1][0]
    char target_char = argv[1][0];
    char* filename = argv[2];

    FILE* fp = fopen(filename, "r");

    // fopen() returns NULL if the file could not be opened. NULL is a constant
    // that represents a pointer to nothing.
    if(fp == NULL) {
        printf("Could not open %s for reading\n", filename);
        return 1;
    }

    int count = char_count(fp, target_char);

    printf("%c appears %i times in %s\n", target_char, count, filename);

    return 0;
}

int char_count(FILE* fp, char target_char)
{
    // Implement this function here

    int count = 0;
    char hold_character ;


    while((hold_character = fgetc(fp))!=EOF)
    {
      if (hold_character == target_char)
          count++;
    }
	  fclose(fp);
    return count;
}
