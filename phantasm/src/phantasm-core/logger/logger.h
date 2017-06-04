#include <string>

#include "phm_core.h"

enum class LOGGING_LEVELS {
   INFO,
   WARNING,
   ERROR
};

PHM_CORE_API void StartLogging (void);
PHM_CORE_API void EndLogging (void);

PHM_CORE_API void LogMessage (LOGGING_LEVELS level, const std::string & msg);

PHM_CORE_API void LogInfo (const std::string & msg);
PHM_CORE_API void LogWarning (const std::string & msg);
PHM_CORE_API void LogError (const std::string & msg);
