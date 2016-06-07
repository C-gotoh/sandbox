#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printfile(FILE *fp, char readc){
    printf("Its contents are the following.\n");
        while((readc = fgetc(fp)) != EOF) {
            putchar(readc);
        }
        rewind(fp);
}

char * decode(char *buffer, int bsize, char *password, int psize){
    int i;
    //printf("%d, %d.\n", bsize, psize);
    for(i = 0; i < bsize-1; i++){
        if(buffer[i] - (password[(i % psize)] - 'A') < 'a')
            buffer[i] = buffer[i] - (password[(i % psize)] - 'A') + ('z'-'a');  
        else
            buffer[i] = buffer[i] - (password[(i % psize)] - 'A');
    }
    return buffer;
}

char * encode(char *buffer, int bsize, char *password, int psize){
    int i;
    //printf("%d, %d.\n", bsize, psize);
    for(i = 0; i < bsize-1; i++){
        if(buffer[i] + (password[(i % psize)] - 'A') > 'z')
            buffer[i] = buffer[i] + (password[(i % psize)] - 'A') - ('z'-'a');
        else
            buffer[i] = buffer[i] + (password[(i % psize)] - 'A');
    }
    return buffer;
}

int main(int argc, char *argv[])
{
    char input;
    char filename[80];
    //char readc = '\0';
    char *buffer;
    int buffersize = 0;

    long filesize = 0;
    char password[80];
    int passwordsize = 0;

    FILE *fp;

    printf("Please input 'd' for decode, 'e' for encode, or 'q' to quit.\n");
    scanf("%c", &input);
    printf("Your input was '%c'.\n", input);

    if(input == 'q')
        return 0;

    if(input == 'e')
        printf("Select a file to encode.\n");
    if(input == 'd')  
        printf("Select a file to decode.\n");

    scanf("%s", filename);
    printf("You selected file '%s'.\n", filename);
    fp = fopen(filename, "r");
    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);
    
    buffer = calloc(1, filesize+1);
    buffersize = filesize;
    fread(buffer, filesize, 1, fp);
    rewind(fp);
    fclose(fp); 

    printf("Its contents are: \n%s", buffer);
    //printfile(fp, readc);

    printf("Please input the password.\n");
    scanf("%s", password);
    printf("You chose '%s' as the password.\n", password);
    passwordsize = strlen(password); // todo replace with correct size of password ; currently 80.
    printf("It is of size %d. \n", passwordsize);

    if(input == 'e'){
        encode(buffer, buffersize, password, passwordsize);
        printf("The encoded file is the following:\n%s\n", buffer);
        printf("Saving as file ...\n"); // todo save buffer as file
        fp = fopen(filename, "w+");
        fwrite(buffer,buffersize,1,fp);
        fclose(fp);
    }
    if(input == 'd'){
        decode(buffer, buffersize, password, passwordsize);
        printf("The decoded file is the following:\n%s\n", buffer);
    }

    free(buffer);
    return 0;
}
