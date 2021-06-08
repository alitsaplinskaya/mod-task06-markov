#include <gtest/gtest.h>
#include "../include/textgen.h"

TEST(task1, test1)
{
    vector<string> word{ "What", "a", "beautiful", "day!" };
    Markov Generator(word, 3, 100);
    string output = Generator.TextGenerator();
    if (output[0] = 'W')
        ASSERT_STREQ("What a beautiful day! ", output.c_str());
    else
        ASSERT_STREQ("a beautiful day! ", output.c_str());
}

TEST(task2, test2)
{
    vector<string> word{ "Just", "Nice" };
    Markov Generator(word, 2, 100);
    ASSERT_STREQ("Just Nice ", Generator.TextGenerator().c_str());
}

TEST(task3, test3)
{
    map<deque<string>, vector<string>> dict;
    dict[{"Live", "the"}].push_back("read");
    dict[{"the", "read"}].push_back("<Last_Prefix>");
    Markov Generator(dict, 100);
    string output = Generator.TextGenerator();
    if (output[0] == 'L')
        ASSERT_STREQ("Live the read ", output.c_str());
    else
        ASSERT_EQ('t', output[0]);
}

TEST(task4, test4)
{
    map<deque<string>, vector<string>> dict;
    dict[{"Raed", "the"}].push_back("book");
    dict[{"Look", "the"}].push_back("sunset");
    dict[{"the", "book"}].push_back("<Last_Prefix>");
    dict[{"the", "sunset"}].push_back("<Last_Prefix>");

    Markov Generator(dict, 100);
    string output = Generator.TextGenerator();
    if (output[0] == 't')
        ASSERT_EQ('t', output[0]);
    else if (output[output[output.length() - 2]] == 'e')
        ASSERT_STREQ("Read the book ", output.c_str());
    else
        ASSERT_STREQ("Look the sunset ", output.c_str());
}

TEST(task5, test5)
{
    vector<string> word{ "Then", "you", "want", "to", "be", "artist,", "artist", "allready", "be", "yourself." };
    Markov Generator(word, 2, 100);
    string output = Generator.TextGenerator();
    if (output[output.length() - 2] == '.')
        ASSERT_EQ('.', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}