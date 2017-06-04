#include <easylogging++.h>


#include "logger.h"


INITIALIZE_EASYLOGGINGPP


static double  Frequency       = 0.0;
static __int64 counterStart = 0;

static void StartCounter (void)
{
   LARGE_INTEGER li;

   if (!QueryPerformanceFrequency(&li)) {
      LOG(ERROR) << "QueryPerformanceFrequency failed!";
   }

   Frequency = static_cast<double>(li.QuadPart) / 1000.0;

   QueryPerformanceCounter(&li);
   counterStart = li.QuadPart;
}


static double GetCounter (void)
{
   LARGE_INTEGER li;

   QueryPerformanceCounter(&li);

   return static_cast<double>(li.QuadPart - counterStart) / Frequency;
}


PHM_CORE_API void StartLogging (void)
{
   el::Loggers::reconfigureAllLoggers(el::Configurations("logging.conf"));

   LOG(INFO) << "Starting...";
   StartCounter();
}

PHM_CORE_API void EndLogging (void)
{
   double duration = GetCounter();
   LOG(INFO) << "Duration is " + std::to_string(duration) + " ms";
   LOG(INFO) << "The work is done!";
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

