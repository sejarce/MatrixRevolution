/********************************************************************
* Copyright (c) 2016 深圳市云之梦科技有限公司
* All rights reserved.
*
* @file    App3DFramework.h
*
* 这个档案定义App3DFramework这个class,
*
* @version 1.0
* @author  敖建
* @date    2016-10-14
*********************************************************************/
#ifndef _APP3DFRAMEWORK_H
#define	_APP3DFRAMEWORK_H

#pragma once
#include <stdint.h>

#include "../Export.h" 

namespace Cloudream{

	// 一个用于创建3D应用程序框架的基类。建立一个3D应用程序需要继承这个类，
	//			然后重载以下函数:
	//
	//			OnCreate()				- Called when the app is creating.
	//			OnDestroy()				- Called when the app is destroying.
	//			OnSuspend()				- Called when the app is suspending
	//			OnResume()				- Called when the app is resuming.
	//			DoUpdate()				- 刷新场景
	//			DoUpdateOverlay()		- 刷新Overlay物体
	/////////////////////////////////////////////////////////////////////////////////
	class ENGINE_DLLCLASS_EXPORTS App3DFramework
	{
	public:
		/*
		*@ 构造
		*/
		App3DFramework();
		/*
		*@ 析构
		*/
		virtual ~App3DFramework();

	public:
		/*
		*@ create app
		*/
		void Create();
		/*
		*@ destroy app
		*/
		void Destroy();
		/*
		*@ suspend app
		*/
		void Suspend();
		/*
		*@ resume app
		*/
		void Resume();
		/*
		*@ update app
		*/
		void Refresh();
		/*
		*@ 启动引擎
		*/
		void Run();
		/*
		*@ 退出程序
		*/
		void Quit();  
		/*
		*@ 响应app窗口变化
		*/
		virtual void OnResize(uint32_t width, uint32_t height);
		/*
		*@ 获取当前总帧数
		*/
		uint32_t GetTotalNumFrames() const;
		/*
		*@ 获取当前帧率
		*/
		float GetFPS() const;
		/*
		*@ 获取app运行时间
		*/
		float GetAppTime() const;
	protected:
		//uint32_t Update(uint32_t pass);
		//void UpdateStats();

	private:
		virtual void OnCreate()
		{
		}
		virtual void OnDestroy()
		{
		}
		virtual void OnSuspend()
		{
		}
		virtual void OnResume()
		{
		}

		virtual void DoUpdateOverlay() = 0;
		virtual uint32_t DoUpdate(uint32_t pass) = 0;

	private:
		uint32_t _totalNumFrame;
		float _fps;
		float _appTime;
	};
}

#endif