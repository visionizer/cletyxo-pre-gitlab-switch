#include <string>
#include <stdlib.h>
#include "BasicRenderer.h"
#include "cstr.h"
#include "Framebuffer.h"
#include "EfiMemory.h"
#include "Memory.h"


struct KernelBootInfo
{
	Visionizer::Framebuffer* framebuffer;
	Visionizer::PSF1_FONT* psf1_Font;
	Visionizer::EFI_MEMORY_DESCRIPTOR* mMap;
	uint64_t mMapSize;
	uint64_t mMapDescSize;
};

// Uses the renderer to generate a newline
void NewLine(Visionizer::BasicRenderer* ren)
{
	ren->CursorPosition = {0, ren->CursorPosition.Y + 16};
	return;
}

// The main
extern "C" void _startKernel(KernelBootInfo* bootInfo)
{
	Visionizer::BasicRenderer infoRenderer = Visionizer::BasicRenderer(bootInfo->framebuffer, bootInfo->psf1_Font);

	NewLine(&infoRenderer);

	uint64_t mMapEntries = bootInfo->mMapSize / bootInfo->mMapDescSize;

	infoRenderer.Print(Visionizer::ToString(Visionizer::GetMemorySize(bootInfo->mMap, mMapEntries, bootInfo->mMapDescSize)));

//	for (int i = 0; i < mMapEntries; i++)
//	{
//		Visionizer::EFI_MEMORY_DESCRIPTOR* desc = (Visionizer::EFI_MEMORY_DESCRIPTOR*)((uint64_t)bootInfo->mMap + (i * bootInfo->mMapDescSize));
//		NewLine(&infoRenderer);
//		infoRenderer.Print(Visionizer::EFI_MEMORY_TYPE_STRINGS[desc->type]);
//		infoRenderer.Colour = 0xffff00ff;
//		infoRenderer.Print(" ");
//		infoRenderer.Print(Visionizer::ToString(desc->numPages * 4096 /* Gives us bits */ / 1024 /* Into kilobytes*/));
//		infoRenderer.Print(" KB");
//		infoRenderer.Colour = 0xffffffff;
//
//	}


    return;
}
