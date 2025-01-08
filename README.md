# LOGGER WITHOUT FMT

Hi, this is my attempt to create a logger without fmt. How you know, fmt it is a popular open source C++ library that provides a more efficient alternative to the C++ iostreams library.
But still, sometimes it's better to just think and initialize it without fmt applications...maybe it didn't turn out very well, but I hope it will come in handy for you (someone).

# HIGHTLIGHTS
```c++
Logger.cpp

#pragma warning (once : 7595) // Warning for potential division by zero

// Global logger instance
MyLogger logger;

// Constructor: Initializes logger with name and output stream
TheLogger::TheLogger(std::string name, std::ostream& out)
    : name{ std::move(name) },
    out{ &out } {
    // Enable colors only for console output
    use_colors = &out == &std::cout;
}

// Convert log level to string with optional color formatting
std::string to_String(Logger level, bool use_colors) {
    return use_colors ? logger.color_levels[level] : logger.levels[level];
}
```
## It's the main part for initialize logger
```c++
Logger.hpp
struct Format {
    // Gets current time in HH:MM:SS format
    static std::string GetCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        std::tm local_tm;
        localtime_s(&local_tm, &time);
        ss << std::put_time(&local_tm, "%H:%M:%S");
        return ss.str();
    }
};

// Enum for different logging levels
enum Logger {
    DEBUG,      // Detailed information for debugging
    INFO,       // General information about program execution
    WARNING,    // Potentially harmful situations
    ERROR       // Error events that might still allow the program to continue
};
```
# EXAMPLE

[image]()
