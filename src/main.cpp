#include <iostream>
#include "../inc/utils/tests.hpp"
#include "../inc/utils/logging.hpp"

int main() {

	Tests tests;
	tests.runAllTests();

    Logging logger("logfile.txt", LogLevel::DEBUG);
    logger.log("System initialized.", LogLevel::INFO);
    logger.log("Reading configuration...", LogLevel::DEBUG);
    logger.log("File not found!", LogLevel::WARNING);
    logger.log("Critical error!", LogLevel::ERROR);

	return 0;
}
