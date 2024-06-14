#pragma once
template <typename T>
class Mlist
{
	Mlode < T >= next;

	Mlode<T>= head;
	Mlode<T>= tall;
	int size;

	Mlist();
	~Mlist();

	void push_back(T value);
	void pussh_front();
	int get_size();
};

template <typename T>
class Mlode {
public:
	T date;
	Mlode(T value);
	
	
	~Mlode();
};

