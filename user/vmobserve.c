#include "kernel/types.h"
#include "user/user.h"

int global_var = 123;

int
main(void)
{
  int local_var = 456;

  printf("\n===OUC===c1: address analysis ===\n");
  printf("TODO: <vmobserve.c> fix address analysis\n");
  // TODO: c1-1: address analysis:VA\VPN[2]\VPN[1]\VPN[0]\offset
  printf("stack address : 0x%lx\n", (uint64)&local_var);

  printf("\n===OUC===c1: address analysis Done ===\n");

  // calling vmprint() to print the current process's page table
  printf("\n===OUC===c1: vmprint() ===\n");
  if(vmprint() < 0){
    printf("vmprint failed\n");
    exit(1);
  }
  printf("\n===OUC===c1: vmprint() Done ===\n");



  exit(0);
}
