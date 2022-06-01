cmake_minimum_required(VERSION 3.0)

project(cbtinyirc LANGUAGES C)

add_executable(cbtinyirc main.c sock.c)
add_definitions(-std=c11 -Wall -Wextra -Werror -Og -lpthreads)
install(TARGETS cbtinyirc RUNTIME DESTINATION bin)
