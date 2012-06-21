#include <iostream>
#include "String2.h"
using namespace std;
class FileReader
{
    enum State
    {
        INITIAL,
        OPENED,
        CLOSED
    } state;
    FILE* fp;

public:
    FileReader(const char * filename = NULL)
    {
        fp = NULL;
        state = INITIAL;
        if (filename != NULL)
            Open(filename);
    }

    ~FileReader()
    {
        if (state == OPENED)
            Close();
    }

    void Open(const char * filename)
    {
        if (state != INITIAL)
            throw exception("Wrong file state");
        fopen_s (&fp, filename, "rt");
        if (!fp)
            throw exception("Error opening file");
        state = OPENED;
    }

    String ReadLine()
    {
        if (state != OPENED)
            throw exception("Wrong file state");

        const int SIZE = 10;
        char temp[SIZE] = "";
        string ret;
        bool lineEnded = false;
        while(!lineEnded)
        {
            fgets(temp, SIZE, fp);
            if (strlen(temp) < SIZE-1 || temp[SIZE-2] == '\n' || temp[SIZE-2] == '\r') 
            {
                lineEnded = true;
                for (int i = 0; i < SIZE; ++i)
                {
                    if (temp[i] == '\n' || temp[i] == '\r')
                    {
                        temp[i] = '\0';
                        break;
                    }
                }
            }
            ret += temp;
        }
        return ret;
    }

    int Eof()
    {
        if (state != OPENED)
            throw exception("Wrong file state");
        return feof(fp);
    }

    void Close()
    {
        if (state != OPENED)
            throw exception("Wrong file state");
        fclose (fp);
        fp = NULL;
        state = CLOSED;
    }
};