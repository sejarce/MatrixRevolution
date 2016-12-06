/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    Singleton.h
*
* 这个档案定义单例模式模板
*
* @version 1.0
* @author  敖建
* @date    2016-10-14
*********************************************************************/

#ifndef _SINGLETON_H
#define	_SINGLETON_H

#pragma once

#include <memory>
#include <mutex>
#include <iostream>

namespace Cloudream
{		
	template <class T>
	class Singleton
	{
	public:
		/*
		*@ 创建实例
		*/
		static inline T* instance();
		/*
		*@ 主动销毁实例
		*/
		static inline void Destroy();

	private:
		Singleton(void){}
		~Singleton(void){}
		Singleton(const Singleton&){}
		Singleton & operator= (const Singleton &){}

		static std::auto_ptr<T> _instance;	
		static std::mutex singleton_mutex;

		//Class that will implement the singleton mode,
		//must use the macro in it's delare file
#define DECLARE_SINGLETON_CLASS( type ) \
		friend class std::auto_ptr< type >;\
		friend class Cloudream::Singleton< type >;
	};
}

#endif