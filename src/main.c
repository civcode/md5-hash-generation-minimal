#include <stdio.h>
#include <openssl/md5.h>

int main(int argc, char *argv[])
{

    if (argc !=2) {
        //printf("Filename is missing.\n");
        printf("Wrong number of arguments.\n");
        printf("Example:\n$ md5-hash main.c\n");
        return 0;
    }

    unsigned char c[MD5_DIGEST_LENGTH];
    //char *filename="file.c";
    char *filename = argv[1];
    int i;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL) {
        printf("%s can't be opened.\n", filename);
        return 0;
    }
 
    MD5_Init(&mdContext);
    while ((bytes = fread(data, 1, 1024, inFile)) != 0) {
        MD5_Update(&mdContext, data, bytes);
    }

    MD5_Final(c, &mdContext);
    
    for (i=0; i<MD5_DIGEST_LENGTH; i++) {
        printf("%02x", c[i]);
    }
    
    printf(" %s\n", filename);
    fclose(inFile);
    
    return 0;
}
