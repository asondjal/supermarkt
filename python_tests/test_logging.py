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
