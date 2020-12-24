MBALIGN  equ  1 << 0            
MEMINFO  equ  1 << 1           
FLAGS    equ  MBALIGN | MEMINFO 
MAGIC    equ  0x1BADB002        
CHECKSUM equ -(MAGIC + FLAGS)   
 
;Cette section va nous permettre de reconnaître le boot
section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
 
section .bss
align 16
stack_bottom:
resb 16384 
stack_top:
 
section .text
global _start:function (_start.end - _start)
_start:
	mov esp, stack_top
	extern kernel_main; On charge la fonction kernel_main();
	call kernel_main	; Ensuite on la charge
 cli
.hang:	hlt
	jmp .hang
.end:
