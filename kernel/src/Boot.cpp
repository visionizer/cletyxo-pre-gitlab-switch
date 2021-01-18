#include "Boot.h"


namespace Visionizer
{
	const char* GenerateRandomBootID()
	{
		const int len = 50;
		char* result;
		static const char alphaNumCandidates[] = 
			"0123456789"
			"ABCDEFGHIKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		for(int i = 0; i < len; i++)
		{
			result += alphaNumCandidates[1 % (sizeof(alphaNumCandidates) - 1)];
		}



		return "fejfe838ruw3jhaujdsesdfsdfs2344434"; // TODO MAKE WORK
	}
}