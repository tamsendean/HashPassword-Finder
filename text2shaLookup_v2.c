/**
 Tamsen Dean
 Professor Cenek
 CS 334
 13 February 2022
 HW #2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <openssl/sha.h>

/*  Method to convert to SHA1 hash based on code by user 'styx^' cited from:
    https://memset.wordpress.com/2010/10/06/using-sha1-function/
*/

int main(int argc, char *argv[]) {
    FILE *fp;
    int i = 0;
    unsigned char temp[SHA_DIGEST_LENGTH];
    char hashbuf[SHA_DIGEST_LENGTH*2];
    clock_t start_t, end_t, total_t;

    
    if ( argc != 3 ) { // if there aren't 2 args provided
      printf("Usage: %s string\n", argv[0]);
      return -1;
      }

  fp = fopen(argv[1], "r"); //  open first arg as file in read mode

  if (fp == NULL) {
    fprintf(stderr,"Could not open file. \n");
    exit(1);
  }
    memset(hashbuf, 0x0, 41); // fill variables' memory blocks
    memset(temp, 0x0, SHA_DIGEST_LENGTH);
    SHA1((unsigned char *)argv[2], strlen(argv[2]), temp);
 
    for (i=0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf((char*)&(hashbuf[i*2]), "%02x", temp[i]); //  convert to sha1
    }
    
    for (i=0; hashbuf[i]; i++){
      hashbuf[i] = (toupper(hashbuf[i])); //  capitalize to match .txt file
    }
    char *buf = (char *)malloc(sizeof(char));
    start_t = clock();
    fread(buf, sizeof(char), 41, fp); //    store blocks of 41 chars in buf
    char *found = strstr(buf, hashbuf); //  see if the buf matches the hashkey
    if (found){
        printf("Password has been found. \n");
                printf("Hash is: %s\n", hashbuf);
    } else {
        printf("Password has not been found. \n");
    }
end_t = clock();
total_t = (long double)(end_t - start_t) / CLOCKS_PER_SEC;
printf("Total time: %ld\n", total_t);
free(buf); //   I have freed the data, however the program still returns free(): invalid size
fclose(fp);
exit(0);
}
