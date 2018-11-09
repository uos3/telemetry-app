#include "utility.h"

#include <ctime>

uint32_t util::now () {
	time_t t_now = time(nullptr);
	return static_cast<uint32_t>(mktime(gmtime(&t_now)));
}

std::string util::time_string (uint32_t tstamp) {
	time_t t = static_cast<time_t>(tstamp);
	tm* st = gmtime(&t);
	char s[22];
	strftime(s, 22, "%F %T", st);
	return std::string(s);
}
