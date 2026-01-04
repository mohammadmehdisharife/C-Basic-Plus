#include <string>
#include "./IO/IO.hpp"
#include "./Variable/String.hpp"
#include "./Variable/Int.hpp"
#include "./Error/Error.hpp"
#include "./Syntax/Print/Print.hpp"
using namespace std;
namespace Compiler
{
    int LineCode = 1;
    string codeLine = "";
    string buffer = "";
    void Compile(string code)
    {

        for (; LineCode <= IO::String::LineLength(code); LineCode++)
        {
            codeLine = IO::String::RemoveSpace(IO::String::SelectLine(code, LineCode));

            if (!codeLine.rfind("print(", 0) && codeLine.substr(codeLine.size() - 2) == ");")
            {

                Print::Text(IO::String::ReadyCode(codeLine, 6, codeLine.length() - 2));

                continue;
            }
            else if (!codeLine.rfind("sleep(", 0) && codeLine.substr(codeLine.size() - 2) == ");")
            {
                IO::OS::Sleep(Int::Create(IO::String::ReadyCode(codeLine, 6, codeLine.length() - 2)));
                continue;
            }

            else if (!codeLine.rfind("system(", 0) && codeLine.substr(codeLine.size() - 2) == ");")
            {
                IO::OS::System(IO::String::ReadyCode(codeLine, 7, codeLine.length() - 2));
                continue;
            }

            else if (codeLine.empty() || !codeLine.rfind("//", 0) || codeLine[0] == '\t' || codeLine[0] == '\r' || codeLine[0] == '\n')
                continue;
            else if (codeLine == "exit();")
                IO::OS::Exit();
            else

                Error("Syntax Error!");
        }
    }
}