#include "types.h"
#include "user.h"

// Sets the group GID for the target specified by pathname.
int
main(int argc, char *argv[])
{
  if(argc > 2)
  {
    if(atoi(argv[1]) >= 0)
      if(chgrp(argv[2], atoi(argv[1])))
        printf(1, "chgrp %s failed \n", argv[2]);
      else
        printf(1, "Updating group id...\n");
    else
      printf(1, "Invalid argument(s) for chgrp...\n");
  }
  exit();
}
