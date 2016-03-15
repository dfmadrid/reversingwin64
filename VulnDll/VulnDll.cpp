// VulnDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VulnDll.h"


VULNDLL_API LPVOID* ReverseArray(LPVOID *pData, size_t cData)
{
	LPVOID pReversed[5];

	size_t k = cData - 1;
	for (size_t j = 0; j < cData; j++) {
		pReversed[j] = pData[k];
		k--;
	}

	for (size_t i = 0; i < cData; i++)
		pData[i] = pReversed[i];

	return pData;
}
