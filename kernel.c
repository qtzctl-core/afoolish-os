/*Nous allons récupérer
-> Les informations pour 
	nos buffer*/

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

//Récupération de l'affichage
#include "./bin/vga/vga.c"
#include "./bin/tty/tty.c"

void kernel_main(){
	setTerminal();
	getTerminalWriteString("Bienvenue sur le aFoolishOS, l'ami !");
	while(1){
		
	}
}
