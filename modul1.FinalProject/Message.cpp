#include "Message.h"

Message::Message(std::string to, std::string from, std::string text) :_to(to), _from(from), _text(text)
{
}

std::string Message::getTo() const
{
	return _to;
}

std::string Message::getFrom() const
{
	return _from;
}

std::string Message::getText() const
{
	return _text;
}