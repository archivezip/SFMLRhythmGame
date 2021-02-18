#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Log {

private:
	static std::vector<spdlog::sink_ptr> sinks;	//!< vector of all the sinks that will be used in the logger 
	static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> consoleLog; //!< An std::out colored sink that will print out to the command line
	static std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> fileLog; //!< A rotating file sink
	static std::shared_ptr<spdlog::logger> log; //!< reference to the logger

public:
	static void Init();
	
	inline static std::shared_ptr<spdlog::logger>& getLog() { return log; } //!< Accessor function
};


#define LOG_TRACE(...) ::Log::getLog()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Log::getLog()->info(__VA_ARGS__)
#define LOG_WARN(...) ::Log::getLog()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Log::getLog()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Log::getLog()->critical(__VA_ARGS__)

#define LOG_ASSERT(x, ...) {if(!(x)) {LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

