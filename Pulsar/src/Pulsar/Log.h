#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Pulsar {

	class PULSAR_API Log
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
#define PR_CORE_TRACE(...) ::Pulsar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PR_CORE_INFO(...)  ::Pulsar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PR_CORE_WARN(...)  ::Pulsar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PR_CORE_ERROR(...) ::Pulsar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PR_CORE_FATAL(...) ::Pulsar::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros
#define PR_TRACE(...)	   ::Pulsar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PR_INFO(...)	   ::Pulsar::Log::GetClientLogger()->info(__VA_ARGS__)
#define PR_WARN(...)	   ::Pulsar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PR_ERROR(...)	   ::Pulsar::Log::GetClientLogger()->error(__VA_ARGS__)
#define PR_FATAL(...)	   ::Pulsar::Log::GetClientLogger()->fatal(__VA_ARGS__)