#pragma once




struct KernelBootInfo 
{
	Visionizer::Framebuffer* framebuffer;
	Visionizer::PSF1_FONT* psf1_Font;
	void* mMap;
	uint64_t mMapSize;
	uint64_t mDescriptorSize;
};


// The boot
Visionizer::Boot* boot;

// Getter
Visionizer::Boot* getBoot() { return boot; }

extern "C" void _startKernel(KernelBootInfo* bootInfo);