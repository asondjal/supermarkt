"""Python-file for testing class Logging"""

from py_bindings import Logging, LogLevel

def test_logging():
    """Funktion zum Testen von LogLevel"""

    logger = Logging("loggingfile.txt", LogLevel.DEBUG, True)
    assert logger.get_level() == "DEBUG"
    logger.set_loglevel(LogLevel.ERROR)
    assert logger.get_level() == "ERROR"
    logger.set_loglevel(LogLevel.DEBUG)
    logger.enable_console_output(True)
    logger.start_log("System initialized.", LogLevel.INFO)
    logger.start_log("System deactivated.", LogLevel.INFO)
    logger.start_log("System restarted.", LogLevel.INFO)
    logger.start_log("ChatPGT free is expired!", LogLevel.WARNING)
    logger.start_log("FBI has hacked your PC!", LogLevel.WARNING)
    logger.start_log("WIFI-Connection was interrupted!", LogLevel.ERROR)
    logger.start_log("WIFI-Connection was interrupted by HTTP-Port 241", LogLevel.DEBUG)
