#pragma once
#include <string>

namespace CodeCtrl::data {
struct BacktraceData {
    std::string name;
    std::string file_path;
    uint32_t line_number;
    uint32_t column_number;
    std::string code;

    BacktraceData(std::string name,
                  std::string file_path,
                  uint32_t line_number,
                  uint32_t column_number,
                  std::string code)
        : name(name),
          file_path(file_path),
          line_number(line_number),
          column_number(column_number),
          code(code) {}
};
}  // namespace CodeCtrl::data