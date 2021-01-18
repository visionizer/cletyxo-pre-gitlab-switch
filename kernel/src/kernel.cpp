#include <string>
#include <stdlib.h>
#include "BasicRenderer.h"
#include "cstr.h"
#include "Framebuffer.h"
#include "EfiMemory.h"
#include "Boot.h"
#include "Kernel.h"



// The main
extern "C" void _startKernel(KernelBootInfo* bootInfo) 
{
	Visionizer::BasicRenderer infoRenderer = Visionizer::BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);
	
	infoRenderer.Print(Visionizer::ToString((uint64_t) 12334558));

	infoRenderer.CursorPosition = {0, 16};
	infoRenderer.Print(Visionizer::ToString((int64_t) -394948));

	infoRenderer.CursorPosition = {0, infoRenderer.CursorPosition.Y + 16};
	infoRenderer.Print(Visionizer::ToHString((uint64_t) 0xF0));

	infoRenderer.CursorPosition = {0, infoRenderer.CursorPosition.Y + 16};
	infoRenderer.Print(Visionizer::ToHString((uint32_t) 0xF0));

	infoRenderer.CursorPosition = {0, infoRenderer.CursorPosition.Y + 16};
	infoRenderer.Print(Visionizer::ToHString((uint16_t) 0xF0));

	infoRenderer.CursorPosition = {0, infoRenderer.CursorPosition.Y + 16};
	infoRenderer.Print(Visionizer::ToHString((uint8_t) 0xF0));



	// Generating the boot
	boot->ID = Visionizer::GenerateRandomBootID();
	infoRenderer.Print(boot->ID);

    return;
}

