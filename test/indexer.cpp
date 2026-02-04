// Slingshot: A SystemVerilog language server.
//
// Copyright (c) 2025 M. L. Young.
//
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL
// was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_run_info.hpp>
#include <catch2/catch_test_case_info.hpp>
#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <cctype>
#include <slang/syntax/SyntaxPrinter.h>
#include <slang/syntax/SyntaxTree.h>
#include <spdlog/sinks/sink.h>
#include <spdlog/spdlog.h>

using namespace slang;
using namespace slang::syntax;

class TestRunListener : public Catch::EventListenerBase {
public:
    using Catch::EventListenerBase::EventListenerBase;

    void testRunStarting(Catch::TestRunInfo const & /*testRunInfo*/) override {
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::trace);

        spdlog::default_logger()->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%# %!] %v");
        for (auto &sink : spdlog::default_logger()->sinks()) {
            sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%# %!] %v");
        }
    }

    void testCaseStarting(Catch::TestCaseInfo const &testInfo) override {
        SPDLOG_INFO("===== BEGIN: {} =====", testInfo.name);
    }

    void testCaseEnded(Catch::TestCaseStats const &testCaseStats) override {
        SPDLOG_INFO("===== END: {} =====", testCaseStats.testInfo->name);
    }
};

CATCH_REGISTER_LISTENER(TestRunListener);

constexpr std::string strip(const std::string &str) {
    std::string local = str;
    // NOLINTNEXTLINE don't care about fuckin std::ranges man
    local.erase(std::remove_if(local.begin(), local.end(), isspace), local.end());
    return local;
}

TEST_CASE("Foo", "[Indexer]") {
    REQUIRE(true);
}
