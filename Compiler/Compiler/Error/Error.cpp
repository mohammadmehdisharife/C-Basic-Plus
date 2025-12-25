#include <string>
#include "../IO/IO.hpp"
#include "../Compiler.hpp"
using namespace std;
void Error(const string& msg)
{
    IO::Display::PrintString("\n\n\n=======Error=======");
    IO::Display::PrintString("\nLine: ");
    IO::Display::PrintInt(Compiler::LineCode);
    IO::Display::PrintString("\nContent line: ");
    IO::Display::PrintString(Compiler::codeLine);
    IO::Display::PrintString("\nCompiler Message: ");
    IO::Display::PrintString(msg);
    IO::Display::PrintString("\n===================\n");
    

    IO::OS::Exit();
}