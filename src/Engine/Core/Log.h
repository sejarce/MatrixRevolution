/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    Log.h
*
* 这个档案定义若干程序运行的Log,
*
* @version 1.0
* @author  敖建
* @date    2016-10-14
*********************************************************************/
#ifndef _LOG_H
#define	_LOG_H

#pragma once 
#include "../Export.h"

#include <memory>
#include <mutex>
#include <string>


namespace Cloudream{

	class ENGINE_DLLCLASS_EXPORTS Log 
	{  
	public:
		/*
		*@ 构造
		*/
		Log();		
		/*
		*@ 析构
		*/
		~Log();
		/*
		*@ 实例化Context
		*/
		static Log& Instance();
		/*
		*@ 回收Log
		*/
		static void Destroy();

		//**********************************************************
		// Method   : write
		// Remark   : 写入一条日志
		// DateTime : 2015/08/24
		// Parameter: int level							日志类型（错误、警告、信息）
		// Parameter: const char * filename				源文件 文件名
		// Parameter: const char * function				源文件 函数名
		// Parameter: int line							源文件 代码行数
		// Parameter: const char * format				日志格式内容
		// Parameter: ...								日志内容XXX
		// Returns  : void
		//**********************************************************
		void	write(int level, const char *filename, const char *function, int line, const char *, ...);

		bool	init(const std::string &filePath);

	private:
		void	cleanup();

		void	write(const std::string &text);

	private:
		static std::unique_ptr<Log> _Log_instance;
		std::string		_filePath;		// 日志全路径，默认log.html
		FILE*			_handle;		// 日志文件句柄
	};

	/************************************************************************
	******************       简化日志库调用的辅助宏        ********************
	************************************************************************/
#define		YZM_ERROR(format, ...)	yzm::Log::getInstance().write(yzm::Log::Error, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_WARN(format, ...)	yzm::Log::getInstance().write(yzm::Log::Warn, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_INFO(format, ...)	yzm::Log::getInstance().write(yzm::Log::Info, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_DEBUG(format, ...)	yzm::Log::getInstance().write(yzm::Log::Debug, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#define		YZM_VALUE(val)			yzm::Log::getInstance().write(yzm::Log::Info, __FILE__, __FUNCTION__, __LINE__, "  [%s = %s]  ", #val, yzm::StrT::toString(val).c_str())

#define		YZM_LOG_NAME(name)		yzm::Log::getInstance().init(name)
}

#endif