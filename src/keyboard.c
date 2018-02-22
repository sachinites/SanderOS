#include <system.h>

void keyboard_send_cmd(char val,char first){
	//if(first){
	//	while(!(inportb(0x64) & 0b00000010));
	//}
        outportb(0x60,val);
}

void keyboard_wait_for_ACK(){
	while(!(inportb(0x64) & 0b00000001));
        while(inportb(0x60)!=0xFA);
}

void keyboard_send_and_get_response_cmd(char val){
        keyboard_send_cmd(val,1);
        keyboard_wait_for_ACK();
}

void initialiseKeyboard(){
	keyboard_send_cmd(0xED,1);
	keyboard_send_cmd(0xFF,0);
	keyboard_wait_for_ACK();
}
