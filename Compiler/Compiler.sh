g++ -m64 -static -Wall -Wextra -O3 Main.cpp ./Compiler/IO/IO.cpp \
./Compiler/Compiler.cpp  ./Compiler/Error/Error.cpp ./Compiler/Syntax/Print/Print.cpp \
./Compiler/Variable/Int.cpp  ./Compiler/Variable/String.cpp -o ../Release/cbp.out