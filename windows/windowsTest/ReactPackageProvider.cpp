#include "pch.h"
#include "ReactPackageProvider.h"
#include "NativeModules.h"
#include "Notifications.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::windowsTest::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
    AddAttributedModules(packageBuilder, true);
}

} // namespace winrt::windowsTest::implementation
