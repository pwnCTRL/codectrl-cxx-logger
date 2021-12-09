#pragma once
#include <asio.hpp>
#include <cstdint>
#include <iostream>
#include <map>
#include <optional>
#include <vector>

#include "backtrace_data.h"

namespace CodeCtrl::log {
template <typename T>
struct Log {
    std::vector<data::BacktraceData> stack;
    uint32_t line_number;
    std::map<uint32_t, std::string> code_snippet;
    std::string message;
    std::string message_type;
    std::string file_name;
    std::string address;
    std::vector<std::string> warnings;

   private:
    std::string host;
    uint32_t port;
    int surround;

   public:
    Log(std::string message,
        int surround = 3,
        std::string host = "127.0.0.1",
        uint32_t port = 3001);

    std::optional<asio::error_code> log();

   private:
    void get_stack_trace();
    void get_code();
    void get_code_snippet();
};
}  // namespace CodeCtrl::log