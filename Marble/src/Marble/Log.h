#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Marble {
	
	class MARBLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// Core log macros
#define MB_CORE_TRACE(...)     ::Marble::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MB_CORE_INFO(...)      ::Marble::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MB_CORE_WARN(...)      ::Marble::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MB_CORE_ERROR(...)     ::Marble::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MB_CORE_CRITICAL(...)  ::Marble::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MB_TRACE(...)          ::Marble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MB_INFO(...)           ::Marble::Log::GetClientLogger()->info(__VA_ARGS__)
#define MB_WARN(...)           ::Marble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MB_ERROR(...)          ::Marble::Log::GetClientLogger()->error(__VA_ARGS__)
#define MB_CRITICAL(...)       ::Marble::Log::GetClientLogger()->critical(__VA_ARGS__)
