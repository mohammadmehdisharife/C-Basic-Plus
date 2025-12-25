#pragma once
#include <string>
using namespace std;
namespace Compiler{
    void Compile(string code);
    extern int LineCode;
    extern string codeLine;
}