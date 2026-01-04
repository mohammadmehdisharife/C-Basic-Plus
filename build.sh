g++ -m64 -static -Wall -Wextra -O3 ./src/Main.cpp ./src/Runtime/IO/IO.cpp \
./src/Runtime/Runtime.cpp  ./src/Runtime/Error/Error.cpp ./src/Runtime/Syntax/Print/Print.cpp \
./src/Runtime/Variable/Int.cpp  ./src/Runtime/Variable/String.cpp -o ./build/cbp
