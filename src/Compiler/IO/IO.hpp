#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

namespace IO
{
    namespace Clock
    {
        string Hour24();
        string Hour12();
        string Minutes();
        string Seconds();
        string Year();
        string Month();
        string Day();
        string AMPM();
        string NameMonth();

    }
    namespace String
    {

        string ReadyCode(const string &value, const size_t &start, const size_t &end);
        string RemoveSpace(const string &content);
        int LineLength(const string &value);
        string SelectLine(const string &content, const int &index);
        string RemoveSpaceFull(const string &content);
        string IntToString(const int &value);

    }
    namespace OS
    {
        int System(const string &value);
        string Arch();
        void Sleep(const int &value);
        string Type();
        void Exit();
        bool IsWindows();
    }
    namespace Display
    {
        void PrintInt(const int &value);
        void PrintChar(char value);
        void PrintString(string value);

    }
    namespace File
    {
        void Write(const string &filename, const string &content);
        bool Exists(string filename);
        string Read(const string &filename);

    }

}