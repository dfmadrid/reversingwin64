// ReversingWin64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma pack(1)

typedef struct _ANICHUNK{
	DWORD tag;
	DWORD size;
}ANICHUNK, *PANICHUNK;

typedef struct _ANIHEADER{
	DWORD cbSizeOf;
	DWORD cFrames;
	DWORD64 cSteps;
	DWORD cx, cy; 
	DWORD cBitCount, cPlanes;
	DWORD JifRate; 
	DWORD flags;
}ANIHEADER, *PANIHEADER;

void ReadTag(LPVOID hFile, PANICHUNK chunk){

	memcpy(&chunk->tag, hFile, sizeof(DWORD));

	if (chunk->tag != NULL)
		memcpy(&chunk->size, ((BYTE*) hFile) + sizeof(DWORD), sizeof(DWORD));

}

void ReadChunk(LPVOID hFile, PANICHUNK chunk, PANIHEADER header){

	memcpy(header, ((BYTE *) hFile) + (2 * sizeof(DWORD)), chunk->size);

}

int loadAniIcon(LPVOID hFile){

	ANIHEADER header;
	ANICHUNK chunk;

	ReadTag(hFile, &chunk);
	if (chunk.tag == 'hina')
		ReadChunk(hFile, &chunk, &header);

	return 0;

}

void loadAniIconFromFileMap(){

	HANDLE hFile = 0;
	HANDLE hFileMap = 0;
	LPVOID structMappedFile = 0;

	hFile = CreateFile(L"icon.ico", GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("Unable to find icon file"));
		return;
	}

	hFileMap = CreateFileMapping(hFile,
		NULL,
		PAGE_READONLY,
		0,
		1,
		NULL);

	structMappedFile = MapViewOfFile(hFileMap, FILE_MAP_READ, 0, 0, 0);

	loadAniIcon(structMappedFile);

	CloseHandle(hFile);
}

int _tmain(int argc, _TCHAR* argv[])
{

	loadAniIconFromFileMap();

return 0;
}

