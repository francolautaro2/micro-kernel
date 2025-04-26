all: kernel.bin

kernel.bin: boot/boot.asm kernel/*c linker.ld
	nasm -f bin boot/boot.asm -o boot.o
	gcc -ffreestanding -m32 -c kernel/main.c -o main.o
	ld -T linker.ld -o kernel.bin boot.o main.o

clean:
	rm -f *.o kernel.bin