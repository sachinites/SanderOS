#include <system.h>

void mouselib_int_wait_1(){
	while(1){
		unsigned char dx = inportb(0x64);
		if((dx & 2)==0){
			break;
		}
	}
}

void mouselib_int_wait_0(){
	while(1){
		unsigned char dx = inportb(0x64);
		if((dx & 1)==1){
			break;
		}
	}
}

void mouselib_int_write(unsigned char ah){
	mouselib_int_wait_1();
	outportb(0x64,0xD4);
	mouselib_int_wait_1();
	outportb(0x60,ah);
}

unsigned char mouselib_int_read(){
	mouselib_int_wait_0();
	return inportb(0x60);
}

void mouse_int(){
	if((inportb(0x64)|5)==0){
		printf("Mouse INT \n");
	}
}

extern void irq_mouse();
	
void mouse_init(){
	printf(">>STARTING<<");
	asm volatile("cli");
	mouselib_int_wait_1();
	outportb(0x64,0xA8);
	mouselib_int_wait_1();
	outportb(0x64,0x20);
	mouselib_int_wait_0();
	unsigned char x = inportb(0x60) | 0x02;
	mouselib_int_wait_1();
	outportb(0x64,0x60);
	mouselib_int_wait_1();
	outportb(0x60,x);
	mouselib_int_write(0xF6);
	mouselib_int_read();
	mouselib_int_write(0xF4);
	mouselib_int_read();
	setInterrupt(32+12,(unsigned long) &irq_mouse);
	asm volatile("sti");
	printf(">>READY<<");
}
