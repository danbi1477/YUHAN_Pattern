#include <iostream>
using namespace std;

enum ForeColour
{
    WHITE = 1,          // ���
    RED = 10,           // ������
    GREEN = 100,        // �ʷϻ�
    YELLOW = 1000,      // ���
    CYAN = 10000,       // û�ϻ�
    MAGENTA = 100000,   // ����Ÿ��
};

int main()
{

    string name;
    int num;

    cout << "ȭ�鿡 ����� ����� �ڵ��Դϴ�." << endl;
    cout << "�й� : ";
    cin >> num;
    cout << "�̸� : ";
    cin >> name;

    int code = 0;

    while (true) { 
        cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ���!" << endl;
        cout << "1000000�� �Է��ϸ� ����!" << endl;
        cin >> code;

        if (code == 1) {
            cout << "\x1b[37m" << "[��]" << endl;
        }
        else if (code == 10) {
            cout << "\x1b[31m" << "[��]" << endl;
        }
        else if (code == 100) {
            cout << "\x1b[32m" << "[��]" << endl; 
        }
        else if (code == 1000) {
            cout << "\x1b[33m" << "[��]" << endl; 
        }
        else if (code == 10000) {
            cout << "\x1b[36m" << "[û]" << endl; 
        }
        else if (code == 100000) {
            cout << "\x1b[35m" << "[��]" << endl; 
        }
        else if (code == 1000000) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "��ȿ���� ���� ��ü�ڵ��Դϴ�." << endl;
        }
    }
    return 0;
}