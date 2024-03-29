# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anton_beton/Desktop/projects/FDF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton_beton/Desktop/projects/FDF

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anton_beton/Desktop/projects/FDF/CMakeFiles /home/anton_beton/Desktop/projects/FDF//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anton_beton/Desktop/projects/FDF/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named fclean

# Build rule for target.
fclean: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fclean
.PHONY : fclean

# fast build rule for target.
fclean/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fclean.dir/build.make CMakeFiles/fclean.dir/build
.PHONY : fclean/fast

#=============================================================================
# Target rules for targets named re

# Build rule for target.
re: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 re
.PHONY : re

# fast build rule for target.
re/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re.dir/build.make CMakeFiles/re.dir/build
.PHONY : re/fast

#=============================================================================
# Target rules for targets named build_mlx42

# Build rule for target.
build_mlx42: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 build_mlx42
.PHONY : build_mlx42

# fast build rule for target.
build_mlx42/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/build_mlx42.dir/build.make CMakeFiles/build_mlx42.dir/build
.PHONY : build_mlx42/fast

#=============================================================================
# Target rules for targets named fdf

# Build rule for target.
fdf: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fdf
.PHONY : fdf

# fast build rule for target.
fdf/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/build
.PHONY : fdf/fast

#=============================================================================
# Target rules for targets named ft

# Build rule for target.
ft: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ft
.PHONY : ft

# fast build rule for target.
ft/fast:
	$(MAKE) $(MAKESILENT) -f Libft/CMakeFiles/ft.dir/build.make Libft/CMakeFiles/ft.dir/build
.PHONY : ft/fast

#=============================================================================
# Target rules for targets named get_next_line

# Build rule for target.
get_next_line: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 get_next_line
.PHONY : get_next_line

# fast build rule for target.
get_next_line/fast:
	$(MAKE) $(MAKESILENT) -f Libft/get_next_line/CMakeFiles/get_next_line.dir/build.make Libft/get_next_line/CMakeFiles/get_next_line.dir/build
.PHONY : get_next_line/fast

src/apply_iso.o: src/apply_iso.c.o
.PHONY : src/apply_iso.o

# target to build an object file
src/apply_iso.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/apply_iso.c.o
.PHONY : src/apply_iso.c.o

src/apply_iso.i: src/apply_iso.c.i
.PHONY : src/apply_iso.i

# target to preprocess a source file
src/apply_iso.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/apply_iso.c.i
.PHONY : src/apply_iso.c.i

src/apply_iso.s: src/apply_iso.c.s
.PHONY : src/apply_iso.s

# target to generate assembly for a file
src/apply_iso.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/apply_iso.c.s
.PHONY : src/apply_iso.c.s

src/drawline.o: src/drawline.c.o
.PHONY : src/drawline.o

# target to build an object file
src/drawline.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/drawline.c.o
.PHONY : src/drawline.c.o

src/drawline.i: src/drawline.c.i
.PHONY : src/drawline.i

# target to preprocess a source file
src/drawline.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/drawline.c.i
.PHONY : src/drawline.c.i

src/drawline.s: src/drawline.c.s
.PHONY : src/drawline.s

# target to generate assembly for a file
src/drawline.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/drawline.c.s
.PHONY : src/drawline.c.s

src/error.o: src/error.c.o
.PHONY : src/error.o

# target to build an object file
src/error.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/error.c.o
.PHONY : src/error.c.o

src/error.i: src/error.c.i
.PHONY : src/error.i

# target to preprocess a source file
src/error.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/error.c.i
.PHONY : src/error.c.i

src/error.s: src/error.c.s
.PHONY : src/error.s

# target to generate assembly for a file
src/error.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/error.c.s
.PHONY : src/error.c.s

src/fdf.o: src/fdf.c.o
.PHONY : src/fdf.o

# target to build an object file
src/fdf.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/fdf.c.o
.PHONY : src/fdf.c.o

src/fdf.i: src/fdf.c.i
.PHONY : src/fdf.i

# target to preprocess a source file
src/fdf.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/fdf.c.i
.PHONY : src/fdf.c.i

src/fdf.s: src/fdf.c.s
.PHONY : src/fdf.s

# target to generate assembly for a file
src/fdf.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/fdf.c.s
.PHONY : src/fdf.c.s

src/ft_atoi_save.o: src/ft_atoi_save.c.o
.PHONY : src/ft_atoi_save.o

# target to build an object file
src/ft_atoi_save.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/ft_atoi_save.c.o
.PHONY : src/ft_atoi_save.c.o

src/ft_atoi_save.i: src/ft_atoi_save.c.i
.PHONY : src/ft_atoi_save.i

# target to preprocess a source file
src/ft_atoi_save.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/ft_atoi_save.c.i
.PHONY : src/ft_atoi_save.c.i

src/ft_atoi_save.s: src/ft_atoi_save.c.s
.PHONY : src/ft_atoi_save.s

# target to generate assembly for a file
src/ft_atoi_save.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/ft_atoi_save.c.s
.PHONY : src/ft_atoi_save.c.s

src/hooks.o: src/hooks.c.o
.PHONY : src/hooks.o

# target to build an object file
src/hooks.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/hooks.c.o
.PHONY : src/hooks.c.o

src/hooks.i: src/hooks.c.i
.PHONY : src/hooks.i

# target to preprocess a source file
src/hooks.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/hooks.c.i
.PHONY : src/hooks.c.i

src/hooks.s: src/hooks.c.s
.PHONY : src/hooks.s

