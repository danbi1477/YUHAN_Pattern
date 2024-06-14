#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	int count = 0;

	chrono::steady_clock::time_point prev_start = chrono::steady_clock::now();

	//여기서 함께 정의해주니까 밑에서 다시 쓸 필요 없음
	//밑에서 시작을 해도 코드의 밑부분에 있으니까 while이 들어가기 전 시작 시간을 세야함
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	chrono::steady_clock::time_point end;

	while (count<100)
	{
		//시작시간
		//chrono::steady_clock::time_point start = chrono::steady_clock::now();
		
		//스레드를 사용하는 대표적 사례 -> sleep
		//this_thread::sleep_for(chrono::seconds(1));
		
		count++;
		std::cout << "카운트 : " << count << std::endl;

		//끝난 시간
		//chrono::steady_clock::time_point end = chrono::steady_clock::now();
		
		//std::cout << "실제시간 : " << chrono::duration_cast<chrono::milliseconds>(difl).count() << std::endl;
		//이걸 하는 이유가 sleep 1초로 해도 딱 1초인지 알기 위해
		//결과적으로 아님 1015 1008 이렇게 몇 밀리세컨씩 오차가 발생함


		//이제 모르겠다 
		prev_start =end;
		end = chrono::steady_clock::now();
		//start = end;
		//prev_start = end 하고 start = end 지워도 됌.
		chrono::steady_clock::duration difl = end - prev_start;
		//여까지 시간을 잼

		int duration_ms = chrono::duration_cast<chrono::milliseconds>(difl).count();
		
		//duration_ms < 1000이라면 넘긴 시간만큼 뺴줘야함.
		
		if(duration_ms < 1000)
			this_thread::sleep_for(chrono::milliseconds(1000 - duration_ms));
		//갸ㅐ졸
		
		
	}
}