#pragma once
#include <NativeModules.h>
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.Data.Xml.Dom.h>

using namespace winrt::Windows::UI::Notifications;
using namespace winrt::Windows::Data::Xml::Dom;

REACT_MODULE(Notifications)
struct Notifications {
  REACT_INIT(Initialize);
  void Initialize(React::ReactContext const& context) noexcept {
    m_context = context;
  }

  REACT_METHOD(Raise, L"raise");
  void Raise(const std::string& text) noexcept {
    try {
      auto xml = ToastNotificationManager::GetTemplateContent(ToastTemplateType::ToastText01);
      auto textElements = xml.GetElementsByTagName(L"text");
      
      if (textElements.Length() > 0) {
        textElements.Item(0).AppendChild(xml.CreateTextNode(winrt::to_hstring(text)));
      }

      auto toast = ToastNotification(xml);
      ToastNotificationManager::CreateToastNotifier().Show(toast);
    }
    catch (const std::exception& e) {
      // You can log the error to catch any exceptions
      OutputDebugStringA(e.what());
    }
  }

private:
  React::ReactContext m_context;
};
