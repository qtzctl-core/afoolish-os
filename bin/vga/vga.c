#include <stdint.h>

/* LOCATE OF 0xB8000 */
enum vgaColors{
	BLACK = 0,
	BLUE =	1,
	GREEN =	2,
	CYAN =	3,
	RED = 	4,
	MAGENTA =	5,
	BROWN =	6,
	LIGHT_GREY =	7,
	DARK_GREY =	8,
	LIGHT_BLUE =	9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN =	11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN	=	14,
	WHITE = 15
};

//Set color of terminal
static inline uint8_t vgaEntryColor(enum vgaColors fg, enum vgaColors bg){
	return fg | bg << 4;
}

static inline uint16_t vgaEntry(unsigned char uc, uint8_t color){
	return (uint16_t) uc | (uint16_t) color << 8;
}

static const size_t widthVGA= 80;
static const size_t heightVGA = 25;
