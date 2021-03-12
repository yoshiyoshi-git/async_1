#pragma once

#include "StringViewModel.g.h"

namespace winrt::async_1::implementation
{
    struct StringViewModel : StringViewModelT<StringViewModel>
    {
        StringViewModel();
        StringViewModel(const winrt::hstring value);

        void DataString(winrt::hstring const& value);
        winrt::hstring DataString();

        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:

        winrt::hstring m_DataString;
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

    };
}

namespace winrt::async_1::factory_implementation
{
    struct StringViewModel : StringViewModelT<StringViewModel, implementation::StringViewModel>
    {
    };
}
