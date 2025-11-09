#pragma once
#include <iostream>
#include <string>
#include <sstream> 

#include "BaseQuestion.h"
#include "AnswerRecord.h"
#include "User.h"
#include "Result.h"

using namespace std;

class ViewDisplay
{
public:
    ViewDisplay() {}

    //hien thi chao mung, HDSD
    void displayWelcome() {
        cout << "--------------------------------------------" << endl;
        cout << "\t CHUONG TRINH THI TRAC NGHIEM" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " NOTE: Ban co the chon tra loi hoac skip sang cau tiep theo" << endl;
        cout << " Cac lua chon:" << endl;
        cout << " N (Next): Chuyen sang cau tiep theo." << endl;
        cout << " P(Previous): Quay lai cau hoi truoc do." << endl;
        cout << " S(Skip): Danh dau cau hien tai va tra loi sau." << endl;
        cout << " J(Jump): Cho phep chuyen den cau hoi co so thu tu bat ki." << endl;
        cout << " A / B / C / D (Chon dap an)." << endl;
        cout << " Q(Submit): Nop bai thi." << endl;
        cout << " Chuc ban hoan thanh tot bai trac nghiem!" << endl;
        cout << "--------------------------------------------" << endl;
    }

    //so cau ht, tong , thoi gian con lai
    //current: cau hoi ht
    //total: tong so cau trong bai
    //tiemLeft: thoi gian con lai
    void displayHeader(int current, int total, int timeLeft) {
        int minutes = timeLeft / 60; // phut
        int seconds = timeLeft % 60; // giay

        string minStr = (minutes < 10 ? "0" : "") + to_string(minutes);
        string secStr = (seconds < 10 ? "0" : "") + to_string(seconds);

        cout << "Cau " << current + 1 << "\t" << total
            << " | \t Thoi gian con lai: "
            << minStr << ":" << secStr << endl;
    }

    // hien thi cau hoi
    void displayQuestion(const BaseQuestion& question) {
        question.display();
    }

    // trang thai cau hoi hien tai
    void displayQuestionStatus(const AnswerRecord& record) {
        // skip
        if (record.isSkipped()) {
            cout << "Trang thai: Da skip" << std::endl;
        }
        // tra loi
        else if (record.isAnswer()) {
            char choice = 'A' + record.getAnswer();
            cout << "Trang thai: Da tra loi (" << choice << ")" << std::endl;
        }
        // chua chon
        else {
            cout << "Trang thai: Chua tra loi" << std::endl;
        }
    }

    // ket qua cuoi cung
    void displayResult(const User& user, const Result<double>& result, const string& startTime, const string& totalTime) {
        cout << "--------------------------------------------" << endl;
        cout << "\t KET QUA BAI THI" << endl;
        cout << "Ho ten: " << user.getName() << endl;
        cout << "Ma sinh vien: " << user.getID() << endl;
        cout << "Thoi gian bat dau: " << startTime << endl;
        cout << "Tong thoi gian lam bai: " << totalTime << endl;
        result.display();
        cout << "--------------------------------------------" << endl;
    }

    // hien thi chon thao tac
    void displayMenu() {
        cout << "Lua chon: N (Next), P (Previous), S (Skip), J (Jump), A/B/C/D (Chon dap an), Q (Submit)" << endl;
    }

    // nhac nho huong dan nguoi dung nhap
    void displayPrompt(const string& message) {
        cout << message;
    }

    // thong bao loi
    void displayError(const string& error) {
        cout << "\033[31m" << error << "\033[0m" << endl;
    }
};


