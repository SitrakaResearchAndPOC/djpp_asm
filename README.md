# djpp_asm compiled on linux  : 
## Installing dependancies
```
apt update
```
* For ubuntu 22.04
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
* For ubuntu 24.04
```
sudo dpkg --add-architecture i386
```
```
apt install nasm binutils gcc libc6-dev-i386 gcc-multilib git unzip
```
* Installation
```
git clone https://github.com/SitrakaResearchAndPOC/djpp_asm
```
```
cd djpp_asm
```
```
unzip linux-ex.zip
```
```
ls
```

## Integration of C and ASM
```
nasm -f elf32 -d ELF_TYPE -o asm_io.o asm_io.asm
```
```
nasm -f elf32 -d ELF_TYPE -o first.o first.asm
```
```
gcc -m32 -o first driver.c first.o asm_io.o
```
```
./first
```

## Using linker only by ld command
```
nasm -f elf32 -d ELF_TYPE -o asm_io.o asm_io.asm
```
```
nasm -f elf32 -d ELF_TYPE -o first.o first.asm
```
```
ld -m elf_i386 -o first.elf first.o asm_io.o -lc -dynamic-linker /lib/ld-linux.so.2
```
```
./first.elf
```
