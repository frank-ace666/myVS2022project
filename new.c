#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

typedef enum {
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
} LogLevel;

const char* get_current_time();

void log_message(LogLevel level, const char* format, ...);

int main(void) {
	log_message(LOG_INFO, "This is an information message with a number: %d\n", 42);
	log_message(LOG_WARNING, "This is a warning message for users: %s\n", "Frank");
	log_message(LOG_ERROR, "This is an error message related to file: %s\n", "example.txt");
	return EXIT_SUCCESS;
}

const char* get_current_time() {
	static char buffer[20];
	time_t now = time(NULL);
	struct tm tm_info;
	localtime_s(&tm_info, &now);
	strftime(buffer, 20, "%Y-%m-%d %H:%M:%S",&tm_info);

	return buffer;
}

void log_message(LogLevel level, const char* format, ...) {
	const char* level_str;
	switch (level) {
	case LOG_INFO: level_str = "INFO"; break;
	case LOG_WARNING: level_str = "WARNING"; break;
	case LOG_ERROR: level_str = "ERROR"; break;
	default: level_str = "UNKNOWN"; break;
	}

	printf("[%s] [%s] ", get_current_time(), level_str);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}