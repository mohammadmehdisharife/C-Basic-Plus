#include <string>
#include "../IO/IO.hpp"
#include "../Runtime.hpp"
using namespace std;
void Error(const string& msg)
{
    IO::Display::PrintString("\n\n\n=======Error=======");
    IO::Display::PrintString("\nLine: ");
    IO::Display::PrintInt(Runtime::LineCode);
    IO::Display::PrintString("\nContent line: ");
    IO::Display::PrintString(Runtime::codeLine);
    IO::Display::PrintString("\nRuntime Message: ");
    IO::Display::PrintString(msg);
    IO::Display::PrintString("\n===================\n");
    

    IO::OS::Exit();
}
