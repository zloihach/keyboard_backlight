cmake_minimum_required(VERSION 3.22)
project(lab2)

set(CMAKE_CXX_STANDARD 23)
set(LIBRARY_OUTPUT_PATH )

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#target_link_libraries(lab2 PRIVATE -static-libgcc -static-libstdc++)
#C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Program Files\PostgresPro\14\bin;C:\Program Files (x86)\Bitvise SSH Client;C:\Program Files\Microsoft SQL Server\150\Tools\Binn\;C:\Program Files\dotnet\;C:\Program Files\Microchip\xc8\v2.31\bin;C:\Program Files\Go\bin;C:\Program Files\Git\cmd;c:\matlab6p5\bin\win32;C:\Users\FSB-PC\AppData\Local\Microsoft\WindowsApps;C:\Users\FSB-PC\AppData\Roaming\npm;C:\Users\FSB-PC\AppData\Local\Programs\Microsoft VS Code Insiders\bin;C:\Users\FSB-PC\.dotnet\tools;C:\Users\FSB-PC\go\bin;C:\Users\FSB-PC\AppData\Local\JetBrains\Toolbox\scripts
add_executable(lab2 main.cpp)
