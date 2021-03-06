#ifndef SASS_UTF8_STRING
#define SASS_UTF8_STRING

#include <string>

namespace Sass {
  namespace UTF_8 {

    // naming conventions:
    // offset: raw byte offset (0 based)
    // position: code point offset (0 based)
    // index: code point offset (1 based or negative)

    // function that will count the number of code points (utf-8 characters) from the beginning to the given end
    size_t code_point_count(const string& str, size_t start, size_t end);
    size_t code_point_count(const string& str);

    // function that will return the byte offset of a code point in a
    size_t offset_at_position(const string& str, size_t position);

    // function that returns number of bytes in a character in a string
    size_t code_point_size_at_offset(const string& str, size_t offset);

    // function that will return a normalized index, given a crazy one
    size_t normalize_index(int index, size_t len);

    #ifdef _WIN32
    // functions to handle unicode paths on windows
    string convert_from_utf16(const wstring& wstr);
    wstring convert_to_utf16(const string& str);
    #endif

  }
}

#endif
