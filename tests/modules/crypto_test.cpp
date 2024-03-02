#include "../test_helpers.h"
#include <faker/crypto.h>
#include <regex>

using namespace faker;

TEST(CryptoTest, should_generate_sha256)
{
    const auto sha256_checksum = crypto::sha256();

    static const std::regex re_sha256("^[a-f0-9]{64}$");

    EXPECT_TRUE(std::regex_match(sha256_checksum, re_sha256));
}

TEST(CryptoTest, should_generate_md5)
{
    const auto md5_checksum = crypto::md5();

    static const std::regex re_md5("^[a-f0-9]{32}$");

    EXPECT_TRUE(std::regex_match(md5_checksum, re_md5));
}
