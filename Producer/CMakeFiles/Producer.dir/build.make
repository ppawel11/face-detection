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
CMAKE_COMMAND = /snap/cmake/372/bin/cmake

# The command to remove a file.
RM = /snap/cmake/372/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wojtek/CLionProjects/face-detection/Producer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wojtek/CLionProjects/face-detection/Producer

# Include any dependencies generated for this target.
include CMakeFiles/Producer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Producer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Producer.dir/flags.make

CMakeFiles/Producer.dir/main.cpp.o: CMakeFiles/Producer.dir/flags.make
CMakeFiles/Producer.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/CLionProjects/face-detection/Producer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Producer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Producer.dir/main.cpp.o -c /home/wojtek/CLionProjects/face-detection/Producer/main.cpp

CMakeFiles/Producer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Producer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/CLionProjects/face-detection/Producer/main.cpp > CMakeFiles/Producer.dir/main.cpp.i

CMakeFiles/Producer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Producer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/CLionProjects/face-detection/Producer/main.cpp -o CMakeFiles/Producer.dir/main.cpp.s

CMakeFiles/Producer.dir/Connection/Connection.cpp.o: CMakeFiles/Producer.dir/flags.make
CMakeFiles/Producer.dir/Connection/Connection.cpp.o: Connection/Connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/CLionProjects/face-detection/Producer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Producer.dir/Connection/Connection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Producer.dir/Connection/Connection.cpp.o -c /home/wojtek/CLionProjects/face-detection/Producer/Connection/Connection.cpp

CMakeFiles/Producer.dir/Connection/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Producer.dir/Connection/Connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/CLionProjects/face-detection/Producer/Connection/Connection.cpp > CMakeFiles/Producer.dir/Connection/Connection.cpp.i

CMakeFiles/Producer.dir/Connection/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Producer.dir/Connection/Connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/CLionProjects/face-detection/Producer/Connection/Connection.cpp -o CMakeFiles/Producer.dir/Connection/Connection.cpp.s

CMakeFiles/Producer.dir/Camera/Camera.cpp.o: CMakeFiles/Producer.dir/flags.make
CMakeFiles/Producer.dir/Camera/Camera.cpp.o: Camera/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wojtek/CLionProjects/face-detection/Producer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Producer.dir/Camera/Camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Producer.dir/Camera/Camera.cpp.o -c /home/wojtek/CLionProjects/face-detection/Producer/Camera/Camera.cpp

CMakeFiles/Producer.dir/Camera/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Producer.dir/Camera/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wojtek/CLionProjects/face-detection/Producer/Camera/Camera.cpp > CMakeFiles/Producer.dir/Camera/Camera.cpp.i

CMakeFiles/Producer.dir/Camera/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Producer.dir/Camera/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wojtek/CLionProjects/face-detection/Producer/Camera/Camera.cpp -o CMakeFiles/Producer.dir/Camera/Camera.cpp.s

# Object files for target Producer
Producer_OBJECTS = \
"CMakeFiles/Producer.dir/main.cpp.o" \
"CMakeFiles/Producer.dir/Connection/Connection.cpp.o" \
"CMakeFiles/Producer.dir/Camera/Camera.cpp.o"

# External object files for target Producer
Producer_EXTERNAL_OBJECTS =

Producer: CMakeFiles/Producer.dir/main.cpp.o
Producer: CMakeFiles/Producer.dir/Connection/Connection.cpp.o
Producer: CMakeFiles/Producer.dir/Camera/Camera.cpp.o
Producer: CMakeFiles/Producer.dir/build.make
Producer: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
Producer: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
Producer: CMakeFiles/Producer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wojtek/CLionProjects/face-detection/Producer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Producer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Producer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Producer.dir/build: Producer

.PHONY : CMakeFiles/Producer.dir/build

CMakeFiles/Producer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Producer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Producer.dir/clean

CMakeFiles/Producer.dir/depend:
	cd /home/wojtek/CLionProjects/face-detection/Producer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wojtek/CLionProjects/face-detection/Producer /home/wojtek/CLionProjects/face-detection/Producer /home/wojtek/CLionProjects/face-detection/Producer /home/wojtek/CLionProjects/face-detection/Producer /home/wojtek/CLionProjects/face-detection/Producer/CMakeFiles/Producer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Producer.dir/depend

