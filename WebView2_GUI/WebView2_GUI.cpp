// WebView2_GUI.cpp : Source file for your target.
//

#include <Atliac/WebView2_GUI.h>
#include <winrt/base.h>

std::wstring WebView2_GUI::from_utf8(const std::string_view utf8)
{
    auto h=winrt::to_hstring(utf8);
    return std::wstring(h.begin(), h.end());
}

std::string WebView2_GUI::to_utf8(const std::wstring_view wide)
{
    return winrt::to_string(wide);
}
