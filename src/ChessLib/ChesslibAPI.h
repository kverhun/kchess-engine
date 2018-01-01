#pragma once

#ifdef _WINDOWS
#ifdef CHESSLIB_EXPORT
#define CHESSLIB_API __declspec(dllexport)
#else
#define CHESSLIB_API __declspec(dllimport)
#endif
#else
#define CHESSLIB_API
#endif
