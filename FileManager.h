#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class MultipleChoiceQuestion
{
private:
    int id;
    string content;
    vector<string> options;
    int correctIndex;

public:
    MultipleChoiceQuestion(int _id, const string& _content, const vector<string>& _options, int _correct)
        : id(_id), content(_content), options(_options), correctIndex(_correct) {}
    
        int getID() const {return id;}
        string getContent() const {return content;}
        vector<string> getOptions() const {return options;}
        int getCorrectIndex() const {return correctIndex;}
};

class FileManager
{
public:
    static vector<MultipleChoiceQuestion*> loadQuestion(const string& filename)
    {
        vector<MultipleChoiceQuestion*> questions;
        ifstream file(filename);

        if(!file.is_open())
        {
            cerr << "Lỗi, không thể mở file" << filename << endl;
            return questions;
        }

        string line;
        int lineNumber = 0;

        while(getline(file, line))
        {
            lineNumber++;
            if(line.empty()) continue;

            stringstream ss(line);
            vector<string> tokens;
            string token;

            while(getline(ss, token, '|'))
            {
                tokens.push_back(token);
            }

            if(tokens.size() != 7)
            {
                cerr << "Lỗi, dòng" << lineNumber << "Có định dạng sai" << endl;
                continue;
            }

            try
            {
                 int id = stoi(tokens[0]);
                string content = tokens[1];
                vector<string> options = {tokens[2], tokens[3], tokens[4], tokens[5]};
                int correctIndex = stoi(tokens[6]);

                if(correctIndex < 0 || correctIndex > 3)
                {
                    cerr << "Lỗi. Đáp án không hợp lệ ở dòng" << lineNumber << endl;
                    continue;
                }

                questions.push_back(new MultipleChoiceQuestion(id, content, options, correctIndex));
            }
            catch (...)
            {
                cerr << "Lỗi. Không thể parse dữ liệu ở dòng" << lineNumber << endl;
                continue;
            }
        }

        file.close();
        cout << "Đã load" << questions.size() << "Câu hỏi từ file thành công" << endl;
        return questions;
    }

    static void saveResult(const string& filename, const string& studentName, const string& studentID, double score)
    {
        ofstream file(filename, ios::app);
        if(!file.is_open())
        {
            cerr << "Lỗi. Không thể mở file để ghi kết quả" << endl;
            return;
        }

        file << "Kết quả thi" << endl;
        file << "Họ tên" << studentName << endl;
        file << "Mã sinh viên" << studentID << endl;
        file << "Tổng điểm" << score << endl;
        file << "=====" << endl << endl;

        file.close();
        cout << "Đã lưu kết quả vào file" << filename << endl;
    }
};