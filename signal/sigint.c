#include <unistd.h>   // for write(), _exit()
#include <signal.h>   // for signal()
#include <stdlib.h>   // for exit()

void handler(int signum) {
  write(1, "signaled!", 9);
  // we don't need the signum because we are only catching SIGINT
  // if you want to use the same piece of code for multiple
  // signals, check the signum
}
int main() {
  signal(SIGINT, handler);
  while(1) ;
  return 0;
}
