#include <iostream>
using namespace std;

enum ForeColour
{
    WHITE = 1,          // 흰색
    RED = 10,           // 빨강색
    GREEN = 100,        // 초록색
    YELLOW = 1000,      // 노랑
    CYAN = 10000,       // 청록색
    MAGENTA = 100000,   // 마젠타색
};

int main()
{

    string name;
    int num;

    cout << "화면에 블록을 만드는 코드입니다." << endl;
    cout << "학번 : ";
    cin >> num;
    cout << "이름 : ";
    cin >> name;

    int code = 0;

    while (true) { 
        cout << "화면에 그릴 물체코드를 입력하세요!" << endl;
        cout << "1000000을 입력하면 종료!" << endl;
        cin >> code;

        if (code == 1) {
            cout << "\x1b[37m" << "[흰]" << endl;
        }
        else if (code == 10) {
            cout << "\x1b[31m" << "[빨]" << endl;
        }
        else if (code == 100) {
            cout << "\x1b[32m" << "[녹]" << endl; 
        }
        else if (code == 1000) {
            cout << "\x1b[33m" << "[노]" << endl; 
        }
        else if (code == 10000) {
            cout << "\x1b[36m" << "[청]" << endl; 
        }
        else if (code == 100000) {
            cout << "\x1b[35m" << "[마]" << endl; 
        }
        else if (code == 1000000) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "유효하지 않은 물체코드입니다." << endl;
        }
    }
    return 0;
}