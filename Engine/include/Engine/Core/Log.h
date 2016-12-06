/********************************************************************
* Copyright (c) 2016 ��������֮�οƼ����޹�˾
* All rights reserved.
*
* @file    Log.h
*
* ��������������ɳ������е�Log,
*
* @version 1.0
* @author  ����
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
		*@ ����
		*/
		Log();		
		/*
		*@ ����
		*/
		~Log();
		/*
		*@ ʵ����Context
		*/
		static Log& Instance();
		/*
		*@ ����Log
		*/
		static void Destroy();

		//**********************************************************
		// Method   : write
		// Remark   : д��һ����־
		// DateTime : 2015/08/24
		// Parameter: int level							��־���ͣ����󡢾��桢��Ϣ��
		// Parameter: const char * filename				Դ�ļ� �ļ���
		// Parameter: const char * function				Դ�ļ� ������
		// Parameter: int line							Դ�ļ� ��������
		// Parameter: const char * format				��־��ʽ����
		// Parameter: ...								��־����XXX
		// Returns  : void
		//**********************************************************
		void	write(int level, const char *filename, const char *function, int line, const char *, ...);

		bool	init(const std::string &filePath);

	private:
		void	cleanup();

		void	write(const std::string &text);

	private:
		static std::unique_ptr<Log> _Log_instance;
		std::string		_filePath;		// ��־ȫ·����Ĭ��log.html
		FILE*			_handle;		// ��־�ļ����
	};

	/************************************************************************
	******************       ����־����õĸ�����        ********************
	************************************************************************/
#define		YZM_ERROR(format, ...)	yzm::Log::getInstance().write(yzm::Log::Error, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_WARN(format, ...)	yzm::Log::getInstance().write(yzm::Log::Warn, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_INFO(format, ...)	yzm::Log::getInstance().write(yzm::Log::Info, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)	
#define		YZM_DEBUG(format, ...)	yzm::Log::getInstance().write(yzm::Log::Debug, __FILE__, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)

#define		YZM_VALUE(val)			yzm::Log::getInstance().write(yzm::Log::Info, __FILE__, __FUNCTION__, __LINE__, "  [%s = %s]  ", #val, yzm::StrT::toString(val).c_str())

#define		YZM_LOG_NAME(name)		yzm::Log::getInstance().init(name)
}

#endif