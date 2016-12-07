/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    Context.h
*
* @version 1.0
* @author  敖建
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
		*@ 构造
		*/
		Context();
		/*
		*@ 构造
		*/
		~Context();
		/*
		*@ 实例化Context
		*/
		static Context& Instance();
		/*
		*@ 回收Context
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