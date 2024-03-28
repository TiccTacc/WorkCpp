#include "StandHeader.h"
#pragma once
using namespace std;

class Time
{
private:
	int hours, minutes, seconds;
	bool AMPM, pm;
	//void CheckingThePeriod(int H, int m, int s);
public:
	
	Time();
	Time(int H, int m, int s, bool pAMPM, bool p_pm);
	
	Time operator+(Time& timeAdd);
	Time operator-(Time& timeSub);
	Time operator+= (Time& timeAdd);
	Time operator-= (Time& timeSub);

	bool operator<(Time& timeMore);
	bool operator>(Time& timeLess);
	bool operator==(Time& timeComp); // comparison
	bool operator!=(Time& timeIneq); // inequality

	friend ostream& operator<<(ostream& stringOut, const Time& timeOut);
	friend istream& operator>>(istream& stream, Time& timeIn);

	void convertateToAMPMformat();
	void convertateToStandatformat();
	bool getPM();

};

Time::Time()
{
	hours = minutes = seconds = 0;
	AMPM = pm = false;
}
Time::Time(int H, int m, int s, bool pAMPM, bool p_pm)
{
	//CheckingThePeriod(H, m, s);

	hours = H;
	minutes = m;
	seconds = s;
	AMPM = pAMPM;
	pm = p_pm;
	
	
}


/* Математические функции */
Time Time::operator+(Time& timeAdd) {
	
	Time Result = *new Time();
	bool oneAMPM = false, 
		twoAMPM = false;
	int optMinutes = 0,
		optHours = 0;

	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeAdd.AMPM) {
		timeAdd.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	/* Сложение времени */
	Result.seconds = seconds + timeAdd.seconds;
	if (Result.seconds >= 60) {
		optMinutes += 1;
		Result.seconds -= 60;
	}

	Result.minutes = minutes + timeAdd.minutes + optMinutes;
	if (Result.minutes >= 60) {
		optHours += 1;
		Result.minutes -= 60;
	}

	Result.hours = hours + timeAdd.hours + optHours;
	if (Result.hours >= 24)
	{
		Result.hours %= 24;
	}

	if (twoAMPM) 
		timeAdd.convertateToAMPMformat();

	if (oneAMPM)
		convertateToAMPMformat();

	if (oneAMPM and twoAMPM)
		Result.convertateToAMPMformat();

	return Result;
}
Time Time::operator-(Time& timeSub) {
	
	Time result = *new Time();
	bool oneAMPM, subAMPM = false;
	int optMinutes, optHours = 0;

	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeSub.AMPM) {
		timeSub.convertateToStandatformat();
		subAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	result.seconds = seconds - timeSub.seconds;
	if (result.seconds < 0) {
		result.seconds += 60;
		optMinutes = 1;
	}
	result.minutes = (minutes - optMinutes) - timeSub.minutes;
	if (result.minutes < 0) {
		result.minutes += 60;
		optHours = 1;
	}
	result.hours = (hours - optHours) - timeSub.hours;
	if (result.hours < 0){
		result.hours %= 24;
	}

	if (oneAMPM)
		convertateToAMPMformat();
	if (subAMPM)
		timeSub.convertateToAMPMformat();

	if (oneAMPM and subAMPM)
		result.convertateToAMPMformat();

	return result;
}

/* Сравнение */
bool Time::operator<(Time& timeMore) {
	
	bool oneAMPM, twoAMPM = false;
	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeMore.AMPM) {
		timeMore.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	bool MoreTime = false;
	if (hours < timeMore.hours) {
		MoreTime = true;
	}
	else if (hours == timeMore.hours) {
		if (minutes < timeMore.minutes) {
			MoreTime = true;
		}
		else if (hours == timeMore.hours) {
			if (seconds < timeMore.seconds) { 
				MoreTime = true; 
			}
		}
	}

	if (oneAMPM)
		convertateToAMPMformat();
	if (twoAMPM)
		timeMore.convertateToAMPMformat();

	return MoreTime;
}
bool Time::operator>(Time& timeLess) {
	
	bool oneAMPM, twoAMPM = false;
	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeLess.AMPM) {
		timeLess.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	bool LessTime = false;
	if (hours > timeLess.hours) {
		LessTime = true;
	}
	else if (hours == timeLess.hours) {
		if (minutes > timeLess.minutes) {
			LessTime = true;
		}
		else if (hours == timeLess.hours) {
			if (seconds > timeLess.seconds) {
				LessTime = true;
			}
		}
	}

	if (oneAMPM)
		convertateToAMPMformat();
	if (twoAMPM)
		timeLess.convertateToAMPMformat();

	return LessTime;
}
bool Time::operator==(Time& timeComp) {
	
	bool oneAMPM, twoAMPM = false;
	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeComp.AMPM) {
		timeComp.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	bool comparison = false;
	if (hours == timeComp.hours and minutes == timeComp.minutes and seconds == timeComp.seconds)
		comparison = true;

	if (oneAMPM)
		convertateToAMPMformat();
	if (twoAMPM)
		timeComp.convertateToAMPMformat();

	return comparison;

}
bool Time::operator!=(Time& timeIneq) {

	bool oneAMPM, twoAMPM = false;
	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeIneq.AMPM) {
		timeIneq.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	bool inequality = true;
	if (hours == timeIneq.hours and minutes == timeIneq.minutes and seconds == timeIneq.seconds)
		inequality = false;

	if (oneAMPM)
		convertateToAMPMformat();
	if (twoAMPM)
		timeIneq.convertateToAMPMformat();

	return inequality;

}

