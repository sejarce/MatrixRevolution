#include "Singleton.h"

using namespace Cloudream;

template <class T>
inline T* Singleton<T>::instance()
{
	if (0 == _instance.get())
	{
		std::lock_guard<std::mutex> lock(singleton_mutex);
		if (0 == _instance.get())
		{
			_instance.reset(new T);
		}
	}
	return _instance.get();
}

template <class T>
inline void Singleton<T>::Destroy()
{
	std::lock_guard<std::mutex> lock(singleton_mutex);
	if (_instance.get().get())
	{
		_instance.reset();
	}
}