# target to generate assembly for a file
src/hooks.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/hooks.c.s
.PHONY : src/hooks.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/main.c.s
.PHONY : src/main.c.s

src/map.o: src/map.c.o
.PHONY : src/map.o

# target to build an object file
src/map.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/map.c.o
.PHONY : src/map.c.o

src/map.i: src/map.c.i
.PHONY : src/map.i

# target to preprocess a source file
src/map.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/map.c.i
.PHONY : src/map.c.i

src/map.s: src/map.c.s
.PHONY : src/map.s

# target to generate assembly for a file
src/map.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/map.c.s
.PHONY : src/map.c.s

src/offset.o: src/offset.c.o
.PHONY : src/offset.o

# target to build an object file
src/offset.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/offset.c.o
.PHONY : src/offset.c.o

src/offset.i: src/offset.c.i
.PHONY : src/offset.i

# target to preprocess a source file
src/offset.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/offset.c.i
.PHONY : src/offset.c.i

src/offset.s: src/offset.c.s
.PHONY : src/offset.s

# target to generate assembly for a file
src/offset.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/offset.c.s
.PHONY : src/offset.c.s

src/parsing.o: src/parsing.c.o
.PHONY : src/parsing.o

# target to build an object file
src/parsing.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/parsing.c.o
.PHONY : src/parsing.c.o

src/parsing.i: src/parsing.c.i
.PHONY : src/parsing.i

# target to preprocess a source file
src/parsing.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/parsing.c.i
.PHONY : src/parsing.c.i

src/parsing.s: src/parsing.c.s
.PHONY : src/parsing.s

# target to generate assembly for a file
src/parsing.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/parsing.c.s
.PHONY : src/parsing.c.s

src/plot_img.o: src/plot_img.c.o
.PHONY : src/plot_img.o

# target to build an object file
src/plot_img.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/plot_img.c.o
.PHONY : src/plot_img.c.o

src/plot_img.i: src/plot_img.c.i
.PHONY : src/plot_img.i

# target to preprocess a source file
src/plot_img.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/plot_img.c.i
.PHONY : src/plot_img.c.i

src/plot_img.s: src/plot_img.c.s
.PHONY : src/plot_img.s

# target to generate assembly for a file
src/plot_img.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/plot_img.c.s
.PHONY : src/plot_img.c.s

src/scale.o: src/scale.c.o
.PHONY : src/scale.o

# target to build an object file
src/scale.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/scale.c.o
.PHONY : src/scale.c.o

src/scale.i: src/scale.c.i
.PHONY : src/scale.i

# target to preprocess a source file
src/scale.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/scale.c.i
.PHONY : src/scale.c.i

src/scale.s: src/scale.c.s
.PHONY : src/scale.s

# target to generate assembly for a file
src/scale.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/scale.c.s
.PHONY : src/scale.c.s

src/update_screen.o: src/update_screen.c.o
.PHONY : src/update_screen.o

# target to build an object file
src/update_screen.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/update_screen.c.o
.PHONY : src/update_screen.c.o

src/update_screen.i: src/update_screen.c.i
.PHONY : src/update_screen.i

# target to preprocess a source file
src/update_screen.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/update_screen.c.i
.PHONY : src/update_screen.c.i

src/update_screen.s: src/update_screen.c.s
.PHONY : src/update_screen.s

# target to generate assembly for a file
src/update_screen.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/update_screen.c.s
.PHONY : src/update_screen.c.s

src/utils.o: src/utils.c.o
.PHONY : src/utils.o

# target to build an object file
src/utils.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/utils.c.o
.PHONY : src/utils.c.o

src/utils.i: src/utils.c.i
.PHONY : src/utils.i

# target to preprocess a source file
src/utils.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/utils.c.i
.PHONY : src/utils.c.i

src/utils.s: src/utils.c.s
.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fdf.dir/build.make CMakeFiles/fdf.dir/src/utils.c.s
.PHONY : src/utils.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... build_mlx42"
	@echo "... fclean"
	@echo "... re"
	@echo "... fdf"
	@echo "... ft"
	@echo "... get_next_line"
	@echo "... src/apply_iso.o"
	@echo "... src/apply_iso.i"
	@echo "... src/apply_iso.s"
	@echo "... src/drawline.o"
	@echo "... src/drawline.i"
	@echo "... src/drawline.s"
	@echo "... src/error.o"
	@echo "... src/error.i"
	@echo "... src/error.s"
	@echo "... src/fdf.o"
	@echo "... src/fdf.i"
	@echo "... src/fdf.s"
	@echo "... src/ft_atoi_save.o"
	@echo "... src/ft_atoi_save.i"
	@echo "... src/ft_atoi_save.s"
	@echo "... src/hooks.o"
	@echo "... src/hooks.i"
	@echo "... src/hooks.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/map.o"
	@echo "... src/map.i"
	@echo "... src/map.s"
	@echo "... src/offset.o"
	@echo "... src/offset.i"
	@echo "... src/offset.s"
	@echo "... src/parsing.o"
	@echo "... src/parsing.i"
	@echo "... src/parsing.s"
	@echo "... src/plot_img.o"
	@echo "... src/plot_img.i"
	@echo "... src/plot_img.s"
	@echo "... src/scale.o"
	@echo "... src/scale.i"
	@echo "... src/scale.s"
	@echo "... src/update_screen.o"
	@echo "... src/update_screen.i"
	@echo "... src/update_screen.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

