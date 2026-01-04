#include "./Compiler/IO/IO.hpp"
#include "./Compiler/Compiler.hpp"
#include "./Compiler/Info/Info.hpp"
bool error = true;

int main(int argc, char *argv[])
{

        for (int i = 0; i < argc; i++)
        {
                string input = argv[i];
                if (input == "-ver")
                {
                        error = false;
                        IO::Display::PrintString(Info::logo);
                        IO::Display::PrintString("\n" + Info::Name + " V" + Info::Version + " " + IO::OS::Arch());
                        IO::Display::PrintString("\nRunning in " + IO::OS::Type());
                        IO::Display::PrintString("\n" + Info::License + "\n" +
                                                 Info::Builder + " " + Info::Copyright + "\n" +
                                                 Info::WebSite + "\n");
                }
                if (input == "-file")
                {
                        error = false;
                        input = argv[++i];
                        if (!IO::File::Exists(input))
                        {
                                IO::Display::PrintString("Error: File not found!\n");
                                return 0;
                        }
                        Compiler::Compile(IO::File::Read(input));
                }
                if (input == "-help")
                {
                        error = false;
                        IO::Display::PrintString("===Switches===\n");
                        IO::Display::PrintString("-ver            \tDisplay C-Basic version\n");
                        IO::Display::PrintString("-file <filename>\tCompile code\n");
                }
        }
        if (error)
                IO::Display::PrintString("Type switch -help\n");

        return 0;
}
