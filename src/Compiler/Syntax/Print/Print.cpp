#include <string>
#include "../../Error/Error.hpp"
#include "../../Variable/String.hpp"
#include "../../Variable/Int.hpp"
#include <iostream>
#include "../../IO/IO.hpp"
using namespace std;
namespace Print
{
    void Text(const string &content)
    {

        string output = "", buffer = "";
        size_t end = content.length();

         if (content[0] == '&' || content[end - 1] == '&')
             Error("Syntax Error!");
        for (size_t text = 0; text < end; text++)
        {

            if (content[text] != '&')
            {
                buffer += content[text];
                continue;
            }
            else if (Int::IsNumber(buffer))
                output += Int::Create(buffer);
            else if (String::IsString(buffer))
                output += String::Create(buffer);
            else
                Error("Syntax Error!");
            

            buffer.clear();
        }

        if (!buffer.empty())
        {
            if (Int::IsNumber(buffer))
                output += IO::String::IntToString(Int::Create(buffer));
            else if (String::IsString(buffer))
                output += String::Create(buffer);
            else
                Error("Syntax Error!");
            
            buffer.clear();
        }




        IO::Display::PrintString(output);
    }
}