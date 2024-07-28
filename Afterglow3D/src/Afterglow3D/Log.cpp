#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Afterglow3D
{
	std::shared_ptr<spdlog::logger> Log::m_EngineLogger;
	std::shared_ptr<spdlog::logger> Log::m_AppLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%I:%M:%S %p] %n: %v%$");

		m_EngineLogger = spdlog::stdout_color_mt("AFTERGLOW");
		m_EngineLogger->set_level(spdlog::level::trace);

		m_AppLogger = spdlog::stdout_color_mt("APP");
		m_AppLogger->set_level(spdlog::level::trace);
	}
}