#include "types.h"
#include "user.h"

// Sets the mode, or permission, bits for the target specified by pathname.
int
main(int argc, char *argv[])
{
  if(argc > 2)
  {
    if((atoo(argv[1]) > 0 && atoo(argv[1]) < 1778) || atoi(argv[1]) == 0)
      if(chmod(argv[2], atoo(argv[1])))
        printf(1, "chmod %s failed\n", argv[2]);
      else
        printf(1, "Updating permissions...\n");
    else
        printf(1, "Invalid argument(s) for chmod...\n");
  }
  exit();
}