#include "Log.h"


std::shared_ptr<spdlog::logger> Log::log; //!< static variable init
std::vector<spdlog::sink_ptr> Log::sinks;
std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Log::consoleLog; //!< An std::out colored sink that will print out to the command line
std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> Log::fileLog; //!< A rotating file sink

void Log::Init()
{	
	consoleLog = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();	//Set console log to be a stdout colored sink
	fileLog = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("../bin/logs/log.txt", 1048576 * 5, 5);  //!< Set our file sink which has a max file size of 5MB and 5 rotated files.
	sinks.push_back(consoleLog); //!< Push the sinks to the vector
	sinks.push_back(fileLog); //!< Push the sinks to the vector
	log = std::make_shared<spdlog::logger>("Log", begin(sinks), end(sinks)); //!< Compile all of our sinks to the logger
	sinks.clear();		//!< clear the vector as it is no longer used
	consoleLog.reset();	//!< clear up the shared pointed as it is no longer used
	fileLog.reset();	//!< clear up the shared pointed as it is no longer used
	log->sinks()[0]->set_level(spdlog::level::trace); //!< setting the level the logger
	log->sinks()[1]->set_level(spdlog::level::trace); //!< setting the level the logger
	log->sinks()[0]->set_pattern("%^[%T.%e] %l: %v %$"); //!< 24hour + ms clock with the name of the log and log output along with its type
	log->sinks()[1]->set_pattern("%+"); //!< spdlog default format
	log->info(">>>>>----=== New Application ===----<<<<<");	//!< Print out a header to signal a new run of the application
}
