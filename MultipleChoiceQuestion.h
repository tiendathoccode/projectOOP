#pragma once
#include "BaseQuestion.h" 
#include <iostream>
#include <string>

using namespace std;

class MultipleChoiceQuestion : public BaseQuestion 
{
private:
    string options[4];
    int correctIndex;

public:
    MultipleChoiceQuestion(int id, string content, string opts[4], int correct)
        : BaseQuestion(id, content)// gôi ham tao cua BaseQuestion
    {
        this->correctIndex = correct;
        for (int i = 0; i < 4; ++i) 
        {
            this->options[i] = opts[i];
        }
    }

    //Override các ham ao
    void display() const override 
    {
        cout << "Câu " << id << ": " << content << endl;
        char optionChar = 'A';
        for (int i = 0; i < 4; ++i) 
        {
            cout << "  " << optionChar << ". " << options[i] << endl;
            optionChar++;
        }
    }

    bool checkAnswer(int option) const override 
    {
        return option == correctIndex;
    }
};