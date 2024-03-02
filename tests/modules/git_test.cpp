#include "../test_helpers.h"
#include <common/formatter.h>
#include <common/strings.h>
#include <faker/git.h>
#include <faker/number.h>
#include <regex>

using namespace faker;

namespace {
static const std::string date_re_str = "[A-Z][a-z]{2} [A-Z][a-z]{2,3} (([0-2][0-9])|(3[0-1])) "
                                       "(([0-1][0-9])|(2[0-4])):[0-5][0-9]:[0-5][0-9] "
                                       "[1-2][0-9]{3} (-|\\+)((0[0-9])|(1[0-2]))00";
static const std::string message_re_str
    = R"([a-zA-Z]+(\-[a-zA-Z]+)* ([a-zA-Z\-]+(\-[a-zA-Z]+)*\s)*[a-zA-Z\-]+(\-[a-zA-Z]+)*)";

std::string generate_sha_regex_str(unsigned length)
{
    return utils::format("[0-9a-fA-F]{{{}}}", length);
}

std::string generate_sha_regex_str() { return "[0-9a-fA-F]+"; }

}

TEST(GitTest, should_generate_branch)
{
    const auto branch = git::branch();

    FAKER_EXPECT_BETWEEN(faker::utils::split(branch, "-").size(), 2, 7);
}

TEST(GitTest, should_generate_branch_with_max_issue_number)
{
    auto max_issue_number = number::integer(2u, 100u);

    auto branch_name = git::branch(max_issue_number);

    auto branch = utils::split(branch_name, "-");
    bool number_at_front = false;
    int number;
    while (!number_at_front) {
        branch = utils::split(git::branch(max_issue_number), "-");
        try {
            number = utils::to_int(branch[0]);
            number_at_front = true;
        } catch (...) {
            continue;
        }
    }

    FAKER_EXPECT_BETWEEN(number, 1, max_issue_number);
}

TEST(GitTest, should_generate_commit_date)
{
    auto commit_date = git::commit_date();

    const std::regex re_date("^" + date_re_str + "$");
    EXPECT_TRUE(std::regex_match(commit_date, re_date));
}

TEST(GitTest, should_generate_commit_entry)
{
    auto commit_entry = git::commit_entry();

    const std::regex re_entry("^commit " + generate_sha_regex_str()
        + "\nAuthor: [A-Z][a-zA-Z]+ [A-Z][a-zA-Z]+ .+@[0-9a-zA-Z]+\\.[0-9a-zA-Z]+\nDate: "
        + date_re_str + "\n\n\t" + message_re_str + "$");
    EXPECT_TRUE(std::regex_match(commit_entry, re_entry));
}

TEST(GitTest, should_generate_commit_message)
{
    auto message = git::commit_message();

    const std::regex re_message("^" + message_re_str + "$");
    EXPECT_TRUE(std::regex_match(message, re_message));
}

TEST(GitTest, should_generate_commit_sha)
{
    auto commit_sha = git::commit_sha(40);

    const std::regex re_sha("^" + generate_sha_regex_str(40) + "$");
    EXPECT_TRUE(std::regex_match(commit_sha, re_sha));
}

TEST(GitTest, should_generate_author)
{
    auto author = git::author();

    const std::regex re_name("^[A-Z][a-zA-Z]+\\s[A-Z][a-zA-Z]+$");
    const std::regex re_email("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    EXPECT_TRUE(std::regex_match(author.name, re_name));
    EXPECT_TRUE(std::regex_match(author.email, re_email));
}
