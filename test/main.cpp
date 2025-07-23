#define TEST_MODULE CPACSGenTests
#include <gtest/gtest.h>

#include "../src/lib/SchemaParser.h"
#include "../src/lib/TypeSystem.h"
#include "../src/lib/CodeGen.h"
#include "../src/lib/Tables.h"
#include "../src/lib/Filesystem.h"

#include "utils.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void runTest() {
    const auto testDir = ::testDir();
    const auto schemaFile = testDir / "schema.xsd";
    const auto refFile = testDir / "ref.cpp";
    const auto resultFile = testDir / "result.cpp";

    tigl::Filesystem fs;

    const tigl::Tables tables(testDir.string());
    auto types = tigl::xsd::parseSchema(schemaFile.string());
    const auto& typeSystem = tigl::buildTypeSystem(types, tables);
    genCode(testDir.string(), typeSystem, "", tables, fs);

    fs.mergeFilesInto(resultFile);
    fs.flushToDisk();

    const auto ref = readTextFile(refFile);
    const auto result = readTextFile(resultFile);

    if (ref != result)
        ADD_FAILURE() << "ref and result mismatch. please diff files in filesystem";
    else
        std::filesystem::remove(resultFile);
}

TEST(CPACSGenTests, sequence) {
    runTest();
}

TEST(CPACSGenTests, all) {
    runTest();
}

TEST(CPACSGenTests, choice) {
    runTest();
}

TEST(CPACSGenTests, documentation) {
    runTest();
}

TEST(CPACSGenTests, uidinbasetype) {
    runTest();
}

TEST(CPACSGenTests, custombasetype) {
    runTest();
}

TEST(CPACSGenTests, basetypewithparent) {
    runTest();
}

TEST(CPACSGenTests, uidreferencevector) {
    runTest();
}

TEST(CPACSGenTests, cdata) {
    runTest();
}

TEST(CPACSGenTests, simplebasetypewithparent) {
    runTest();
}

TEST(CPACSGenTests, complextypewithsimplecontent) {
    runTest();
}

TEST(CPACSGenTests, collapsedifferentenums) {
    runTest();
}

TEST(CPACSGenTests, optionalchoice) {
    runTest();
}