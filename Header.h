#pragma once
#include<iostream>
using namespace std;
class Timer
{
	int m_hour;
	int m_min;
	int m_sec;
public:
	Timer() :Timer(0, 0, 0) {}
	Timer(int sec) :Timer(0,0,sec){}
	Timer(int min,int sec) :Timer(0,min,sec){}
	Timer(int hour ,int min, int sec) 
	{
		
		m_hour = hour;
		m_min = min;
		m_sec = sec;	
		this->convertToTrue();

	}

	inline int getHour();
	inline int getMin();
	inline int getSec();
	void setData(int h,int m,int s);
	void convertToTrue();
	int convertToSec();
	void printTo24();
	void printTo12();

	Timer operator+(Timer b);
	Timer operator+(int b);//прибавляем в секундах
	Timer operator+=(Timer b);
	Timer operator-(Timer b);
	Timer operator-(int b);//отнимаем в секундах
	Timer operator-=(Timer b);
	Timer operator*(Timer b);
	Timer operator*(int b);
	Timer operator*=(Timer b);
	bool operator>(Timer b);
	bool operator<(Timer b);
	bool operator<=(Timer b);
	bool operator>=(Timer b);
	bool operator==(Timer b);
	bool operator!=(Timer b);
	~Timer();

private:

};



inline int Timer::getHour()
{
	return m_hour;
}

inline int Timer::getMin()
{
	return m_min;
}

inline int Timer::getSec()
{
	return m_sec;
}

inline void Timer::setData(int h, int m, int s)
{
	
	m_hour = h;
	m_min = m;
	m_sec = s;
	this->convertToTrue();
}

inline void Timer::convertToTrue()
{
	if (m_hour < 0)
	{
		m_hour = 0;
	}
	if (m_min < 0)
	{
		m_min = 0;
	}
	if (m_sec < 0)
	{
		m_sec = 0;
	}


	if (m_sec >= 60)
	{
		m_min = m_min + (m_sec / 60);
		m_sec = m_sec % 60;
	}
	if (m_min >= 60)
	{
		m_hour = m_hour + (m_min / 60);
		m_min = m_min % 60;
	}
	if (m_hour >= 24)
	{
		m_hour = m_hour % 24;
	}
}

inline int Timer::convertToSec()
{
	int ss;
	ss = (this->m_hour * 60 * 60) + (this->m_min * 60) + (this->m_sec);
	return ss;
}

inline void Timer::printTo24()
{
	cout << m_hour << "часов," << m_min << " минут," << m_sec << " секунд"   << endl;
}

inline void Timer::printTo12()
{
	if (m_hour<12)
	{
		cout  << m_hour << "часов," << m_min << " минут," << m_sec<<" секунд||" << " AM" << endl;
	}
	else
	{
		cout << m_hour%12 << " часов," << m_min << " минут," << m_sec << " секунд||" << " PM" << endl;
	}
	
}

inline Timer Timer::operator+(Timer b)
{
	Timer c;
	c.m_hour = b.m_hour + this->m_hour;
	c.m_min = b.m_min + this->m_min;
	c.m_sec = b.m_sec + this->m_sec;
	c.convertToTrue();
	return c;
}

inline Timer Timer::operator+(int b)
{
	this->m_sec = this->m_sec + b;
	this->convertToTrue();
	return *this;
}

inline Timer Timer::operator+=(Timer b)
{
	*this = *this + b;
	this->convertToTrue();
	return *this;
}

inline Timer Timer::operator-(Timer b)
{

	Timer c(this->convertToSec()- b.convertToSec());
	c.convertToTrue();
	return c;
}

inline Timer Timer::operator-(int b)
{
	Timer c(this->convertToSec() - b);
	c.convertToTrue();
	return c;
}

inline Timer Timer::operator-=(Timer b)
{
	*this = *this - b;
	this->convertToTrue();
	return *this;
}

inline Timer Timer::operator*(Timer b)
{
	Timer c(this->convertToSec()* b.convertToSec());
	c.convertToTrue();
	return c;
}

inline Timer Timer::operator*(int b)
{
	
	*this=this->convertToSec()*b;
	this->convertToTrue();
	return *this;
}

inline Timer Timer::operator*=(Timer b)
{
	*this = *this * b;
	this->convertToTrue();
	return *this;
}

inline bool Timer::operator>(Timer b)
{
	bool res = (this->convertToSec() > b.convertToSec());
	return res;
}
inline bool Timer::operator<(Timer b)
{
	bool res = (this->convertToSec() < b.convertToSec());
	return res;
}
inline bool Timer::operator>=(Timer b)
{
	bool res = (this->convertToSec() >=b.convertToSec());
	return res;
}
inline bool Timer::operator<=(Timer b)
{
	bool res = (this->convertToSec() <= b.convertToSec());
	return res;
}
inline bool Timer::operator==(Timer b)
{
	bool res = (this->convertToSec() == b.convertToSec());
	return res;
}
inline bool Timer::operator!=(Timer b)
{
	bool res = (this->convertToSec() != b.convertToSec());
	return res;
}







inline Timer::~Timer()
{

}
