ENTRY(_start)


SECTIONS{
	. = 1M;
	.text BLOCK(4K) : ALIGN(4K){ /*Ici on appelle à notre boot et ensuite l'affichage*/
		*(.multiboot)
		*(.text)
	}
	.rodata BLOCK(4K) : ALIGN(4K){
		*(.rodata)
	}
	.data BLOCK(4K) : ALIGN(4K){
		*(.data)
	}
	.bss BLOCK(4K) : ALIGN(4K){
		*(COMMON)
		*(.bss)
	} 
}
