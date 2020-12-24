size_t terminalRow;
size_t terminalColumn;
uint8_t terminalColor;
uint16_t* terminalBuffer;
 

size_t strlen(const char* str){
	size_t len=0;
	while(str[len]) len++;
	return len;
}

//Notre système de buffer
void setTerminal(void){
	terminalRow = 0;
	terminalColumn = 0;
	terminalColor = vgaEntryColor(LIGHT_RED, BLACK);
	terminalBuffer = (uint16_t*) 0xB8000;
	for(size_t x =0; x < widthVGA; x++){
		for(size_t y=0; y < heightVGA; y++){
			const size_t index = y * widthVGA + x;
			terminalBuffer[index] = vgaEntry(' ', terminalColor);
		}
	}
}

void setTerminalColor(uint8_t color){
	terminalColor = color;
}

void setTerminalPutEntryAt(char c, uint8_t color, size_t x, size_t y){
	const size_t index = y * widthVGA + x;
	terminalBuffer[index] = vgaEntry(c, color);
}

//On écrit une par une les lettres à l'aide d'une boucle for!
void setTerminalPutChar(char c){
	setTerminalPutEntryAt(c, terminalColor, terminalColumn, terminalRow);
	if(++terminalColumn == widthVGA){
		terminalColumn = 0;
		if(++terminalRow == heightVGA){
			terminalRow = 0;	
		}
	}
}

void getTerminalWrite(const char* data, size_t size){
	for(size_t i = 0; i < size; i ++) setTerminalPutChar(data[i]);
}

void getTerminalWriteString(const char* data){
	getTerminalWrite(data, strlen(data));
}
