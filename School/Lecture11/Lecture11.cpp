#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	int count = 0;

	chrono::steady_clock::time_point prev_start = chrono::steady_clock::now();

	//���⼭ �Բ� �������ִϱ� �ؿ��� �ٽ� �� �ʿ� ����
	//�ؿ��� ������ �ص� �ڵ��� �غκп� �����ϱ� while�� ���� �� ���� �ð��� ������
	chrono::steady_clock::time_point start = chrono::steady_clock::now();
	chrono::steady_clock::time_point end;

	while (count<100)
	{
		//���۽ð�
		//chrono::steady_clock::time_point start = chrono::steady_clock::now();
		
		//�����带 ����ϴ� ��ǥ�� ��� -> sleep
		//this_thread::sleep_for(chrono::seconds(1));
		
		count++;
		std::cout << "ī��Ʈ : " << count << std::endl;

		//���� �ð�
		//chrono::steady_clock::time_point end = chrono::steady_clock::now();
		
		//std::cout << "�����ð� : " << chrono::duration_cast<chrono::milliseconds>(difl).count() << std::endl;
		//�̰� �ϴ� ������ sleep 1�ʷ� �ص� �� 1������ �˱� ����
		//��������� �ƴ� 1015 1008 �̷��� �� �и������� ������ �߻���


		//���� �𸣰ڴ� 
		prev_start =end;
		end = chrono::steady_clock::now();
		//start = end;
		//prev_start = end �ϰ� start = end ������ ��.
		chrono::steady_clock::duration difl = end - prev_start;
		//������ �ð��� ��

		int duration_ms = chrono::duration_cast<chrono::milliseconds>(difl).count();
		
		//duration_ms < 1000�̶�� �ѱ� �ð���ŭ �������.
		
		if(duration_ms < 1000)
			this_thread::sleep_for(chrono::milliseconds(1000 - duration_ms));
		//������
		
		
	}
}