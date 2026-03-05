cmake_minimum_required(VERSION 3.5)

project(CryptoTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CryptoTest main.cpp
    Authorization.cpp
    Ciphers.cpp
    CryptoTestEasy.cpp
    Levels.cpp
    RunApplication.cpp
    TestEasyFixed.cpp
    Ciphers.h
    Header.h
    CryptoTestEasy.h
    Levels.h
    RunApplication.h
    TestEasyFixed.h
    Authorization.h
)

include(GNUInstallDirs)
install(TARGETS CryptoTest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
