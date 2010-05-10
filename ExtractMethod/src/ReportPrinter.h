
#pragma once

#include <string>


class ReportPrinter
{
public:
	virtual			~ReportPrinter() = 0;
	virtual	void	print(const std::string& text) = 0;
};