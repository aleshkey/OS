#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

using std::cout; using std::endl;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;


void get_current_time() {
    struct timeval t1;
    gettimeofday(&t1, NULL);
    auto ms = (t1.tv_sec*1000LL + t1.tv_usec/1000);
    std::time_t t = std::time(0);   // get time now
    std::tm *now = std::localtime(&t);
    printf( "%d - %d - %d - %d\n", (now->tm_hour), (now->tm_min), now->tm_sec, ms);
}


int main() {

    pid_t pid[2], p[3];
    pid[0]=getpid();
    p[0]=fork();
    if (p[0]==0) {
        p[1] = fork();
        pid[1]=getpid();
        if (p[1] == 0) {
            pid_t ppid = getppid();
            printf("процесс pid = %d порождает процесс pid = %d\n", (int) ppid, (int) pid[1]);
            get_current_time();
            printf("процесс pid = %d завершает работу\n",  (int) pid[1]);
            exit(0);
        }
        else {
            if (p[0]==-1){
                printf("ошибка");
            }
            else {
                p[2] = fork();
                pid[2] = getpid();
                if (p[2] == 0) {
                    pid_t ppid = getppid();
                    printf("процесс pid = %d порождает процесс pid = %d\n", (int) ppid, (int) pid[2]);
                    get_current_time();
                    printf("процесс pid = %d завершает работу\n",  (int) pid[2]);
                    exit(0);
                }
            }
        }
    }
    system("ps -x");
    printf("процесс pid = %d завершает работу\n",  (int) pid[0]);
    exit(0);
    return 0;
}
