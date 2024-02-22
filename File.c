// ./File "name of file.db" than write cat "name of file.db"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){
if (argc != 2){
    printf("Usage: %s <filename> \n", argv[0]);
    return 0;
}
int filedescriptor=open(argv[1], O_RDWR | O_CREAT, 0644);
if (filedescriptor==-1){
    perror("open");
    return -1;
}
char *mydata ="Hello there file\n";
write(filedescriptor,mydata,strlen(mydata));
close (filedescriptor);
return 0;
}
