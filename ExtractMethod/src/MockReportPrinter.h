

#pragma once

#include <string>


#include "ReportPrinter.h"

class MockReportPrinter : public ReportPrinter
{
public:
	std::string			getText() const;
	virtual	void		print(const std::string& text);

private:
	std::string			printedText;
};


