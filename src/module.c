#include <system.h>


void insmod(const char* path){
	printf("--INSMOD--\n");
	printf("  -> loading file\n");
	unsigned char* msx = readCDROM(path);
	printf("  -> parsing file\n");
	unsigned long location = elf_load_file(msx);
	printf("  -> calling file at %x \n",location);
	void (*foo)(void) = location;
	foo();
	printf("\n  -> insmod returned succesfully!\n");
}
