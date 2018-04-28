#include <stdio.h>
#include<string.h>

// Returns the number of times target_char appears in the file pointed to by fp
int string_count(FILE* fp, char* target_string)
{

    int i, j;
    int length = strlen(target_string);

    int count = 0;

    // BEGIN
    char fileStr[ 1024 ];

    char c;
    int index = 0;

    // Read the whole file into fileStr
    while ( ( c = fgetc( fp ) ) != EOF ) {
        fileStr[ index++ ] = c;
        // ++index == index + 1
        // index++ == index
        //    index = index + 1
    }
    fileStr[ index ] = '\0';

    if ( length == 0 ) return 0;

    // If target_string == 'haha' AND fileStr == 'hahaha'
    // Sau khi match xong 'haha' tai fileStr[ 0 ], minh phai increment fileStr index
    // len 1 doan bang length cua target_string (o day la bien 'length' em calculate o
    // phia tren).
    //
    // 'hahaha'
    //  ^
    //  i
    //
    // Neu nhu minh increment i += length, Sau khi matched:
    // 'hahaha'
    //      ^
    //      i
    //
    // Neu nhu minh ko increment i:
    // 'hahaha'
    //   ^
    //   i

    for ( i = 0; i < index; ++i ) {
        // Match character thu nhat cua target_string va current character cua fileStr
        if ( fileStr[ i ] == target_string[ 0 ] )
        {
            int isMatched = 1;

            // Neu length cua target_string == 1 ( length == 1 ):
            if ( length != 1 ) {
                // Match character thu hai tro di cua target_string va character sau current character cua fileStr
                for ( j = 1; j < length; j++)
                {
                    if ( fileStr[ i + j ] != target_string[ j ] ) {
                        isMatched = 0;
                        break;
                    }
                }

                if ( isMatched )
                {
                    // Neu vong for chay het den cung cua target_string
                    // thi target_string existed in fileStr
                    ++count;
                    // increment i forward to avoid case of:
                    // 'haha' occurs twice in 'hahaha'
                    i += length - 1;
                }

            } else {
                ++count;
            }
       }
    }

    fclose(fp);
    return count;
}

int main(int argc, char** argv) {
    // Make sure we have exactly 3 arguments
    if(argc != 3) {
        printf("Usage: %s <character> <filename>\n", argv[0]);
        return 1;
    }

    // argv[1] contains the character we want to search for. It is a string
    // though, so we need to get the first (and only) character in the string,
    // thus argv[1][0]
    char* target_string = argv[1];
    char* filename = argv[2];

    FILE* fp = fopen(filename, "r");

    // fopen() returns NULL if the file could not be opened. NULL is a constant
    // that represents a pointer to nothing.
    if(fp == NULL) {
        printf("Could not open %s for reading\n", filename);
        return 1;
    }

    int count = string_count(fp, target_string);

    printf("%s appears %i times in %s\n", target_string, count, filename);

    return 0;
}

/*int string_count(FILE* fp, char* target_string)
{

    char fileStr[ 1024 ];

    char c;
    int count = 0;

    while ( ( c = fgetc( fp ) ) != EOF )
    {
        fileStr[ count++ ] = c;
        // ++index == index + 1
        // index++ == index
        //    index = index + 1
    }
    fileStr[ count ] = '\0';


    fclose(fp);
    return count;
}*/
