#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include "IO.hpp"
using namespace std;
namespace IO
{
    namespace Clock
    {
        string Year()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%Y", &datetime);
            return output;
        }

        string Month()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%m", &datetime);
            return output;
        }

        string NameMonth()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%B", &datetime);
            return output;
        }
        string Day()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%d", &datetime);
            return output;
        }
        string Hour24()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%H", &datetime);
            return output;
        }
        string Hour12()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%I", &datetime);
            return output;
        }
        string AMPM()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%p", &datetime);
            return output;
        }
        string Minutes()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%M", &datetime);
            return output;
        }
        string Seconds()
        {
            time_t timestamp = time(NULL);
            struct tm datetime = *localtime(&timestamp);
            char output[50];
            strftime(output, 50, "%S", &datetime);
            return output;
        }

    }
    namespace String
    {

        string ReadyCode(const string &value, const size_t &start, const size_t &end)
        {
            bool str = false;
            string buffer = "", code = IO::String::RemoveSpace(value);
            for (size_t i = start; i < end; i++)
            {
                buffer += value[i];
            }
            code.clear();
            buffer = IO::String::RemoveSpace(buffer);

            for (size_t i = 0; i < buffer.length(); i++)
            {
                if (buffer[i] == '"' && !str)
                {
                    code += buffer[i];
                    str = true;
                    continue;
                }
                if (str)
                {
                    code += buffer[i];
                    if (buffer[i] == '"')
                        str = false;
                    continue;
                }
                if (buffer[i] != ' ' && buffer[i] != '\t')
                {
                    code += buffer[i];
                    continue;
                }
            }
            return code;
        }
        string IntToString(const int &value)
        {
            char buffer[500];
            sprintf(buffer, "%d", value);
            return buffer;
        }
        string RemoveSpaceFull(const string &content)
        {
            string buffer = "";
            for (size_t i = 0; i < content.length(); i++)
            {
                if (content[i] != ' ')
                {
                    buffer += content[i];
                }
            }
            return buffer;
        }
      
        string RemoveSpace(const string &content)
        {

            size_t start = 0, end = content.length();
            while (start < content.length() && (content[start] == ' ' || content[start] == '\t'))
                start++;
            while (end > start && (content[end - 1] == ' ' || content[end - 1] == '\t'))
                end--;

            return content.substr(start, end - start);
        }
        int LineLength(const string &value)
        {
            int line = 1;
            for (size_t i = 1; i < value.length(); i++)
            {
                if (value[i - 1] == '\n')
                    line++;
            }
            return line;
        }
        string SelectLine(const string &content, const int &index)
        {
            string buffer = "";

            int line = 1;

            for (size_t i = 0; i < content.length(); i++)
            {

                if (index == line)
                {
                    if (content[i] == '\n')
                        break;

                    buffer += content[i];
                }

                if (content[i] == '\n')
                    line++;
            }
            return buffer;
        }

    }
    namespace OS
    {
        int System(const string &value)
        {
            return system(value.c_str());
        }
        void Sleep(const int &value)
        {

            clock_t end = clock() + ((value * 1000) * CLOCKS_PER_SEC / 1000);
            while (clock() < end)
            {
            }
        }
        void Exit()
        {
            exit(0);
        }
        string Type()
        {
#if defined(_WIN32) || defined(_WIN64)
            return "Windows";

#elif defined(__APPLE__) && defined(__MACH__)
            return "MacOS";
#elif defined(__linux__)
            return "Linux";
#else
            return "Unknown OS";
#endif
        }
        bool IsWindows()
        {
            if (Type() == "Windows")
            {
                return true;
            }
            return false;
        }
        string Arch()
        {
            if (IsWindows())
            {
#if defined(_WIN32)
                return "x86";
#elif defined(_WIN64)
                return "x64";
#endif
            }
            return "";
        }
        // void Title(string title)
        // {
        //      int buffer;
        //     if (Type() == "Windows")
        //     {
        //         buffer = IO::OS::System("title " + title);
        //         if (buffer == 1)
        //             Clear();
        //     }
        //     else if (Type() == "Linux" || Type() == "MacOS")
        //     {
        //         buffer = IO::OS::System("echo -ne \"\\033]0;" + title + "\\007\"");
        //         if (buffer == 1)
        //             Clear();
        //     }
        // }
        // void WaitKey()
        // {
        //      int buffer;
        //     if (Type() == "Windows")
        //     {
        //         buffer = IO::OS::System("pause > nul");
        //         if (buffer == 1)
        //             Clear();
        //     }
        //     else if (Type() == "Linux" || Type() == "MacOS")
        //     {
        //         buffer = IO::OS::System("read -n1 -s key");
        //         if (buffer == 1)
        //             Clear();
        //     }
        // }
        // void Clear()
        // {
        //     if (Type() == "Windows")
        //         IO::OS::System("cls");
        //     else if (Type() == "Linux" || Type() == "MacOS")
        //         IO::OS::System("clear");
        // }

    }
    namespace Display
    {
        void PrintInt(const int &value)
        {
            cout << value;
        }
        void PrintChar(char value)
        {
            cout << value;
        }
        void PrintString(string value)
        {
            for (size_t i = 0; i < value.length(); i++)
            {
                PrintChar(value[i]);
            }
        }

    }
    namespace File
    {
        void Write(const string &filename, const string &content)
        {
            ofstream f(filename.c_str());
            f << content;
            f.close();
        }
        bool Exists(string filename)
        {

            ifstream f(filename.c_str());

            if (!f.is_open())
                return false;
            return true;
        }
        string Read(const string &filename)
        {

            string content = "", line = "";
            ifstream file(filename.c_str());

            while (getline(file, line))
            {
                content += line + "\n";
            }
            file.close();
            return content;
        }
    }

}