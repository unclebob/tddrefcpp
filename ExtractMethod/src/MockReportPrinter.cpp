
#include "MockReportPrinter.h"


std::string MockReportPrinter::getText() const
{
	return printedText;
}


void MockReportPrinter::print(const std::string& text)
{
	printedText += text;
}