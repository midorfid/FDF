cmake_minimum_required(VERSION 3.21.0)

project(FdF)
set (SRCS
    src/main.c
    src/error.c
    src/fdf.c
    src/hooks.c
    src/parsing.c
    src/ft_atoi_save.c
    src/map.c
    src/plot_img.c
    src/apply_iso.c
    src/scale.c
    src/offset.c
    src/update_screen.c
    src/drawline.c
    src/utils.c
)
set (EXEC_NAME fdf)

#compiler settings:
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra -Ofast -O3")
set (CMAKE_C_FLAGS_DEBUG "-g -fsanitize=address") #cmake -DCMAKE_BUILD_TYPE=DEBUG to add debug flags
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) #vscode include path checking

#norm rules so flclean and re work
add_custom_target(fclean make clean)
add_custom_target(re make clean COMMAND make)

#compile MLX42
add_custom_target(build_mlx42 ALL
                   COMMAND ${CMAKE_MAKE_PROGRAM}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/MLX42
                   COMMENT "Original MLX42 makefile target")
add_library(mlx42 STATIC IMPORTED)
set_property(TARGET mlx42 APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(mlx42 PROPERTIES IMPORTED_LOCATION_NOCONFIG "${CMAKE_CURRENT_SOURCE_DIR}/MLX42/libmlx42.a")
add_dependencies(mlx42 build_mlx42)
target_include_directories(mlx42 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/MLX42/include)

#make executable with output name specified under EXEC_NAME and sources specified under SRCS
add_executable(${EXEC_NAME} ${SRCS})
target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_library(GLFW_LIB NAMES glfw3 glfw)
target_link_libraries(${EXEC_NAME} PRIVATE mlx42 ${GLFW_LIB})
if (APPLE)
target_link_libraries(${EXEC_NAME} PRIVATE "-framework Cocoa" "-framework OpenGL" "-framework IOKit")
endif()

#optionaly add libft:
add_subdirectory(./Libft)
add_subdirectory(./Libft/get_next_line)
target_link_libraries(${EXEC_NAME} PRIVATE ft)
target_link_libraries(${EXEC_NAME} PRIVATE get_next_line)