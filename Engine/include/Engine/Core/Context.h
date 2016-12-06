/********************************************************************
* Copyright (c) 2016 ��������֮�οƼ����޹�˾
* All rights reserved.
*
* @file    Context.h
*
* @version 1.0
* @author  ����
* @date    2016-10-14
*********************************************************************/
#ifndef _CONTEXT_H
#define	_CONTEXT_H	

#pragma once		 
#include "../Export.h"
#include "../Rendering System/RenderSettings.h"

#include <memory>
#include <mutex>


namespace Cloudream{
	struct ContextCfg
	{	 
		RenderSettings settings;
	};

	class ENGINE_DLLCLASS_EXPORTS Context
	{
	public:
		/*
		*@ ����
		*/
		Context();
		/*
		*@ ����
		*/
		~Context();
		/*
		*@ ʵ����Context
		*/
		static Context& Instance();
		/*
		*@ ����Context
		*/
		static void Destroy();
		/*
		*@ suspend app
		*/
		void Suspend();
		/*
		*@ resume app
		*/
		void Resume();
		/*
		*@ set context config
		*/
		void SetConfig(ContextCfg const & cfg);
		/*
		*@ get context config
		*/
		ContextCfg const & GetConfig() const; 
		 
	private:
		void DestroyAll();

	private:
		static std::unique_ptr<Context> _context_instance;
	  	ContextCfg _cfg;
	};
}

#endif