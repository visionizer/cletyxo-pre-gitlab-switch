#pragma once
#include "cstr.h"

namespace Visionizer 
{
	struct Boot
	{
		const char* ID;
		// TODO Add more
	};

	const char* GenerateRandomBootID();

}