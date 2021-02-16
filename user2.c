#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    mkfifo(myfifo, 0666); 
  
    char MYMESSAGE[100];
    char MESSAGEFROM[100]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, MESSAGEFROM, 100); 
  
        // Print the read string and close 
        printf("MESSAGE FROM 1st USER is: %s\n", MESSAGEFROM); 
        close(fd1); 
  
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo,O_WRONLY); 
        printf("Enter your message: ");
        fgets(MYMESSAGE, 100, stdin); 
        write(fd1, MYMESSAGE, strlen(MYMESSAGE)+1); 
        close(fd1); 
    } 
    return 0; 
} 
