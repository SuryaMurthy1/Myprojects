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
 char ch, *shm, *s;
 key =1234;
 if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
 {
 printf ( " SHAREDMEMORY GET FAILED \n");
 return -1;
 }
 if ((shm = (char*) shmat (shmid, NULL, 0)) == (char*) - 1)
 {
 printf("sharememory attached failed \n");
 return -1;
 }
 s=shm;
 // put a-z into the memory for the other process to read..
 for ( ch ='A' ; ch <= 'z'; ch++)
 {
 *s++ = ch;
 }
 *s = '\0';
 while ( *shm != '*')
 sleep(1);
 return 0;
 }
