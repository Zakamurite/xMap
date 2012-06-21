#ifndef __STRING2_H__
#define __STRING2_H__

#include <iostream>
class String : public std::string
{
public:
    String (const char * str) : std::string (str) {}
    String () : std::string () {}

    String (const std::string &str) : std::string (str.c_str()) {}

    operator const char *() {
        return c_str();
    }

    bool operator < (const String &other) const
    {
        return strcmp(c_str(), other.c_str()) < 0;        
    }

    bool operator > (const String &other) const
    {
        return strcmp(c_str(), other.c_str()) > 0;        
    }

    bool operator == (const String other) const
    {
        return strcmp(c_str(), other.c_str()) == 0;        
    }

    bool operator == (const char* other) const
    {
        return strcmp(c_str(), other) == 0;        
    }

    String ToLowerCase()
    {
        char c[0x400];

        strcpy_s(c, c_str());
        _strlwr_s(c);

        return c;
    }

    char &operator[](int index) 
    { 
        return this->at(index);
    }

    String Trim()
    {
        String tempstr = "";
    
        for (size_t i = 0; i < this->size(); ++i)
            if (this->at(i) != ' ' && this->at(i) != '\t')
                tempstr += this->at(i);

        return tempstr.ToLowerCase();
    }
};
#endif