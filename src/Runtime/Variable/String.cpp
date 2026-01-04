#include <string>
#include "../Error/Error.hpp"
#include "../IO/IO.hpp"
#include "./Int.hpp"
using namespace std;
namespace String
{
    bool IsString(const string &content)
    {

        size_t end = content.length() - 1;
        if (content[0] != '\"' || content[end] != '\"')
            return false;
        for (size_t i = 1; i < end; i++)
        {
            if (content[i] == '\\')
            {
                i++;
                switch (content[i])
                {
                 
                case 'n':
                case 'T':
                case 'a':
                case 's':
                case '\\':
                case '\'':
                case 'b':
                case '\"':
                case '{':
                case '}':
                case 't':
                    break;
                case '0':
                    i = end;
                    break;
                default:
                    return false;
                    break;
                }
                continue;
            }
            if (content[i] == '"' || content[i] == '{' || content[i] == '}')
                return false;
        }

        return true;
    }
    string Create(const string &content)
    {
        string buffer = "";
        size_t end = content.length() - 1;

        for (size_t i = 1; i < end; i++)
        {
            if (content[i] == '"' || content[i] == '{' || content[i] == '}')
                Error("Escape Sequence Error!");
            if (content[i] == '\\')
            {
                switch (content[++i])
                {
                case 'n':
                    buffer += '\n';
                    break;
                case 'T':
                    buffer += '\t';
                    break;
                case 'a':
                    buffer += '\a';
                    break;
                case 's':
                    buffer += ' ';
                    break;
                case '\\':
                    buffer += '\\';
                    break;
                case '\'':
                    buffer += '\'';
                    break;
                case 'b':
                    buffer += '\b';
                    break;
                case '\"':
                    buffer += '\"';
                    break;
                case '0':
                    buffer += '\0';
                    i = end;
                    break;
                case '{':
                    buffer += '{';
                    break;
                case '}':
                    buffer += '}';
                    break;
                case 't':
                    for (int j = 0; j < 4; j++)
                    {
                        buffer += ' ';
                    }
                    break;

                default:
                    Error("Escape Sequence Error!");
                    break;
                }
                continue;
            }

            if (content[i] == '%' && content[i + 1] == 'o' && content[i + 2] == 's' && content[i + 3] == '%')
            {
                i += 3;
                buffer += IO::OS::Type();
            }
            else if (content[i] == '%' && content[i + 1] == 'a' && content[i + 2] == 'r' &&
                     content[i + 3] == 'c' && content[i + 4] == 'h' && content[i + 5] == '%')
            {
                i += 5;
                buffer += IO::OS::Arch();
            }
            // Date
            else if (content[i] == '%' && content[i + 1] == 'Y' && content[i + 2] == '%')
            {
                i += 2;
                buffer += IO::Clock::Year();
            }
            else if (content[i] == '%' && content[i + 1] == 'M' && content[i + 2] == '%')
            {
                i += 2;
                buffer += IO::Clock::Month();
            }
            else if (content[i] == '%' && content[i + 1] == 'D' && content[i + 2] == '%')
            {
                i += 2;
                buffer += IO::Clock::Day();
            }
            // Time
            else if (content[i] == '%' && content[i + 1] == 's' && content[i + 2] == '%')
            {
                i += 2;
                buffer += IO::Clock::Seconds();
            }
            else if (content[i] == '%' && content[i + 1] == 'm' && content[i + 2] == '%')
            {
                i += 2;
                buffer += IO::Clock::Minutes();
            }
            else if (content[i] == '%' && content[i + 1] == 'h' && content[i + 2] == '1' &&
                     content[i + 3] == '2' && content[i + 4] == '%')
            {
                i += 4;
                buffer += IO::Clock::Hour12();
            }
            else if (content[i] == '%' && content[i + 1] == 'h' && content[i + 2] == '2' &&
                     content[i + 3] == '4' && content[i + 4] == '%')
            {
                i += 4;
                buffer += IO::Clock::Hour24();
            }

            else if (content[i] == '%' && content[i + 1] == 'a' && content[i + 2] == 'p' && content[i + 3] == '%')
            {
                i += 3;
                buffer += IO::Clock::AMPM();
            }
            else
                buffer += content[i];
        }

        return buffer;
    }
}