# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mishalzulfiqar/CLionProjects/Captive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DsaGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DsaGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DsaGame.dir/flags.make

CMakeFiles/DsaGame.dir/main.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DsaGame.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/main.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/main.cpp

CMakeFiles/DsaGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/main.cpp > CMakeFiles/DsaGame.dir/main.cpp.i

CMakeFiles/DsaGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/main.cpp -o CMakeFiles/DsaGame.dir/main.cpp.s

CMakeFiles/DsaGame.dir/Game.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DsaGame.dir/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Game.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Game.cpp

CMakeFiles/DsaGame.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Game.cpp > CMakeFiles/DsaGame.dir/Game.cpp.i

CMakeFiles/DsaGame.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Game.cpp -o CMakeFiles/DsaGame.dir/Game.cpp.s

CMakeFiles/DsaGame.dir/Player.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Player.cpp.o: ../Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DsaGame.dir/Player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Player.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Player.cpp

CMakeFiles/DsaGame.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Player.cpp > CMakeFiles/DsaGame.dir/Player.cpp.i

CMakeFiles/DsaGame.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Player.cpp -o CMakeFiles/DsaGame.dir/Player.cpp.s

CMakeFiles/DsaGame.dir/Blocks.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Blocks.cpp.o: ../Blocks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DsaGame.dir/Blocks.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Blocks.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Blocks.cpp

CMakeFiles/DsaGame.dir/Blocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Blocks.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Blocks.cpp > CMakeFiles/DsaGame.dir/Blocks.cpp.i

CMakeFiles/DsaGame.dir/Blocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Blocks.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Blocks.cpp -o CMakeFiles/DsaGame.dir/Blocks.cpp.s

CMakeFiles/DsaGame.dir/Enemy.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Enemy.cpp.o: ../Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/DsaGame.dir/Enemy.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Enemy.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Enemy.cpp

CMakeFiles/DsaGame.dir/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Enemy.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Enemy.cpp > CMakeFiles/DsaGame.dir/Enemy.cpp.i

CMakeFiles/DsaGame.dir/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Enemy.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Enemy.cpp -o CMakeFiles/DsaGame.dir/Enemy.cpp.s

CMakeFiles/DsaGame.dir/Captives.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Captives.cpp.o: ../Captives.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/DsaGame.dir/Captives.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Captives.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Captives.cpp

CMakeFiles/DsaGame.dir/Captives.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Captives.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Captives.cpp > CMakeFiles/DsaGame.dir/Captives.cpp.i

CMakeFiles/DsaGame.dir/Captives.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Captives.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Captives.cpp -o CMakeFiles/DsaGame.dir/Captives.cpp.s

CMakeFiles/DsaGame.dir/Sticks.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Sticks.cpp.o: ../Sticks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/DsaGame.dir/Sticks.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Sticks.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Sticks.cpp

CMakeFiles/DsaGame.dir/Sticks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Sticks.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Sticks.cpp > CMakeFiles/DsaGame.dir/Sticks.cpp.i

CMakeFiles/DsaGame.dir/Sticks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Sticks.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Sticks.cpp -o CMakeFiles/DsaGame.dir/Sticks.cpp.s

CMakeFiles/DsaGame.dir/Bullets.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/Bullets.cpp.o: ../Bullets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/DsaGame.dir/Bullets.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/Bullets.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/Bullets.cpp

CMakeFiles/DsaGame.dir/Bullets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/Bullets.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/Bullets.cpp > CMakeFiles/DsaGame.dir/Bullets.cpp.i

CMakeFiles/DsaGame.dir/Bullets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/Bullets.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/Bullets.cpp -o CMakeFiles/DsaGame.dir/Bullets.cpp.s

CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o: ../SuccessWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/SuccessWindow.cpp

CMakeFiles/DsaGame.dir/SuccessWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/SuccessWindow.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/SuccessWindow.cpp > CMakeFiles/DsaGame.dir/SuccessWindow.cpp.i

CMakeFiles/DsaGame.dir/SuccessWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/SuccessWindow.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/SuccessWindow.cpp -o CMakeFiles/DsaGame.dir/SuccessWindow.cpp.s

CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o: CMakeFiles/DsaGame.dir/flags.make
CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o: ../GameOverWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o -c /Users/mishalzulfiqar/CLionProjects/Captive/GameOverWindow.cpp

CMakeFiles/DsaGame.dir/GameOverWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DsaGame.dir/GameOverWindow.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mishalzulfiqar/CLionProjects/Captive/GameOverWindow.cpp > CMakeFiles/DsaGame.dir/GameOverWindow.cpp.i

CMakeFiles/DsaGame.dir/GameOverWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DsaGame.dir/GameOverWindow.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mishalzulfiqar/CLionProjects/Captive/GameOverWindow.cpp -o CMakeFiles/DsaGame.dir/GameOverWindow.cpp.s

# Object files for target DsaGame
DsaGame_OBJECTS = \
"CMakeFiles/DsaGame.dir/main.cpp.o" \
"CMakeFiles/DsaGame.dir/Game.cpp.o" \
"CMakeFiles/DsaGame.dir/Player.cpp.o" \
"CMakeFiles/DsaGame.dir/Blocks.cpp.o" \
"CMakeFiles/DsaGame.dir/Enemy.cpp.o" \
"CMakeFiles/DsaGame.dir/Captives.cpp.o" \
"CMakeFiles/DsaGame.dir/Sticks.cpp.o" \
"CMakeFiles/DsaGame.dir/Bullets.cpp.o" \
"CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o" \
"CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o"

# External object files for target DsaGame
DsaGame_EXTERNAL_OBJECTS =

DsaGame: CMakeFiles/DsaGame.dir/main.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Game.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Player.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Blocks.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Enemy.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Captives.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Sticks.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/Bullets.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/SuccessWindow.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/GameOverWindow.cpp.o
DsaGame: CMakeFiles/DsaGame.dir/build.make
DsaGame: /usr/local/lib/libsfml-graphics.2.5.1.dylib
DsaGame: /usr/local/lib/libsfml-audio.2.5.1.dylib
DsaGame: /usr/local/lib/libsfml-network.2.5.1.dylib
DsaGame: /usr/local/lib/libsfml-window.2.5.1.dylib
DsaGame: /usr/local/lib/libsfml-system.2.5.1.dylib
DsaGame: CMakeFiles/DsaGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable DsaGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DsaGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DsaGame.dir/build: DsaGame

.PHONY : CMakeFiles/DsaGame.dir/build

CMakeFiles/DsaGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DsaGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DsaGame.dir/clean

CMakeFiles/DsaGame.dir/depend:
	cd /Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mishalzulfiqar/CLionProjects/Captive /Users/mishalzulfiqar/CLionProjects/Captive /Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug /Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug /Users/mishalzulfiqar/CLionProjects/Captive/cmake-build-debug/CMakeFiles/DsaGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DsaGame.dir/depend

