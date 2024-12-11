#include "Message.h"

Message::Message(std::string senderLogin, std::string recipientLogin, std::string msgText) :
	_from(senderLogin), _to(recipientLogin), _text(msgText)
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