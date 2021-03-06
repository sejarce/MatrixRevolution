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
#ifndef _RENDERSETTINGS_H
#define	_RENDERSETTINGS_H	

#pragma once

namespace Cloudream{
	// 渲染窗口的设置
	/////////////////////////////////////////////////////////////////////////////////
	struct RenderSettings
	{
		RenderSettings()
			: hide_win(false), full_screen(false),
			left(0), top(0), width(1280), height(720)
		{
		}

		bool	hide_win;
		bool	full_screen;
		int		left;
		int		top;
		int		width;
		int		height; 


	}; 
}

#endif