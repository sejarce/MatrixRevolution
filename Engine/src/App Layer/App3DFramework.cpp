#include "App3DFramework.h"
#include "../Core/Context.h"

using namespace Cloudream;

App3DFramework::App3DFramework()
{
}


App3DFramework::~App3DFramework()
{
}


void App3DFramework::Create()
{
	//read cfg file
	ContextCfg cfg = Context::Instance().GetConfig();
	Context::Instance().SetConfig(cfg);

	this->OnCreate();
	this->OnResize(cfg.settings.width,cfg.settings.height);
}


void App3DFramework::Destroy()
{
	this->OnDestroy();

	Context::Destroy();
}


void App3DFramework::Suspend()
{
	Context::Instance().Suspend();
	this->Suspend();
}


void App3DFramework::Resume()
{  
	Context::Instance().Resume();
	this->OnResume();
}


void App3DFramework::Refresh()
{

}


void App3DFramework::Run()
{

}


void App3DFramework::Quit()
{

}


void App3DFramework::OnResize(uint32_t /*width*/, uint32_t /*height*/)
{
	//this->Proj(this->ActiveCamera().NearPlane(), this->ActiveCamera().FarPlane());
}


uint32_t App3DFramework::GetTotalNumFrames() const
{				
	return _totalNumFrame;
}


float App3DFramework::GetFPS() const
{					
	return _fps;
}


float App3DFramework::GetAppTime() const
{
	return _appTime;
}

