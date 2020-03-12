#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

  struct procs *proc = malloc(sizeof(struct procs)*16);

  int num_procs = getprocs(proc);

  printf(1,"PID \t Name \t UID \t GID \t PPID \t Elapsed \t CPU \t State \t Size\n");
  int i;
  for(i = 0; i<num_procs;i++){
    uint elapsed_time_ms = proc[i].elapsed_ticks;
    uint elapsed_time_s = elapsed_time_ms/1000;
    elapsed_time_ms = elapsed_time_ms % 1000;
    char* zeros = "";
    if(elapsed_time_ms < 100 && elapsed_time_ms >= 10){
      zeros = "0";
    }
    if(elapsed_time_ms < 10){
      zeros = "00";
    }
    uint cpu_time_ms = proc[i].CPU_total_ticks;
    uint cpu_time_s = cpu_time_ms/1000;
    cpu_time_ms = cpu_time_ms % 1000;
    char* cpu_zeros = "";
    if(cpu_time_ms < 100 && cpu_time_ms >= 10){
      cpu_zeros = "0";
    }
    if(cpu_time_ms < 10){
      cpu_zeros = "00";
    }

    printf(1,"%d \t %s \t %d \t %d \t %d \t %d.%s%d \t %d.%s%d \t %s \t %d\n", proc[i].pid,proc[i].name,proc[i].uid,proc[i].gid,
            proc[i].ppid,elapsed_time_s,zeros,elapsed_time_ms,
            cpu_time_s,cpu_zeros,cpu_time_ms,proc[i].state, proc[i].size);
     
}
  exit();
}