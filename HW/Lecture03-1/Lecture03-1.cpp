#include <iostream>
using namespace std;

enum ForeColor 
{
    WHITE = 37,           // ���
    RED = 31,             // ������
    GREEN = 32,           // �ʷϻ�
    YELLOW = 33,          // ���
    CYAN = 36,           // û�ϻ�
    MAGENTA = 35        // ����Ÿ��
};

void drawBlock(ForeColor color) {
    cout << "\x1b[" << color << "m[���]\x1b[0m " << endl;
}

int main()
{   cout << "ȭ�鿡 ����� ����� �ڵ��Դϴ�." << endl;
    cout << "�й� : 202327071" << endl;
    cout << "�̸� : ��ܺ�" << endl;

    int code = 0;

    while (true) { 
        cout << "ȭ�鿡 �׸� ��ü�ڵ带 �Է��ϼ���!" << endl;
        cout << "64�� �Է��ϸ� ����!" << endl;
        cin >> code;

        if (code == 1) {
            drawBlock(WHITE);
        }
        else if (code == 2) {
            drawBlock(RED);
        }
        else if (code == 4) {
            drawBlock(GREEN);
        }
        else if (code == 8) {
            drawBlock(YELLOW);
        }
        else if (code == 16) {
            drawBlock(CYAN);
        }
        else if (code == 32) {
            drawBlock(MAGENTA);
        }
        else if (code == 64) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
        else {
            cout << "��ȿ���� ���� ��ü�ڵ��Դϴ�." << endl;
        }
    }
    return 0;
}
