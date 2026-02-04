// Slingshot: A SystemVerilog language server.
//
// Copyright (c) 2026 M. L. Young.
//
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL
// was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#include "slingshot/compiler.hpp"
#include "slingshot/slingshot.hpp"
#include <memory>

namespace slingshot {
bool g_running = false;
IndexManager g_indexManager = {};
CompilationManager g_compilerManager = {};
RemoteDebugger g_debugger = {};
std::shared_ptr<lsp::MessageHandler> g_msgHandler = {};
CompletionManager g_completionManager = {};
} // namespace slingshot
