#include "Log.h"
#include "Util.h"
#include <mutex>
#include <stdarg.h>
#include "time.inl"

namespace
{
	std::mutex singleton_mutex;
}

using namespace Cloudream;
std::unique_ptr<Log> Log::_Log_instance;

Log::Log()
{

}

Log::~Log()
{

}

Log& Log::Instance()
{
	if (!_Log_instance)
	{
		std::lock_guard<std::mutex> lock(singleton_mutex);
		if (!_Log_instance)
		{
			_Log_instance = MakeUniquePtr<Log>();
		}
	}
	return *_Log_instance;
}

void Log::Destroy()
{
	std::lock_guard<std::mutex> lock(singleton_mutex);
	if (_Log_instance)
	{
		//_Log_instance->cleanup();
		_Log_instance.reset();
	}
}

void Log::write(int level, const char *filename, const char *function, int line, const char *, ...)
{

}	 

bool Log::init(const std::string &filePath)
{
	return false;
}

void Log::cleanup()
{

}

void Log::write(const std::string &text)
{

}
