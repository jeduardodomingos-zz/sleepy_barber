# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\sleepy_barber.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\sleepy_barber.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\sleepy_barber.dir\flags.make

CMakeFiles\sleepy_barber.dir\main.c.obj: CMakeFiles\sleepy_barber.dir\flags.make
CMakeFiles\sleepy_barber.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sleepy_barber.dir/main.c.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\sleepy_barber.dir\main.c.obj /FdCMakeFiles\sleepy_barber.dir\ /FS -c "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\main.c"
<<

CMakeFiles\sleepy_barber.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sleepy_barber.dir/main.c.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\sleepy_barber.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\main.c"
<<

CMakeFiles\sleepy_barber.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sleepy_barber.dir/main.c.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\sleepy_barber.dir\main.c.s /c "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\main.c"
<<

# Object files for target sleepy_barber
sleepy_barber_OBJECTS = \
"CMakeFiles\sleepy_barber.dir\main.c.obj"

# External object files for target sleepy_barber
sleepy_barber_EXTERNAL_OBJECTS =

sleepy_barber.exe: CMakeFiles\sleepy_barber.dir\main.c.obj
sleepy_barber.exe: CMakeFiles\sleepy_barber.dir\build.make
sleepy_barber.exe: CMakeFiles\sleepy_barber.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sleepy_barber.exe"
	"C:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\sleepy_barber.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\sleepy_barber.dir\objects1.rsp @<<
 /out:sleepy_barber.exe /implib:sleepy_barber.lib /pdb:"D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug\sleepy_barber.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\sleepy_barber.dir\build: sleepy_barber.exe

.PHONY : CMakeFiles\sleepy_barber.dir\build

CMakeFiles\sleepy_barber.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sleepy_barber.dir\cmake_clean.cmake
.PHONY : CMakeFiles\sleepy_barber.dir\clean

CMakeFiles\sleepy_barber.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber" "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber" "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug" "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug" "D:\Projetos\Unifaj\Sistemas Operacionais\sleepy_barber\cmake-build-debug\CMakeFiles\sleepy_barber.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\sleepy_barber.dir\depend
