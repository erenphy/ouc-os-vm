#include "kernel/types.h"
#include "user/user.h"

int global_var = 123;

int
main(void)
{
  int local_var = 456;
  uint64 heap_before;
  uint64 heap_after;

  printf("===OUC===c0: xv6 virtual memory observation ===\n");

  printf("code  address : 0x%lx\n", (uint64)main);
  printf("global address: 0x%lx\n", (uint64)&global_var);
  printf("stack address : 0x%lx\n", (uint64)&local_var);

  heap_before = (uint64)sbrk(0);
  printf("heap  before  : 0x%lx\n", heap_before);

  if(sbrk(4096) < 0){
    printf("sbrk failed\n");
    exit(1);
  }

  heap_after = (uint64)sbrk(0);
  printf("heap  after   : 0x%lx\n", heap_after);

  printf("heap growth   : %d bytes\n",
         (int)(heap_after - heap_before));

  printf("===c0 observation finished ===\n");

  /*
   * c0-2:
   * Ask the kernel to print the current process's page table.
   */

  printf("\n");
  if(vmprint() < 0){
    printf("vmprint failed\n");
    exit(1);
  }

  exit(0);
}
