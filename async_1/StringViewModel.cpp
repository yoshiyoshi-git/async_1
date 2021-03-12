#include "pch.h"
#include "StringViewModel.h"
#if __has_include("StringViewModel.g.cpp")
#include "StringViewModel.g.cpp"
#endif

namespace winrt::async_1::implementation
{
    StringViewModel::StringViewModel() : m_DataString(L"クリックしてないよ！")
    {
    }
    StringViewModel::StringViewModel(const winrt::hstring value)
    {
        m_DataString = value;
    }
    void StringViewModel::DataString(winrt::hstring const& value)
    {
        m_DataString = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"DataString" });
    }
    winrt::hstring StringViewModel::DataString()
    {
        return m_DataString;
    }
    winrt::event_token StringViewModel::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void StringViewModel::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
