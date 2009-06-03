#include "Exceptions.h"

#include <sstream>

using namespace lima;
using namespace std;

Exception::Exception(Layer layer, ErrorType err_type, String err_desc,
		     String file_name, String funct_name, int line_nr)
	: m_layer(layer), m_err_type(err_type), m_err_desc(err_desc),
	  m_file_name(file_name), m_funct_name(funct_name), m_line_nr(line_nr)
{
}


Exception::String Exception::getErrMsg() const
{
	ostringstream os;
	os << m_layer << ": " 
	   << m_funct_name  << "(" << m_file_name << ", " 
	   << m_line_nr << "): " 
	   << m_err_type << ": " << m_err_desc;
	return os.str();
}

std::ostream& lima::operator <<(std::ostream& os, Layer layer)
{
	string name = "Unknown";
	switch (layer) {
	case Common:	name = "Common";	break;
	case Control:	name = "Control";	break;
	case Hardware:	name = "Hardware";	break;
	}
	return os << name;
}

std::ostream& lima::operator <<(std::ostream& os, ErrorType err_type)
{
	string name = "Unknown";
	switch (err_type) {
	case InvalidValue:	name = "InvalidValue";	break;
	case NotSupported:	name = "NotSupported";	break;
	case Error:		name = "Error";		break;
	}
	return os << name;
}

std::ostream& lima::operator <<(std::ostream& os, const Exception& e)
{
	return os << e.getErrMsg();
}
