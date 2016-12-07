/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    RenderEngine.h
*
* 这个档案定义RenderEngine这个class
*
* @version 1.0
* @author  敖建
* @date    2016-10-18
*********************************************************************/

#pragma once
#include "../Export.h"

#ifndef _RENDERENGINE_H
#define _RENDERENGINE_H

namespace Cloudream{
	class ENGINE_DLLCLASS_EXPORTS RenderEngine
	{
	public:
		/*
		*@ 构造
		*/
		RenderEngine();
		/*
		*@ 析构
		*/
		virtual ~RenderEngine();
	public:

		void Suspend();

		void Resume();
	};
}

#endif