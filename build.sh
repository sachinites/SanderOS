nasm -felf32 boot.asm -o boot.o
cc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -m32 -Wextra -mtune=i386
ld -n -T linker.ld -o myos.bin -O2 -nostdlib boot.o kernel.o -m elf_i386
if grub-file --is-x86-multiboot myos.bin; then
  	echo multiboot confirmed
	mkdir -p isodir/boot/grub
	cp myos.bin isodir/boot/myos.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir
	rm -f *.o
	qemu-system-i386 -cdrom myos.iso
else
  echo the file is not multiboot
fi
echo "# SanderOS" >> README.md
#git remote add origin https://github.com/AdeRegt/SanderOS.git
git push -u origin master
