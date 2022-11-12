#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <fstream>

#define NUMBER_OF_ELEMENTS 10

int getRandomNumber(){
    int x =rand()%100-50;
    return x;
}

int main(void)
{
    srand(time(NULL));
    int     fd[3], nbytes;
    pid_t   p1, p2;

    int bufferForFile[NUMBER_OF_ELEMENTS];
    int bufferForConsole[NUMBER_OF_ELEMENTS];
    if(pipe(fd) == -1) {
        perror("Failed to create pipe");
        exit(EXIT_FAILURE);
    }
    int buffer[NUMBER_OF_ELEMENTS];
    for(int i = 0; i< NUMBER_OF_ELEMENTS; i++){
        buffer[i]=getRandomNumber();
        write(fd[1], &buffer[i], sizeof(int));
    }


    if ((p1 = fork()) == -1)
    {
        perror("fork");
        _exit(1);
    }
    if (p1== 0)
    {
        /* Child process closes up input side of pipe */
        close(fd[1]);
        /* Send "string" through the output side of pipe */
        nbytes = read(fd[0], bufferForConsole, sizeof(int)*NUMBER_OF_ELEMENTS);
        for(int i = 0; i< NUMBER_OF_ELEMENTS; i++){
            printf("Received string: %d\n", bufferForConsole[i]);
        }
        _exit(0);
    }
    else
    {
        /* Read in a string from the pipe */
        if ((p2 = fork()) == -1)
        {
            perror("fork");
            _exit(1);
        }
        if (p2 == 0)
        {
            std::ofstream fout("res.txt");
            close(fd[2]);
            int bytes = read(fd[1], bufferForFile, sizeof(int)*NUMBER_OF_ELEMENTS);
            for(int i = 0; i< NUMBER_OF_ELEMENTS; i++){
                int x= buffer[i];
                fout<<x<<std::endl;

            //    fout<<bufferForFile[i];
            }
            _exit(0);
        }
    }
    return(0);
}
