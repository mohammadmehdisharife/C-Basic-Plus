#include <string>
#include "../IO/IO.hpp"
#include "../Error/Error.hpp"
#include "./Int.hpp"
using namespace std;
namespace Int
{

    bool IsNumber(const string &content)
    {

        size_t numberLength = content.length() - 1;
        if (content[0] == '+' || content[0] == '-' || content[0] == '*' || content[0] == '%' || content[0] == '/' ||
            content[numberLength] == '+' || content[numberLength] == '-' || content[numberLength] == '*' ||
            content[numberLength] == '%' || content[numberLength] == '/')
        {
            return false;
        }
        for (size_t i = 0; i < content.length(); i++)
        {
            switch (content[i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                continue;
            default:
                return false;
            }
        }

        return true;
    }
    bool IsProcess(char work)
    {
        switch (work)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return true;
        default:
            return false;
        }
    }
    string Process(string num1, string num2, char work)
    {
        int bufferNum1 = atoi(num1.c_str()),
            bufferNum2 = atoi(num2.c_str());
        switch (work)
        {
        case '+':
            return IO::String::IntToString(bufferNum1 + bufferNum2);
        case '-':
            return IO::String::IntToString(bufferNum1 - bufferNum2);
        case '*':
            return IO::String::IntToString(bufferNum1 * bufferNum2);
        case '/':
            if (bufferNum2 == 0)
                Error("Zero Division Error: Division by Zero");
            return IO::String::IntToString(bufferNum1 / bufferNum2);

        case '%':
            if (bufferNum2 == 0)
                Error("Zero Division Error: Division by Zero");

            return IO::String::IntToString(bufferNum1 % bufferNum2);
        }
        /* Aref
        This line for fix warning Compiler
        */
        return ""; 
    }
    int Create(const string &content)
    {

        string num1 = "",
               num2 = "";
        char work = '\0';
        bool op = false;

        for (size_t i = 0; i < content.length(); i++)
        {
            if (op && work != '\0' && IsProcess(content[i]))
            {
                num1 = Process(num1, num2, work);
                num2.clear();
                work = '\0';
                op = !op;
                i--;
                continue;
            }

            if (!IsProcess(content[i]))
            {
                if (work == '\0')
                    num1 += content[i];
                else
                    num2 += content[i];
                continue;
            }
            else
            {
                work = content[i];
                op = true;
            }
        }

        if (!num2.empty() && work != '\0')
            num1 = Process(num1, num2, work);
            
        return atoi(num1.c_str());
    }
}