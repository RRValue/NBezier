#pragma once

// clang-format off
#define OpenNameSpace(NameSpace) namespace NameSpace {
#define CloseNameSpace(NameSpace) }
#define UseNameSpace(NameSpace) using namespace NameSpace
// clang-format on

#define StaticClass(Class)             \
    Class() = delete;                  \
    ~Class() = delete;                 \
    Class(Class&) = delete;            \
    Class(Class&&) = delete;           \
    Class& operator=(Class&) = delete; \
    Class& operator=(Class&&) = delete