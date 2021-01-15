#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef char* bootID; // Move to other file TODO
bootID BID;

typedef struct {
	void* BaseAddress;
	size_t BufferSize;
	unsigned int Width;
	unsigned int Height;
	unsigned int PixelsPerScanline;

} Framebuffer;

typedef struct 
{
	unsigned char magic[2];
	unsigned char mode;
	unsigned char charsize;
} PSF1_HEADER;

typedef struct 
{
	PSF1_HEADER* psf1_Header;
	void* glyphBuffer;

} PSF1_FONT;

typedef struct
{
	unsigned int X;
	unsigned int Y;	
} Point;

// Prints a character to a certain position on the screen
void putChar(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char chr, unsigned int xOff, unsigned int yOff)
{
    unsigned int* pixPtr = (unsigned int*)framebuffer->BaseAddress;
    char* fontPtr = psf1_font->glyphBuffer + (chr * psf1_font->psf1_Header->charsize);
    for (unsigned long y = yOff; y < yOff + 16; y++){
        for (unsigned long x = xOff; x < xOff+8; x++){
            if ((*fontPtr & (0b10000000 >> (x - xOff))) > 0){
                    *(unsigned int*)(pixPtr + x + (y * framebuffer->PixelsPerScanline)) = colour;
                }

        }
        fontPtr++;
    }
}


Point CursorPosition;



// Takes away a few params
void Print(Framebuffer* framebuffer, PSF1_FONT* psf1_font, unsigned int colour, char* str)
{
	// After a line it should automatically add a \n and \r (!) TODO
	char* chr = str;
	while(*chr != 0)
	{
		putChar(framebuffer, psf1_font, colour, *chr, CursorPosition.X, CursorPosition.Y);
		CursorPosition.X+=8;
		// If line full, goto next line
		if(CursorPosition.X + 8 > framebuffer->Width)
		{
			CursorPosition.X = 0;
			CursorPosition.Y +=16;
		}
		chr++;
	}
}

char *generateBootID() 
{
	return (char*) "12hdhsd934ffh4895rjh8digjd84t586ejh85894";
	// TODO FIX OBIVOUSLY :)  (Make random)
}

bootID getBootID()
{
	return BID;
}


extern "C" void _startKernel(Framebuffer* framebuffer, PSF1_FONT* psf1_font) 
{
	// Set Cursor Position
	CursorPosition.X = 50;
	CursorPosition.Y = 120;

	BID = generateBootID();
	// Confirm Kernel Bootup
	Print(framebuffer, psf1_font, 0xfffffff, "[Kernel] G'day mate! My name is Merlin and I am your kernel. I will do everything important \n\r");
    return;
}

