/********************************************************************
* Copyright (c) 2016 ��������֮�οƼ����޹�˾
* All rights reserved.
*
* @file    App3DFramework.h
*
* �����������App3DFramework���class,
*
* @version 1.0
* @author  ����
* @date    2016-10-14
*********************************************************************/
#ifndef _APP3DFRAMEWORK_H
#define	_APP3DFRAMEWORK_H

#pragma once
#include <stdint.h>

#include "../Export.h" 

namespace Cloudream{

	// һ�����ڴ���3DӦ�ó����ܵĻ��ࡣ����һ��3DӦ�ó�����Ҫ�̳�����࣬
	//			Ȼ���������º���:
	//
	//			OnCreate()				- Called when the app is creating.
	//			OnDestroy()				- Called when the app is destroying.
	//			OnSuspend()				- Called when the app is suspending
	//			OnResume()				- Called when the app is resuming.
	//			DoUpdate()				- ˢ�³���
	//			DoUpdateOverlay()		- ˢ��Overlay����
	/////////////////////////////////////////////////////////////////////////////////
	class ENGINE_DLLCLASS_EXPORTS App3DFramework
	{
	public:
		/*
		*@ ����
		*/
		App3DFramework();
		/*
		*@ ����
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
		*@ ��������
		*/
		void Run();
		/*
		*@ �˳�����
		*/
		void Quit();  
		/*
		*@ ��Ӧapp���ڱ仯
		*/
		virtual void OnResize(uint32_t width, uint32_t height);
		/*
		*@ ��ȡ��ǰ��֡��
		*/
		uint32_t GetTotalNumFrames() const;
		/*
		*@ ��ȡ��ǰ֡��
		*/
		float GetFPS() const;
		/*
		*@ ��ȡapp����ʱ��
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