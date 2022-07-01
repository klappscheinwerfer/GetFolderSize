/*
--version
--help
--diserrlog Disable error log (default: false)
--delimiter (delault: ,)
-i
--input     Input file
-o
--output    Output file (default: sizelog.txt)
--mode      total, files, folders, all (default: total)
--rtime     Add readable timestamp (default: false)
*/

#include <string_view>
#include <vector>
#include <stdexcept>

#include "../include/program_options.hpp"

namespace {
    static bool _log_errors = true;
    static char _delimiter = ',';
    static std::string_view _input_path;
    static std::string_view _output_path;
    static int _mode = 0;
    static bool _rtime = false;
}

void program_options::parse(int argc, char* argv[]) {
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    for (const auto& arg : args) {
        if (arg == "--version") {
            return;
        }
        if (arg == "--help") {
            return;
        }
        if (arg == "--diserrlog") {
            continue;
        }
        if (arg == "--delimiter") {
            continue;
        }
        if (arg == "-i" || arg == "--input") {
            continue;
        }
        if (arg == "-o" || arg == "--output") {
            continue;
        }
        if (arg == "--mode") {
            continue;
        }
        if (arg == "--rtime") {
            continue;
        }
    }

    return;
}

bool program_options::log_errors() {
    return _log_errors;
}

char program_options::delimiter() {
    return _delimiter;
}

bool program_options::rtime() {
    return _rtime;
}