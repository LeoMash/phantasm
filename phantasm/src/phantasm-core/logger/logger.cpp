#define _ELPP_NO_DEFAULT_LOG_FILE

#include <easylogging++.h>

#include "logger.h"

INITIALIZE_EASYLOGGINGPP


PHM_CORE_API void StartLogging (void)
{

   el::Loggers::configureFromGlobal("logging.conf");

   LOG(INFO) << "Starting...";

}


PHM_CORE_API void LogMessage (LOGGING_LEVELS level, const std::string & msg)
{
   switch (level) {
   case LOGGING_LEVELS::INFO:
      LOG(INFO) << msg;
      break;

   case LOGGING_LEVELS::WARNING:
      LOG(WARNING) << msg;
      break;

   case LOGGING_LEVELS::ERROR:
      LOG(ERROR) << msg;
      break;
   }
}


PHM_CORE_API void LogInfo (const std::string & msg)
{
   LOG(INFO) << msg;
}


PHM_CORE_API void LogWarning (const std::string & msg)
{
   LOG(WARNING) << msg;
}


PHM_CORE_API void LogError(const std::string & msg)
{
   LOG(ERROR) << msg;
}

