/********************************************************************
* Copyright (c) 2016 ��������֮�οƼ����޹�˾
* All rights reserved.
*
* @file    RenderEngine.h
*
* �����������RenderEngine���class
*
* @version 1.0
* @author  ����
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
		*@ ����
		*/
		RenderEngine();
		/*
		*@ ����
		*/
		virtual ~RenderEngine();
	public:

		void Suspend();

		void Resume();
	};
}

#endif