/* Функции присваивания */
Time Time::operator+=(Time& timeAdd) {

	bool oneAMPM = false, 
		twoAMPM = false;
	int optMinutes = 0, 
		optHours = 0;

	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeAdd.AMPM) {
		timeAdd.convertateToStandatformat();
		twoAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	/* Сложение времени */
	seconds += timeAdd.seconds;
	if (seconds >= 60) {
		optMinutes += 1;
		seconds -= 60;
	}

	minutes += optMinutes + timeAdd.minutes;
	if (minutes >= 60) {
		optHours += 1;
		minutes -= 60;
	}

	hours = optHours + timeAdd.hours;
	if (hours >= 24)
	{
		hours %= 24;
	}

	if (twoAMPM)
		timeAdd.convertateToAMPMformat();

	if (oneAMPM)
		convertateToAMPMformat();

	return timeAdd;

}
Time Time::operator-=(Time& timeSub) {

	bool oneAMPM, subAMPM = false;
	int optMinutes, optHours = 0;

	if (AMPM) {
		convertateToStandatformat();
		oneAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}
	if (timeSub.AMPM) {
		timeSub.convertateToStandatformat();
		subAMPM = true; // Запоминаем формат, чтобы потом конвертировать данные обратно
	}

	seconds -= timeSub.seconds;
	if (seconds < 0) {
		seconds += 60;
		optMinutes = 1;
	}
	minutes -= optMinutes + timeSub.minutes;
	if (minutes < 0) {
		minutes += 60;
		optHours = 1;
	}
	hours -= optHours + timeSub.hours;
	if (hours < 0) {
		hours %= 24;
	}

	if (oneAMPM)
		convertateToAMPMformat();
	if (subAMPM)
		timeSub.convertateToAMPMformat();

	return timeSub;

}

/* Функции ввода и вывода*/
ostream& operator<<(std::ostream& stream, const Time& timeOut) {
	
	string stringOut = "";

	if (timeOut.hours < 10)
		stringOut += "0" + to_string(timeOut.hours) + ":";
	if (timeOut.minutes < 10)
		stringOut += "0" + to_string(timeOut.minutes) + ":";
	if (timeOut.seconds < 10)
		stringOut += "0" + to_string(timeOut.seconds);

	if (timeOut.AMPM) {
		if (timeOut.pm) {
			stringOut += " PM";
		}
		else {
			stringOut += " AM";
		}
	}
	stream << stringOut << endl;

	return stream;
}
istream& operator>>(std::istream& stream, Time& timeIn)
{
	stream >> timeIn.hours >> timeIn.minutes >> timeIn.seconds;
	
	if (timeIn.seconds > 60) {
		timeIn.minutes += (timeIn.seconds / 60);
		timeIn.seconds %= 60;
	}
	else if (timeIn.seconds < 0) {
		timeIn.seconds = 0;
	}
	if (timeIn.minutes > 60) {
		timeIn.hours += (timeIn.minutes / 60);
		timeIn.seconds %= 60;
	}
	else if (timeIn.minutes < 0) {
		timeIn.minutes = 0;
	}
	if (timeIn.hours > 24) {
		timeIn.hours %= 24;
	}
	else if (timeIn.hours < 0)
	{
		timeIn.hours = 0;
	}

	return stream;
}

/* Служебные функции */
void Time::convertateToAMPMformat() {
	
	if (!AMPM){
		AMPM = !AMPM;
		pm = hours > 12;
		if (hours > 12)
			hours = hours - 12;	
	}

}
void Time::convertateToStandatformat() {

	
	if (AMPM and pm) {
		hours = hours + 12;
	}
	AMPM = false;
}
bool Time::getPM() {
	return pm;
}
void CheckingThePeriod(int house, int minute, int second) {

	//int optMinutes = 0;
	if (second >= 60)
	{
		minute += second / 60;
		second %= 60;
	}
	//int opthouse = 0;
	if (minute >= 60) {
		house += minute / 60;
		minute %= 60;
	}
	if (house >= 24) {
		house %= 24;
	}
}