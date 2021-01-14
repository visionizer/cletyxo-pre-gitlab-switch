#include <efi.h>
#include <efilib.h>
#include <elf.h>


EFI_FILE* LoadFile(EFI_FILE* Directory, CHAR16* Path, EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) 
{
	EFI_FILE* LoadedFile;
	EFI_LOADED_IMAGE_PROTOCOL* LoadedImage;
	SystemTable->BootServices->HandleProtocol(ImageHandle, &gEfiLoadedImageProtocolGuid, (void**)&LoadedImage);

	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* FileSystem;
	SystemTable->BootServices->HandleProtocol(LoadedImage->DeviceHandle, &gEfiSimpleFileSystemProtocolGuid, (void**)&FileSystem);

	if (Directory == NULL)
	{
		FileSystem->OpenVolume(FileSystem, &Directory);
	}

	EFI_STATUS s = Directory->Open(Directory, &LoadedFile, Path, EFI_FILE_MODE_READ, EFI_FILE_READ_ONLY);
	if (s != EFI_SUCCESS)
	{
		return NULL;
	} 
	return LoadedFile;

}


int memcmp(const void* aptr, const void* bptr, size_T n)
{
	const unsigned char* a = aptr, b = bptr;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}
	return 0;
}



EFI_STATUS efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	InitializeLib(ImageHandle, SystemTable);

	Print(L"Visionizer Cletyxo [ Version 0.1 Pre-Alpha ] \n\r"); // Get version automatically
	Print(L"(c) 2021 Visionizer Corporation. All rights reserverd \n\r");

	EFI_FILE* Kernel = LoadFile(NULL, L"kernel.elf", ImageHandle, SystemTable);
	if(Kernel == NULL) 
	{
		Print(L"[Bootloader] Fatal: Could not load kernel.elf. Please restart your computer.\n\r"); // Better msg TODO
	} // Maybe add checkmarks TODO
	else {
		Print(L"[Bootloader] Success: Kernel loaded succesfully \n\r");
	}

	Elf64_Ehdr header;
	{
		UINTN FileInfoSize;
		EFI_FILE_INFO* FIleInfo;
		Kernel->GetInfo(Kernel, &gEfiFileInfoGuid, &FileInfoSize, NULL);
		SystemTable->BootServices->AllocatePool(EfiLoaderData, FileInfoSize, (void**)&FileInfo);
		Kernel->GetInfo(Kernel, &gEfiFileInfoGuid, &FileInfoSize, (void**)&FileInfo);

		UINTN size = sizeof(header);
		Kernel->Read(Kernel, &size, &header);

	} if(
		)



	return EFI_SUCCESS; // Exit the UEFI application
}
