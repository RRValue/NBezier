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

#define NBEnableForceInline
#ifdef NBEnableForceInline
#define NBInline inline
#else
#define NBForceInline
#endif  // NBezierEnableForceInline

#define DO_PRAGMA(x) _Pragma(#x)

#if __clang__
#define ClangDisableWarning(warnoption) \
    DO_PRAGMA(clang diagnostic push)    \
    DO_PRAGMA(clang diagnostic ignored #warnoption)
#define ClangEnableWarning() DO_PRAGMA(clang diagnostic pop)
#else
#define ClangDisableWarning(warnoption, ...)
#define ClangEnableWarning()
#endif
