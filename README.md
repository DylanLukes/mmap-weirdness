# mmap-weirdness
Reproduction for strange mmap behavior on macOS Sonoma (14.1)

## Output:

```sh
~/Projects/mmap-weirdness master ?2 ❯ uname -a
Darwin Dylans-MBP-2.attlocal.net 23.1.0 Darwin Kernel Version 23.1.0: Mon Oct  9 21:27:24 PDT 2023; root:xnu-10002.41.9~6/RELEASE_ARM64_T6000 arm64

~/Projects/mmap-weirdness master ?2 ❯ ./repro.sh
Running mmap-test without running dummy.
size: 33432
mmap (simple) failed w/ 1

Running mmap-test after running dummy.
Hello, world!
size: 33432
mmap (simple) succeeded
```
