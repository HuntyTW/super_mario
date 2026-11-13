#include "app_factory.hpp"

#ifdef WINDOWS_CONSOLE
	#include "windows_app_factory.hpp"
#elif defined(LINUX_CONSOLE)
	#include "linux_app_factory.hpp"
#elif defined(QT_GUI)
	#include "qt_app_factory.hpp"
#endif

namespace biv {

AppFactory* AppFactory::create_app_factory(int argc, char* argv[]) {
#ifdef WINDOWS_CONSOLE
	return new WindowsAppFactory();
#elif defined(LINUX_CONSOLE)
	return new LinuxAppFactory();
#elif defined(QT_GUI)
	return new QtAppFactory(argc, argv);
#else
	return nullptr;
#endif
}

} // namespace biv
