	BITS 16

bootloader_start:
	mov ax, 07C0h
	add ax, 544
	cli
	mov ss, ax
	mov sp, 4096
	sti

	mov ax, 07C0h
	mov ds, ax

	mov [bootdev], dl
	mov si,hello
	call print_string
	
	;
	; Dataladen klaarmaken
	;
	
	mov ax,0
	mov dl,byte [bootdev]
	int 0x13
	jc fail
	
	;
	; Data lazen
	;
	
	mov ax, buffer
	mov es, ax
	mov bx, 0
	mov ah,0x02
	mov al,60
	mov cx,1
	mov dx, [bootdev]
	int 0x13
	jc fail
	
	mov si,seemsok
	call print_string
	
	mov si,buffer
	mov al,byte [si]
	cmp al,0x7f
	jne och
	cli
	hlt
	
fail:
mov si,failmes
call print_string
cli
hlt

och:
mov si,failmes2
call print_string
cli
hlt

seemsok db "TOT ZOVER ALLES GOED",0x00
failmes db "<<FATAL>>",0x00	
failmes2 db "<<SUM>>",0x00	
hello db "Hello world!",0x00
bootdev db 0x00
	
print_string:				; Output string in SI to screen
	pusha

	mov ah, 0Eh

.repeat:
	lodsb	
	cmp al, 0
	je .done
	int 10h	
	jmp short .repeat

.done:
	popa
	ret
times 510-($-$$) db 0	; Pad remainder of boot sector with zeros
dw 0AA55h		; Boot signature (DO NOT CHANGE!)
buffer:

