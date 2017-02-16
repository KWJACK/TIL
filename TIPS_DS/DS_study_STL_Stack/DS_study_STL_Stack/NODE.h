#pragma once
class NODE
{
private:
	int m_data;
	NODE* p_next;
public:
	NODE() :m_data(0), p_next(nullptr) {}
	NODE(int data) : m_data(data), p_next(nullptr) {}
	~NODE() {}
	void setData(int data) { m_data = data; }
	void setNext(NODE* next) { p_next = next; }

	int getData() { return m_data; }
	NODE* getNext() { return p_next; }
};
