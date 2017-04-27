#include "easylogging++.h"

#include "logger.h"

INITIALIZE_EASYLOGGINGPP

void StartLogging (void)
{

   el::Loggers::configureFromGlobal("logging.conf");

   LOG(INFO) << "Starting...";

}

void LogMessage (std::string str)
{
   LOG(INFO) << str;
}

