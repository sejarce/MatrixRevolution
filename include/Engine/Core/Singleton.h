/********************************************************************
* Copyright (c) 2016 ��������֮�οƼ����޹�˾
* All rights reserved.
*
* @file    Singleton.h
*
* ����������嵥��ģʽģ��
*
* @version 1.0
* @author  ����
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
		*@ ����ʵ��
		*/
		static inline T* instance();
		/*
		*@ ��������ʵ��
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