/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    Util.h
*
* 这个档案定义若干模板函数
*
* @version 1.0
* @author  敖建
* @date    2016-10-14
*********************************************************************/		
#ifndef _UTIL_H
#define	_UTIL_H

#pragma once
#include <memory>	 															

namespace Cloudream
{
	template <typename T, typename... Args>
	inline std::unique_ptr<T> MakeUniquePtr(Args&&... args)
	{
		return MakeUniquePtrHelper<T>(std::is_array<T>(), std::forward<Args>(args)...);
	};

	template <typename T, typename... Args>
	inline std::unique_ptr<T> MakeUniquePtrHelper(std::true_type, size_t size)
	{
		static_assert(0 == std::extent<T>::value,
			"make_unique<T[N]>() is forbidden, please use make_unique<T[]>().");
		return std::make_unique<T>(size);  
	} 

	template <typename T, typename... Args>
	inline std::unique_ptr<T> MakeUniquePtrHelper(std::false_type, Args&&... args)
	{ 
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}

#endif