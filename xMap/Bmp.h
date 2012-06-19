#ifndef _BMP_H
#define _BMP_H

#define BLOB_ITEM UNIT_ITEM
#define BLOB_MONSTER UNIT_MONSTER
#define BLOB_MISSILE UNIT_MISSILE
#define BLOB_OBJECT UNIT_OBJECT
#define BLOB_PLAYER UNIT_PLAYER

DWORD __fastcall D2CLIENT_LoadUIImage_ASM(char* Path) ;
void InitBlobs();
void DeleteBlobs();

CellFile *LoadBmpCellFile(char *filename);
CellFile *LoadBmpCellFile(BYTE *buf1, int width, int height);
CellFile *myInitCellFile(CellFile *cf);
void DeleteCellFile(CellFile *cf);
VOID *memcpy2(void *dest, const void *src, size_t count);
HANDLE OpenFileRead(char *filename);
HANDLE OpenFileWrite(char *filename);
BYTE *AllocReadFile(char *filename);
DWORD ReadFile(HANDLE hFile, void *buf, DWORD len);
CellFile* LoadCellFile(CHAR* lpszPath, DWORD bMPQ);
VOID myDrawAutomapCell(CellFile *cellfile, int xpos, int ypos, BYTE col, BOOL worldcoords);

#endif