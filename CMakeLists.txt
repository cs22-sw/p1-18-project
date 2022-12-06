cmake_minimum_required(VERSION 3.1)
project(TicketSystem C)
set(CMAKE_C_STANDARD 11)

add_executable(ticket-system src/ticket-system.c)
add_library(create-match-stats src/create-match-stats.c)
