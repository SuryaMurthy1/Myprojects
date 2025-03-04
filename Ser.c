#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#define SHMSIZE 128
 int main()
 {
 int shmid;
 key_t key;
 char *shm, *s;
 key =1234;
// shared memory creation
 if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
 {
 printf ( " SHAREDMEMORY GET FAILED \n");
 return -1;
 }
// shared memory attachment
 if ((shm = (char*) shmat (shmid, NULL, 0)) == (char*) - 1)
 {
 printf("share memory attached failed \n");
 return -1;
 }
// s=shm;
 for ( s = shm; *s != '\0'; s++)
 {
 putchar (*s);
 }
 putchar('\n');
// while ( *shm != '*')
// sleep(1);
 *shm = '*';
 return 0;
 }
