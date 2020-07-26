//
// Created by Jie Cao on 7/26/20.
//
#include "gtest/gtest.h"
#include "server/namenode/inode_file.h"
using namespace satifs;
namespace {

// Tests factorial of negative numbers.
    TEST(GetParentTest, Negative) {
        // This test is named "Negative", and belongs to the "FactorialTest"
        // test case.
        std::shared_ptr<INodeFile> inode_file = std::make_shared<INodeFile>();
        EXPECT_EQ(0, inode_file->get_blocks().size());
    }
}
