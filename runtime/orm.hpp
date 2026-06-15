#pragma once

#include <sqlite3.h>

#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::orm {

inline std::vector<std::string> splitPipe(const std::string& text) {
    std::vector<std::string> parts;
    std::string cur;
    for (char c : text) {
        if (c == '|') {
            parts.push_back(cur);
            cur.clear();
        } else {
            cur += c;
        }
    }
    parts.push_back(cur);
    return parts;
}

inline std::string quoteSqlLiteral(const std::string& value) {
    std::string out = "'";
    for (char c : value) {
        if (c == '\'') out += "''";
        else out += c;
    }
    out += "'";
    return out;
}

inline std::string findAll(const std::string& dbPath, const std::string& table) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return {};
    }

    const std::string sql = "SELECT * FROM " + table + ";";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
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

inline int insert(const std::string& dbPath, const std::string& table,
                  const std::string& columns, const std::string& values) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return -1;
    }

    const auto cols = splitPipe(columns);
    const auto vals = splitPipe(values);
    if (cols.empty() || cols.size() != vals.size()) {
        sqlite3_close(db);
        return -1;
    }

    std::ostringstream sql;
    sql << "INSERT INTO " << table << " (";
    for (std::size_t i = 0; i < cols.size(); ++i) {
        if (i > 0) sql << ", ";
        sql << cols[i];
    }
    sql << ") VALUES (";
    for (std::size_t i = 0; i < vals.size(); ++i) {
        if (i > 0) sql << ", ";
        sql << quoteSqlLiteral(vals[i]);
    }
    sql << ");";

    char* err = nullptr;
    const int rc = sqlite3_exec(db, sql.str().c_str(), nullptr, nullptr, &err);
    if (err) sqlite3_free(err);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return -1;
    }

    const int rowId = static_cast<int>(sqlite3_last_insert_rowid(db));
    sqlite3_close(db);
    return rowId;
}

inline bool deleteRows(const std::string& dbPath, const std::string& table,
                       const std::string& whereClause) {
    sqlite3* db = nullptr;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return false;
    }

    const std::string sql = "DELETE FROM " + table + " WHERE " + whereClause + ";";
    char* err = nullptr;
    const int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &err);
    if (err) sqlite3_free(err);
    sqlite3_close(db);
    return rc == SQLITE_OK;
}

} // namespace afrilang::runtime::orm
