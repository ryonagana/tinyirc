cmake_minimum_required(VERSION 3.0)

project(cbtinyirc LANGUAGES C)

add_executable(cbtinyirc main.c)

install(TARGETS cbtinyirc RUNTIME DESTINATION bin)
