#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd, sz;
  intptr_t rc;
  const char *exe = "./dummy";

  if ((fd = openat(AT_FDCWD, exe, O_RDONLY)) < 0) {
    fprintf(stderr, "openat failed w/ %d\n", errno);
  }
  sz = lseek(fd, 0, SEEK_END);
  printf("size: %d\n", sz);

  // Simplest case.
  rc = (intptr_t)mmap(0, sz, PROT_READ | PROT_EXEC, MAP_PRIVATE, fd, 0);
  if (rc < 0) {
    fprintf(stderr, "mmap (simple) failed w/ %d\n", errno);
    return 1;
  }

  printf("mmap (simple) succeeded\n");
  return 0;
}