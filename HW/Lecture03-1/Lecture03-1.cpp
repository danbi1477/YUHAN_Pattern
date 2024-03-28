#include <iostream>
using namespace std;

enum ForeColor 
{
    WHITE = 37,           // 흰색
    RED = 31,             // 빨강색
    GREEN = 32,           // 초록색
    YELLOW = 33,          // 노랑
    CYAN = 36,           // 청록색
    MAGENTA = 35        // 마젠타색
};

void drawBlock(ForeColor color) {
    cout << "\x1b[" << color << "m[블록]\x1b[0m " << endl;
}

int main()
{   cout << "화면에 블록을 만드는 코드입니다." << endl;
    cout << "학번 : 202327071" << endl;
    cout << "이름 : 노단비" << endl;

    int code = 0;

    while (true) { 
        cout << "화면에 그릴 물체코드를 입력하세요!" << endl;
        cout << "64을 입력하면 종료!" << endl;
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
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "유효하지 않은 물체코드입니다." << endl;
        }
    }
    return 0;
}
