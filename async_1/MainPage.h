#pragma once

#include "MainPage.g.h"
#include "StringViewModel.h"

namespace winrt::async_1::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        async_1::StringViewModel SSync();
        async_1::StringViewModel SAsync1();
        async_1::StringViewModel SAsync2();
        async_1::StringViewModel SAsync3();

        winrt::Windows::Foundation::IAsyncAction Async_Background();
        winrt::Windows::Foundation::IAsyncAction Async_ThreadPool();

    private:
        async_1::StringViewModel m_SSync{ nullptr };
        async_1::StringViewModel m_SAsync1{ nullptr };
        async_1::StringViewModel m_SAsync2{ nullptr };
        async_1::StringViewModel m_SAsync3{ nullptr };
    public:
        void syncButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void asyncButton1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void asyncButton2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction asyncButton3_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::async_1::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
