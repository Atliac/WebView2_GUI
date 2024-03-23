#pragma once
#include <string>

namespace WebView2_GUI
{
std::wstring from_utf8(const std::string_view utf8);
std::string to_utf8(const std::wstring_view wide);
} // namespace WebView2_GUI