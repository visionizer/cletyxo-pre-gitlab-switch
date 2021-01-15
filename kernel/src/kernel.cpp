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

	infoRenderer.CursorPosition = {0, 32};
	double foo = 13.1454;
	infoRenderer.Print(Visionizer::ToString(foo));

    return;
}

