cmake_minimum_required(VERSION 3.21)
project(5)

set(CMAKE_CXX_STANDARD 17)

add_executable(5 main.cpp ThreadSafeQueue.h Department.h Buyer.h Product.h Seller.h Seller.cpp Buyer.cpp Department.cpp)

find_package (Threads)
target_link_libraries (5 ${CMAKE_THREAD_LIBS_INIT})
