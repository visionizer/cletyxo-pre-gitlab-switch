#pragma once
#include "cstr.h"

namespace Visionizer 
{
	struct BootIdentifier
	{
		VString ID;
		// TODO Add more
	};

	class Boot
	{
	public:
		Boot();
		virtual ~Boot();
		BootIdentifier GenerateBootIdentifier(Boot boot);


		// Getters
		inline float getRuntime() { return runtime; }
		inline BootIdentifier getBootID() { return id; }


	private:
		float runtime = 0.0f; // Returns boot time in seconds
		BootIdentifier id;
	};
}