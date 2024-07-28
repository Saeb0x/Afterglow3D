#pragma once

#include "Core.h"
#include <memory>
#include <spdlog/spdlog.h>

namespace Afterglow3D
{
	class AFTERGLOW3D_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return m_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetAppLogger() { return m_AppLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_EngineLogger;
		static std::shared_ptr<spdlog::logger> m_AppLogger;
	};
}

// Core Engine Logs
#define AG_ENGINE_ERROR(...) Afterglow3D::Log::GetEngineLogger()->error(__VA_ARGS__)
#define AG_ENGINE_WARN(...) Afterglow3D::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define AG_ENGINE_INFO(...) Afterglow3D::Log::GetEngineLogger()->info(__VA_ARGS__)
#define AG_ENGINE_DEBUG(...) Afterglow3D::Log::GetEngineLogger()->debug(__VA_ARGS__)
#define AG_ENGINE_TRACE(...) Afterglow3D::Log::GetEngineLogger()->trace(__VA_ARGS__)

// External App Logs
#define AG_APP_ERROR(...) Afterglow3D::Log::GetAppLogger()->error(__VA_ARGS__)
#define AG_APP_WARN(...) Afterglow3D::Log::GetAppLogger()->warn(__VA_ARGS__)
#define AG_APP_INFO(...) Afterglow3D::Log::GetAppLogger()->info(__VA_ARGS__)
#define AG_APP_DEBUG(...) Afterglow3D::Log::GetAppLogger()->debug(__VA_ARGS__)
#define AG_APP_TRACE(...) Afterglow3D::Log::GetAppLogger()->trace(__VA_ARGS__)