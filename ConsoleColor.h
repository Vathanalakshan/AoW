#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#if defined(_WIN32)

#include <windows.h>

inline std::ostream& blue(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
                                     |FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& red(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
                            FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& green(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
                            FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& yellow(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
                            FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    return s;
}

inline std::ostream& white(std::ostream &s)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,
                            FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    return s;
}

struct color {
    color(WORD attribute):m_color(attribute){};
    WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem,_Traits>&
operator<<(std::basic_ostream<_Elem,_Traits>& i, color& c)
{
    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout,c.m_color);
    return i;
}

#elif defined(__linux__) || defined(__APPLE__)

inline std::ostream& blue(std::ostream &s) { return s << "\033[34m"; }

inline std::ostream& red(std::ostream &s) { return s << "\033[31m"; }

inline std::ostream& green(std::ostream &s) { return s << "\033[32m"; }

inline std::ostream& yellow(std::ostream &s) { return s << "\033[33m"; }

inline std::ostream& white(std::ostream &s) { return s << "\033[37m"; }

#else
#error "Incompatible OS. This only supports Windows and Linux."
#endif

#endif //COLOUR_H
