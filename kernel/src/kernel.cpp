#include <string>
#include <stdlib.h>
#include "BasicRenderer.h"
#include "cstr.h"

// THe main
extern "C" void _startKernel(Visionizer::Framebuffer* framebuffer, Visionizer::PSF1_FONT* psf1_font) 
{
	Visionizer::BasicRenderer infoRenderer = Visionizer::BasicRenderer(framebuffer, psf1_font);

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

    return;
}

