#include <fstream> 
#include <iostream>

using namespace std;


int main() {
    setlocale(0, "");
    ifstream text("text.txt");
    ifstream inp("input.txt");
    fstream result("result.txt");
    string word_in_text;//����� �� �������
    string array_word[10];//������ �������� ����
    short len_mas_word;//������� ��� ���������� ����������� ���������� ���� � �������� ����
    inp >> len_mas_word;
    int cnt = 0;
    cin >> word_in_text;// ��� ������ ������ ��������� � �������, ��� ������ ������� �� ���������� <Winsows.h>
    bool flag = true;
    ////�������� ����� �� ����� input.txt
    while (!text.eof())//���������� �� ����� �����
    {
        text >> word_in_text;//���������� ����� �� ����� text.txt
        int start_pos = -1, end_pos = -1;
        flag = true;
        for (int i = 0; i < word_in_text.length(); i++)
        {
            if (start_pos == -1 && isdigit(word_in_text[i]))
            {
                for (int j = 0; j < word_in_text.length(); j++)
                {
                    if (!isdigit(word_in_text[j]))
                        flag = false;
                    else
                        end_pos = j;
                }
                if (flag)
                {
                    start_pos = i;
                    break;
                }
            }
            if (start_pos == -1 && (isalpha((unsigned char)word_in_text[i]) || isdigit((unsigned char)word_in_text[i])))
            {

                start_pos = i;
            }
            if (start_pos != -1 && isalpha((unsigned char)word_in_text[i]))
            {
                end_pos = i;
            }
        }
        string new_str_for_word;
        for (int i = start_pos; i <= end_pos; i++)
        {
            new_str_for_word += tolower(word_in_text[i]);
        }
        flag = true;
        //    // �������� ���� �� ������������� ����� � ����� ���� �� �� �� ����� ��� �����
        for (int i = 0; i < new_str_for_word.length() - 1; i++)
        {
            for (int j = i + 1; j < new_str_for_word.length(); j++)
            {
                if (new_str_for_word[i] == new_str_for_word[j])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)break;
        }
        word_in_text = new_str_for_word;
        if (!flag) continue;
        //���� ������ ������ �������, �� ��������� �� ��������� �� ����� � ��� �����������
        if (flag)
        {
            for (short i = 0; i < 10; i++)
            {
                if (word_in_text == array_word[i])//��������� ���� �� ����� �� ���������
                {
                    flag = false;
                    break;
                }
            }
        }
        //���� ������ ��� ����������, ��������� ����� � ������
        if (flag)
        {
            int min_len_str = INT_MAX, min_index_str;
            cnt++;
            //��������� �����, ���� ��� ������ ������ ����������� ������ ����� � �������
            for (int i = 0; i < 10; i++)
            {
                if (min_len_str > array_word[i].length())
                {
                    min_len_str = array_word[i].length();
                    min_index_str = i;
                }
            }
            if (min_len_str < word_in_text.length())
                array_word[min_index_str] = word_in_text;
        }
    }
    ////���������� ������������� �������
    for (short i = 0; i < len_mas_word; i++)
    {
        for (short j = i + 1; j < len_mas_word; j++)
        {
            if (array_word[i].length() > array_word[j].length())
                swap(array_word[i], array_word[j]);
        }
    }
    ////���� ���������� ����
    for (int i = 0; i < cnt; i++)
    {
        result << array_word[i] << " ";
        cout << array_word[i] << " ";
    }
    ////����� ���� ����
    cout << endl;
    for (int i = 0; i < cnt; i++)
        cout << "<" << array_word[i] << ">" << std::endl;
}
