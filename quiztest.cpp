#include "main.cpp"
#include <doctest.h>

TEST_SUITE_BEGIN("file main");

TEST_CASE("CheckResults"){
    Question_Text = "?";
    Answer_1 = "1";
    Answer_2 = "2";
    Answer_3 = "3";
    Answer_4 = "4";
    Correct_Answer = 3;
    Question_Score = 10;
    TestQuiz = Question();

    REQUIRE(TestQuiz.askQuestion() == "Correct !\n""Score = 10 out of 10!\n");



}

TEST_SUITE_END();