#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

#include <string>
#include <sstream>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.System.Threading.Core.h>

namespace winrt::async_1::implementation
{
    MainPage::MainPage()
    {
        m_SSync = winrt::make<async_1::implementation::StringViewModel>();
        m_SAsync1 = winrt::make<async_1::implementation::StringViewModel>();
        m_SAsync2 = winrt::make<async_1::implementation::StringViewModel>();
        m_SAsync3 = winrt::make<async_1::implementation::StringViewModel>();
            

        InitializeComponent();
    }
    async_1::StringViewModel MainPage::SSync()
    {
        return m_SSync;
    }
    async_1::StringViewModel MainPage::SAsync1()
    {
        return m_SAsync1;
    }
    async_1::StringViewModel MainPage::SAsync2()
    {
        return m_SAsync2;
    }
    async_1::StringViewModel MainPage::SAsync3()
    {
        return m_SAsync3;
    }

    winrt::Windows::Foundation::IAsyncAction MainPage::Async_Background()
    {
        for (int i = 1; i <= 5; ++i)
        {
            //重い処理はバックグラウンドで！！
            co_await winrt::resume_background();

            //1秒もかかる凄い重い処理だ！！
            Sleep(1000);

            //重い処理が終わったらもどすぞ！！
            co_await winrt::resume_foreground(this->Dispatcher());

            std::wostringstream woss;
            woss << i;
            std::wstring mes = woss.str() + L"秒経過！";
            SAsync1().DataString(mes);
        }
    }

    winrt::Windows::Foundation::IAsyncAction MainPage::Async_ThreadPool()
    {
        for (int i = 1; i <= 5; ++i)
        {
            //重い処理はスレッドプールで
            co_await winrt::Windows::System::Threading::ThreadPool::RunAsync([&](winrt::Windows::Foundation::IAsyncAction const& workItem)
                {
                    //1秒もかかる凄い重い処理だ！！
                    Sleep(1000);
                });

            std::wostringstream woss;
            woss << i;
            std::wstring mes = woss.str() + L"秒経過！";
            SAsync2().DataString(mes);
        }
    }
}


void winrt::async_1::implementation::MainPage::syncButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    for (int i = 1; i <= 5; ++i)
    {
        //1秒もかかる凄い重い処理だ！！
        Sleep(1000);

        std::wostringstream woss;
        woss << i;
        std::wstring mes = woss.str() + L"秒経過！";
        SSync().DataString(mes);
    }
}


void winrt::async_1::implementation::MainPage::asyncButton1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    Async_Background();
}


void winrt::async_1::implementation::MainPage::asyncButton2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    Async_ThreadPool();
}


winrt::Windows::Foundation::IAsyncAction winrt::async_1::implementation::MainPage::asyncButton3_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    for (int i = 1; i <= 5; ++i)
    {
        //重い処理はスレッドプールで
        co_await winrt::Windows::System::Threading::ThreadPool::RunAsync([&](winrt::Windows::Foundation::IAsyncAction const& workItem)
            {
                //1秒もかかる凄い重い処理だ！！
                Sleep(1000);
            });

        std::wostringstream woss;
        woss << i;
        std::wstring mes = woss.str() + L"秒経過！";
        SAsync3().DataString(mes);
    }
}
