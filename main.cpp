#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int Guess;
int Total;

class Question {
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int Correct_Answer;
    int Question_Score;

public:
    void setValues(string, string,
                   string, string,
                   string, int, int);

    void askQuestion();
};

int CountLinesInFile(string filename)
{
    ifstream fin(filename, ios::in);

    if (!fin)
    {
        return -1;
    }

    int count = 0;
    char buffer[1000];

    while (!fin.eof())
    {
        count++;

        fin.getline(buffer, 1000);
    }

    fin.close();

    return count;
}
int GetStringsFromFileS(string filename, string** _lines)
{
    string* lines;
    int n = CountLinesInFile("table.txt");

    if (n == -1) return -1;

    ifstream F(filename);

    if (!F) return -1;

    try
    {
        lines = new string[n];
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
        F.close();
        return -2;
    }

    char buffer[1000];

    for (int i = 0; i < n; i++)
    {
        F.getline(buffer, 1000);

        int len;
        for (len = 0; buffer[len] != '\0'; len++);

        lines[i].assign(buffer, len);
    }

    F.close();
    *_lines = lines;
    return n;
}

bool SetStringsToFileS(string filename, string* lines, int count)
{
    ofstream F(filename);

    if (!F) return false;

    for (int i = 0; i < count - 1; i++)
        F << lines[i] << endl;

    F << lines[count - 1];

    F.close();

    return true;
}

bool InsertStringToFile(string filename, string str, int position)
{
    int count;
    string* lines = nullptr;

    count = GetStringsFromFileS(filename, &lines);

    if ((count < 0)) return false;

    if ((position < 0) || (position > count)) return false;

    string* lines2 = nullptr;
    try
    {
        lines2 = new string[count + 1];
    }
    catch (bad_alloc e)
    {
        cout << e.what() << endl;
        if (lines != nullptr)
            delete[] lines;
        return false;
    }

    for (int i = 0; i < position; i++)
        lines2[i] = lines[i];

    lines2[position] = str;

    for (int i = position; i < count; i++)
        lines2[i + 1] = lines[i];

    count++;

    bool res = SetStringsToFileS(filename, lines2, count);

    if (lines != nullptr) delete[] lines;
    if (lines2 != nullptr) delete[] lines2;

    return res;
}

int main()
{
    cout << "\n\n\t\t\t\tTHE DAILY QUIZ"
         << endl;
    cout << "\nPress Enter to start "
         << "the quiz... " << endl;

    cin.get();

    string Name;
    int Age;

    cout << "What is your name?"
         << endl;
    cin >> Name;
    cout << endl;

    cout << "How old are you?"
         << endl;
    cin >> Age;
    cout << endl;

    string Respond;
    cout << "Are you ready to take"
         << " the quiz " << Name
         << "? yes/no" << endl;
    cin >> Respond;

    if (Respond == "yes") {
        cout << endl;
        cout << "Good Luck!" << endl;
    }
    else {
        cout << "Okay Good Bye!" << endl;
        return 0;
    }

    Question q1;
    Question q2;
    Question q3;
    Question q4;
    Question q5;
    Question q6;
    Question q7;
    Question q8;
    Question q9;
    Question q10;

    q1.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q2.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q3.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q4.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q5.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q6.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q7.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q8.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q9.setValues("Question : ", "Answer 1",
                 "Answer 2", "Answer 3",
                 "Answer 4", 3, 10);
    q10.setValues("Question : ", "Answer 1",
                  "Answer 2", "Answer 3",
                  "Answer 4", 3, 10);

    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();
    q6.askQuestion();
    q7.askQuestion();
    q8.askQuestion();
    q9.askQuestion();
    q10.askQuestion();

    cout << "Total Score = " << Total
         << "out of 100" << endl;


    if (Total >= 70) {
        cout << "Congrats you passed the"
             << " quiz!" << endl;
    }

    else {
        cout << "You failed the quiz."
             << endl;
        cout << "Better luck next time."
             << endl;
    }
    int nLines = CountLinesInFile("table.txt");
    string filename = "table.txt";
    string s = Name + " " + to_string(Total);
    bool a=InsertStringToFile(filename, s, nLines);
    string* lines = nullptr;
    int count = GetStringsFromFileS("table.txt", &lines);
    cout << "best players" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << lines[i] << endl;
    }
    return 0;
}

void Question::setValues(
        string q, string a1,
        string a2, string a3,
        string a4, int ca, int pa)
{
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

void Question::askQuestion()
{
    cout << endl;

    cout << Question_Text << endl;
    cout << "1. " << Answer_1 << endl;
    cout << "2. " << Answer_2 << endl;
    cout << "3. " << Answer_3 << endl;
    cout << "4. " << Answer_4 << endl;
    cout << endl;

    cout << "What is your answer?(in number)"
         << endl;
    cin >> Guess;

    if (Guess == Correct_Answer) {
        cout << endl;
        cout << "Correct !" << endl;

        Total = Total + Question_Score;
        cout << "Score = " << Question_Score
             << " out of "
             << Question_Score
             << "!" << endl;
        cout << endl;
    }

    else {
        cout << endl;
        cout << "Wrong !" << endl;
        cout << "Score = 0"
             << " out of "
             << Question_Score
             << "!" << endl;
        cout << "Correct answer = "
             << Correct_Answer
             << "." << endl;
        cout << endl;
    }
}