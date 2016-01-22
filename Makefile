# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kele/work/active/menger/mixed_menger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kele/work/active/menger/mixed_menger

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kele/work/active/menger/mixed_menger/CMakeFiles /home/kele/work/active/menger/mixed_menger/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kele/work/active/menger/mixed_menger/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_all_paths

# Build rule for target.
test_all_paths: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_all_paths
.PHONY : test_all_paths

# fast build rule for target.
test_all_paths/fast:
	$(MAKE) -f tst/CMakeFiles/test_all_paths.dir/build.make tst/CMakeFiles/test_all_paths.dir/build
.PHONY : test_all_paths/fast

#=============================================================================
# Target rules for targets named test_connectivity_all

# Build rule for target.
test_connectivity_all: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_connectivity_all
.PHONY : test_connectivity_all

# fast build rule for target.
test_connectivity_all/fast:
	$(MAKE) -f tst/CMakeFiles/test_connectivity_all.dir/build.make tst/CMakeFiles/test_connectivity_all.dir/build
.PHONY : test_connectivity_all/fast

#=============================================================================
# Target rules for targets named test_edge_connectivity

# Build rule for target.
test_edge_connectivity: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_edge_connectivity
.PHONY : test_edge_connectivity

# fast build rule for target.
test_edge_connectivity/fast:
	$(MAKE) -f tst/CMakeFiles/test_edge_connectivity.dir/build.make tst/CMakeFiles/test_edge_connectivity.dir/build
.PHONY : test_edge_connectivity/fast

#=============================================================================
# Target rules for targets named test_ford_fulkerson

# Build rule for target.
test_ford_fulkerson: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_ford_fulkerson
.PHONY : test_ford_fulkerson

# fast build rule for target.
test_ford_fulkerson/fast:
	$(MAKE) -f tst/CMakeFiles/test_ford_fulkerson.dir/build.make tst/CMakeFiles/test_ford_fulkerson.dir/build
.PHONY : test_ford_fulkerson/fast

#=============================================================================
# Target rules for targets named test_graph

# Build rule for target.
test_graph: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_graph
.PHONY : test_graph

# fast build rule for target.
test_graph/fast:
	$(MAKE) -f tst/CMakeFiles/test_graph.dir/build.make tst/CMakeFiles/test_graph.dir/build
.PHONY : test_graph/fast

#=============================================================================
# Target rules for targets named test_mixed_paths

# Build rule for target.
test_mixed_paths: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_mixed_paths
.PHONY : test_mixed_paths

# fast build rule for target.
test_mixed_paths/fast:
	$(MAKE) -f tst/CMakeFiles/test_mixed_paths.dir/build.make tst/CMakeFiles/test_mixed_paths.dir/build
.PHONY : test_mixed_paths/fast

#=============================================================================
# Target rules for targets named test_subsets

# Build rule for target.
test_subsets: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test_subsets
.PHONY : test_subsets

# fast build rule for target.
test_subsets/fast:
	$(MAKE) -f tst/CMakeFiles/test_subsets.dir/build.make tst/CMakeFiles/test_subsets.dir/build
.PHONY : test_subsets/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test_all_paths"
	@echo "... test_connectivity_all"
	@echo "... test_edge_connectivity"
	@echo "... test_ford_fulkerson"
	@echo "... test_graph"
	@echo "... test_mixed_paths"
	@echo "... test_subsets"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

