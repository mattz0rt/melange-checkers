#include "clang/StaticAnalyzer/Core/CheckerRegistry.h"
#include "UseDefChecker.h"
#include "TypeCastingVulnChecker.h"
#include "StrCpyOverflowChecker.h"

using namespace clang;
using namespace ento;

// Register plugin!
extern "C"
void clang_registerCheckers(CheckerRegistry &registry) {
  registry.addChecker<Melange::UseDefChecker>("alpha.security.UseDefChecker", "CXX UseDef Checker");
  registry.addChecker<Melange::TypeCastingVulnChecker>("alpha.security.CastChecker", "Unsafe cast checker");
  registry.addChecker<Melange::StrCpyOverflowChecker>("alpha.security.StrOverflowChecker", "Str Overflow Checker");
}

extern "C"
const char clang_analyzerAPIVersionString[] = CLANG_ANALYZER_API_VERSION_STRING;

