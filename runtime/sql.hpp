#pragma once

#include <sqlite3.h>

#include <string>

namespace afrilang {
namespace runtime {
namespace sql {

inline std::string query(const std::string& dbPath, const std::string& sqlText) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return {};
    }

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sqlText.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_close(db);
        return {};
    }

    std::string result;
    const int cols = sqlite3_column_count(stmt);
    bool firstRow = true;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        if (!firstRow) result += '\n';
        firstRow = false;
        for (int i = 0; i < cols; ++i) {
            if (i > 0) result += '|';
            const char* val = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            if (val) result += val;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}

inline bool exec(const std::string& dbPath, const std::string& sqlText) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return false;
    }
    char* err = nullptr;
    const int rc = sqlite3_exec(db, sqlText.c_str(), nullptr, nullptr, &err);
    if (err) sqlite3_free(err);
    sqlite3_close(db);
    return rc == SQLITE_OK;
}

} // namespace sql
} // namespace runtime
} // namespace afrilang
