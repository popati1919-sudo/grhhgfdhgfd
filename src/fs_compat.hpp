#pragma once

// Compatibility helpers for Geode 6, where Geode APIs use asp::fs::Path
// instead of std::filesystem::path.

#include <filesystem>
#include <string>
#include <string_view>

#include <asp/fs/Path.hpp>
#include <Geode/Result.hpp>
#include <matjson.hpp>

namespace eclipse::fsx {
    /// Converts a Geode (asp) path to a std::filesystem::path (UTF-8 aware).
    inline std::filesystem::path toStd(asp::fs::PathView p) {
        std::string s = p.string();
        return std::filesystem::path(
            std::u8string(reinterpret_cast<char8_t const*>(s.data()), s.size())
        );
    }

    /// Replacement for the removed geode::utils::string::pathToString.
    inline std::string toString(std::filesystem::path const& p) {
        auto u = p.u8string();
        return std::string(reinterpret_cast<char const*>(u.data()), u.size());
    }

    /// Converts a std::filesystem::path to a Geode (asp) path (UTF-8).
    inline asp::fs::Path toAsp(std::filesystem::path const& p) {
        auto u = p.u8string();
        return asp::fs::Path(std::string(reinterpret_cast<char const*>(u.data()), u.size()));
    }
}

// Geode 6 only provides a matjson serializer for asp::fs::Path.
template <>
struct matjson::Serialize<std::filesystem::path> {
    static geode::Result<std::filesystem::path> fromJson(matjson::Value const& value) {
        GEODE_UNWRAP_INTO(std::string str, value.asString());
        return geode::Ok(std::filesystem::path(
            std::u8string(reinterpret_cast<char8_t const*>(str.data()), str.size())
        ));
    }

    static matjson::Value toJson(std::filesystem::path const& value) {
        auto u = value.u8string();
        return matjson::Value(std::string(reinterpret_cast<char const*>(u.data()), u.size()));
    }
};
