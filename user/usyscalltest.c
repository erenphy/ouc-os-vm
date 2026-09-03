#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int pid1 = getpid();
  int pid2 = ugetpid();
  printf("===OUC=== C1: USYSCALL ===\n");
  printf("getpid()  : %d\n", pid1);
  printf("ugetpid() : %d\n", pid2);

  if(pid1 != pid2){
    printf("USYSCALL TEST FAILED\n");
    exit(1);
  }

  printf("USYSCALL TEST PASSED\n");
  exit(0);
}