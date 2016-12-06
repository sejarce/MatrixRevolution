#include "Context.h"
#include "Util.h"	 

namespace
{
	std::mutex singleton_mutex;
}

using namespace Cloudream;
std::unique_ptr<Context> Context::_context_instance;


Context::Context()
{

}


Context::~Context()
{
}	


Context& Context::Instance()
{
	if (!_context_instance)
	{
		std::lock_guard<std::mutex> lock(singleton_mutex);
		if (!_context_instance)
		{
			_context_instance = MakeUniquePtr<Context>();
		}
	}
	return *_context_instance;
}


void Context::Destroy()
{
	std::lock_guard<std::mutex> lock(singleton_mutex);
	if (_context_instance)
	{
		_context_instance->DestroyAll();
		_context_instance.reset();
	}
}


void Context::Suspend()
{

}


void Context::Resume()
{

}


void Context::SetConfig(ContextCfg const & cfg)
{ 
	_cfg = cfg;
}


ContextCfg const & Context::GetConfig() const
{
	return _cfg;
}	 


void Context::DestroyAll()
{
}