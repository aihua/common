// Copyright (c) 2016, Baidu.com, Inc. All Rights Reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: yanshiguang02@baidu.com

#include <gtest/gtest.h>

#include <util.h>

namespace baidu {
namespace common {
namespace util {

TEST(UtilTest, TestEncodeDecode) {
    char buf1[8];
    char buf2[8];
    uint64_t x = 123456789;
    uint64_t y = 200000000;
    EncodeBigEndian(buf1, x);
    EncodeBigEndian(buf2, y);
    printf("%s %s\n", std::string(buf1, 8).c_str(), std::string(buf2, 8).c_str());
    ASSERT_TRUE(std::string(reinterpret_cast<char*>(&x), 8) > std::string(reinterpret_cast<char*>(&y), 8));
    ASSERT_TRUE(std::string(buf1, 8) < std::string(buf2, 8));
    ASSERT_EQ(DecodeBigEndian64(buf1), x);
    ASSERT_EQ(DecodeBigEndian64(buf2), y);

    uint32_t a = 123456789;
    uint32_t b = 200000000;
    char bufa[4];
    char bufb[4];
    EncodeBigEndian(bufa, a);
    EncodeBigEndian(bufb, b);
    printf("%s %s\n", std::string(bufa, 4).c_str(), std::string(bufb, 4).c_str());
    ASSERT_TRUE(std::string(reinterpret_cast<char*>(&a), 4) > std::string(reinterpret_cast<char*>(&b), 4));
    ASSERT_TRUE(std::string(bufa, 4) < std::string(bufb, 4));
    ASSERT_EQ(DecodeBigEndian32(bufa), a);
    ASSERT_EQ(DecodeBigEndian32(bufb), b);
}

}
}
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

