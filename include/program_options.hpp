#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

namespace program_options {
    void parse(int argc, char* argv[]);

    bool log_errors();
    char delimiter();
    bool rtime();
};

#endif