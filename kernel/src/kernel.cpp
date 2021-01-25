#include <string>
#include <stdlib.h>
#include "BasicRenderer.h"
#include "cstr.h"
#include "Framebuffer.h"
#include "EfiMemory.h"
#include "Boot.h"
#include "Core.h"


struct KernelBootInfo
{
	Visionizer::Framebuffer* framebuffer;
	Visionizer::PSF1_FONT* psf1_Font;
	void* mMap;
	uint64_t mMapSize;
	uint64_t mDescriptorSize;
};



// The main
extern "C" void _startKernel(KernelBootInfo* bootInfo)
{
	Visionizer::BasicRenderer infoRenderer = Visionizer::BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

	infoRenderer.CursorPosition = {0, infoRenderer.CursorPosition.Y + 16}
	infoRenderer.Print("Hello World")

    return;
}
