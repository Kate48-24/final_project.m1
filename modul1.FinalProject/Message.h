#pragma once
#include "User.h"

class Message
{
public:
	Message(std::string to, std::string from, std::string text);

	std::string getTo() const;
	std::string getFrom() const;
	std::string getText() const;

private:
	std::string _to;
	std::string _from;
	std::string _text;
};
