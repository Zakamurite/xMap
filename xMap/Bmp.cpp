#include "xMap.h"

void InitBlobs()
{
    char filename[0x400];
    for (int i = 0; i < ArraySize(cUnitBlobFiles); i++)
    {
        if (cUnitBlobFiles[i].length() == 0)
            continue;
        
        sprintf_s(filename, sizeof(filename), "%s%s.BMP", szPath, cUnitBlobFiles[i].c_str());
                
        cUnitBlobCells[i] = LoadCellFile(filename, FALSE);        
    }

    sprintf_s(filename, sizeof(filename), "%s%s.bmp", szPath, cWaypointBlobFile.c_str());
    cWaypointCell = LoadCellFile(filename, FALSE);

    sprintf_s(filename, sizeof(filename), "%s%s.bmp", szPath, cRadiusBlobFile.c_str());
    cRadiusCell = LoadCellFile(filename, FALSE);

    /*if (GameReady())
        Print("%s", filename);*/

    for (int i = 0; i < ArraySize(cShrineBlobCells); ++i)
    {
        sprintf_s(filename, sizeof(filename), "%sshrine%d.bmp", szPath, i);

        cShrineBlobCells[i] = LoadCellFile(filename, FALSE);        
    }
}

void DeleteBlobs()
{
    for (int i = 0; i < ArraySize(cUnitBlobCells); ++i)
        DeleteCellFile(cUnitBlobCells[i]);

    for (int i = 0; i < ArraySize(cShrineBlobCells); ++i)
        DeleteCellFile(cShrineBlobCells[i]);

    DeleteCellFile(cWaypointCell);
    DeleteCellFile(cRadiusCell);
}

CellFile* LoadBmpCellFile(char *filename)
{
    BYTE* ret = 0;

    BYTE* buf1 = AllocReadFile(filename);
    BITMAPFILEHEADER* bmphead1 = (BITMAPFILEHEADER*)buf1;
    BITMAPINFOHEADER* bmphead2 = (BITMAPINFOHEADER*)(buf1 + sizeof(BITMAPFILEHEADER));
    if (buf1 && (bmphead1->bfType == 'MB') && (bmphead2->biBitCount == 8) && (bmphead2->biCompression == BI_RGB))
        ret = (BYTE*)LoadBmpCellFile(buf1+bmphead1->bfOffBits, bmphead2->biWidth, bmphead2->biHeight);

    delete buf1;

    return (CellFile*)ret;
}

CellFile* LoadBmpCellFile(BYTE *buf1, int width, int height)
{
    BYTE* buf2 = new BYTE[(width*height*2)+height], *dest = buf2;

    for (int i = 0; i < height; ++i)
    {
        BYTE *src = buf1 + (i * ((width + 3)&-4)), *limit = src + width;
        while (src < limit)
        {
            BYTE *start = src, *limit2 = min(limit, src+0x7f), trans = !*src;
            do
                src++;
            while ((trans == (BYTE)!*src) && (src < limit2));

            if (!trans || (src < limit))
                *dest++ = (trans?0x80:0)+(src-start);
            if (!trans)
                while (start < src)
                    *dest++ = *start++;
        }
        *dest++ = 0x80;
    }

    static DWORD dc6head[] = { 6, 1, 0, 0xeeeeeeee, 1, 1, 0x1c,  0, -1, -1, 0, 0, 0, -1, -1 };
    dc6head[8] = width;
    dc6head[9] = height;
    BYTE* ret = new BYTE[dc6head[13] = sizeof(dc6head) + (dc6head[14] = dest - buf2) + 3];
    memset(memcpy2(memcpy2(ret, dc6head, sizeof(dc6head)), buf2, dc6head[14]), 0xee, 3);
    delete[] buf2;
    
    return (CellFile *)ret;
}

CellFile *myInitCellFile(CellFile *cf)
{
    if (cf)
        D2CMP_InitCellFile(cf, &cf, "?", 0, -1, "?");

    return cf;
}


void DeleteCellFile(CellFile *cf)
{
    if (cf)
    {
        D2CMP_DeleteCellFile(cf);
        delete cf;
    }
}

VOID* memcpy2(void *dest, const void *src, size_t count)
{
    return (char *)memcpy(dest, src, count)+count;
}

HANDLE OpenFileRead(char *filename)
{
    return CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

HANDLE OpenFileWrite(char *filename)
{
    return CreateFile(filename, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
}

BYTE *AllocReadFile(char *filename)
{
    HANDLE hFile = OpenFileRead(filename);
    int filesize = GetFileSize(hFile, 0);
    if (filesize <= 0)
        return 0;
    BYTE *buf = new BYTE[filesize];
    ReadFile(hFile, buf, filesize);
    CloseHandle(hFile);
    return buf;
}

DWORD ReadFile(HANDLE hFile, void *buf, DWORD len)
//NOTE :- validates len bytes of buf
{
    DWORD numdone = 0;
    ReadFile(hFile, buf, len, &numdone, NULL);
    return numdone;
}

DWORD __declspec(naked) __fastcall D2CLIENT_LoadUIImage_ASM(char* Path) 
{
    __asm
    {
        mov eax, ecx
        push 0
        call D2CLIENT_LoadUIImage_I
        retn
    }
}

CellFile* LoadCellFile(CHAR* lpszPath, DWORD bMPQ)
{
    if(bMPQ == TRUE)
        return (CellFile*)D2CLIENT_LoadUIImage_ASM(lpszPath);
    else if(bMPQ == FALSE)
        return myInitCellFile((CellFile*)LoadBmpCellFile(lpszPath));

    return NULL;
}

VOID myDrawAutomapCell(CellFile *cellfile, int xpos, int ypos, BYTE col, BOOL worldcoords)
{
    POINT nPos = { xpos, ypos };
    if (worldcoords)
    {
        if (!p_D2CLIENT_AutomapOn)
            return;
        ScreenToAutomap(&nPos, xpos * 32, ypos * 32);
    }

    CellContext ct;
    memset(&ct, 0, sizeof(ct));
    if (!(ct.pCellFile = cellfile))
        return;

    nPos.x -= (cellfile->cells[0]->width / 2);
    nPos.y += (cellfile->cells[0]->height / 2);

    int xpos2 = nPos.x - cellfile->cells[0]->xoffs, 
        ypos2 = nPos.y - cellfile->cells[0]->yoffs;
    if (xpos2 >= D2GetScreenSizeX() || xpos2 + (int)cellfile->cells[0]->width <= 0 || ypos2 >= D2GetScreenSizeY() || ypos2 + (int)cellfile->cells[0]->height <= 0) 
        return;

    static BYTE coltab[2][256];//, tabno = 0, lastcol = 0;
    if (!coltab[0][1])
        for (int k = 0; k < 255; k++)
            coltab[0][k] = coltab[1][k] = k;

    cellfile->mylastcol = coltab[cellfile->mytabno ^= (col != cellfile->mylastcol)][255] = col;

    D2GFX_DrawAutomapCell2(&ct, nPos.x, nPos.y, -1, 5, coltab[cellfile->mytabno]);
}