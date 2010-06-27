#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace ytk {
	class Exception{
	protected:
		std::string msg;
	public:
		Exception(){}
		Exception(std::string m){msg = m;}
		std::string what(){return msg;}
	};

	class SqlException : public Exception{
	public:
		SqlException(){}
		SqlException(std::string m) : Exception(m){}
	};
}

#endif //EXCEPTION_H