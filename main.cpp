#include <iostream>
#include "../LOGGER/Logger/Logger.hpp"

int main() {
	MyglobalLogger().logMessage(Logger::DEBUG, "Nice to Program.", __FILE__, __LINE__);
	MyglobalLogger().logMessage(Logger::INFO, "Logger initialized.", __FILE__, __LINE__);
	MyglobalLogger().logMessage(Logger::WARNING, "It's maybe been error", __FILE__, __LINE__);
	MyglobalLogger().logMessage(Logger::ERROR,"Failed to load texture", __FILE__, __LINE__);
	return 0;
}