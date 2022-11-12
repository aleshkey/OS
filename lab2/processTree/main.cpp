#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{

    pid_t p1;
    pid_t ppid[6];
    pid_t pid[7];
    pid[0]=getpid();//ид главного процесса
    p1=fork();
    if (p1==-1)
    {

        printf("Ошибка\n");exit(1);

    }

    else
        if (p1==0){


            pid[1]=getpid();
            printf("процесс PID=%d, порождает потомка %d\n",(int)pid[0],(int)pid[1]);
            pid_t p4;
            p4=fork();
           if (p4==-1){
                printf("ошибка:\n");exit(0);
           }
           else
                if (p4==0){

                    pid[4]=getpid();
                    printf("процесс PID=%d, порождает потомка %d\n",(int)pid[1],(int)pid[4]);
                    pid_t p5;
                    p5=fork();
                    if (p5==-1){
                        printf("ошибка:\n");exit(0);
                    }
                    else
                        if(p5==0){
                            pid[5] = getpid();
                            printf("процесс PID=%d, порождает потомка %d\n",(int)pid[4],(int)pid[5]);
                            printf("процесс pid = %d завершает работу\n",  (int) pid[5]);
                            exit(0);
                        }
                    printf("процесс pid = %d завершает работу\n",  (int) pid[4]);
                    exit(0);
                }
            printf("процесс pid = %d завершает работу\n",  (int) pid[1]);
            exit(0);
        }
        else//код родителя
        {

        pid_t p2;
        p2=fork();
        if (p2==-1)
        {

            printf("Ошибка\n");exit(1);

        }

        else if (p2==0)

        {

            pid[2]=getpid();
            printf("процесс PID= %d,порождает потомка %d\n",(int)pid[0],(int)pid[2]);
            pid_t p5;
            p5=fork();
            if (p5==-1)

            {

                printf("ошибка:\n");exit(0);

            }

            else if (p5==0)

            {
                pid[6]=getpid();
                printf("процесс PID=%d, порождает потомка %d\n",(int)pid[2],(int)pid[6]);
                printf("процесс pid = %d завершает работу\n",  (int) pid[6]);
                exit(0);
            }
            printf("процесс pid = %d завершает работу\n",  (int) pid[2]);
            exit(0);
        }

        else

        {

            pid_t p3;
            p3=fork();
            if (p3==-1)

            {

                printf("Ошибка\n");exit(1);

            }

            else if (p3==0)

            {

                pid[3]=getpid();
                printf("процесс PID= %d,порождает потомка %d и вызывает команду whoami\n",(int)pid[0],(int)pid[3]);
                std::string path = "/bin/whoami";
                execlp(path.c_str(), path.c_str(), NULL);
                printf("процесс pid = %d завершает работу\n",  (int) pid[3]);
                exit(0);
            }

            else sleep(8);

        }
            printf("процесс pid = %d завершает работу\n",  (int) pid[0]);
            exit(0);
    }

    return (0);

}