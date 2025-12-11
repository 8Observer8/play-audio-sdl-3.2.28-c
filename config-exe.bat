cmake -G "MinGW Makefiles" -S . -B dist/win ^
-DSDL3_DIR=H:/libs/SDL3-devel-3.2.28-mingw/lib/cmake/SDL3 ^
-DSDL3_mixer_DIR=H:/libs/SDL3_mixer-devel-3.0.0-mingw/lib/cmake/SDL3_mixer ^
-DCMAKE_BUILD_TYPE=Debug
