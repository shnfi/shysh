# ShySh
ShySh (shysh) is a more advanced version of the [sshell](https://github.com/shnfi/sshell), that had many problems, like:
- No scroll
- Few commands to run becase of the lack of scroll
- Segmentation faults that occurs because of lack of experience
- etc (read the sourse if you like)

## How to use?
```bash
./scripts/compile.sh
```
Want to do this Manually? run do this:
```bash
gcc src/*.c builtins/*.c utils/*.c -o shysh
```
And then run the shell:
```bash
./shysh
```

## How it gonne be better
So, the new [sshell](https://github.com/shnfi/sshell), called shysh, is gonna be way better, without those problems.