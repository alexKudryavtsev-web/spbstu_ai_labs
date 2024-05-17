+ACM-include +ADw-iostream+AD4-
+ACM-include +ADw-string.h+AD4-
+ACM-include +ADw-vector+AD4-
+ACM-include +ADw-string+AD4-

using namespace std+ADs-

class MyString
+AHs-
public:
	MyString(const string+ACY- str)
	+AHs-
		this-+AD4-str +AD0- str+ADs-
		cout +ADwAPA- +ACIEGgQ+BD0EQQRCBEAEQwQ6BEIEPgRA- +ACI- +ADwAPA- this +ADwAPA- endl+ADs-
	+AH0-

	MyString(const vector+ADw-string+AD4AJg- strs) +AHs-
		cout +ADwAPA- +ACIEGgQ+BD0EQQRCBEAEQwQ6BEIEPgRA- +BDQEOwRP- 9 +BDcEMAQ0BDAEPQQ4BE8- +ACI- +ADwAPA- this +ADwAPA- endl+ADs-
		for (const auto+ACY- str : strs) +AHs-
			this-+AD4-str +-+AD0- str+ADs-
		+AH0-
	+AH0-

	MyString() +AHs-
		cout +ADwAPA- +ACIEEQQwBDcEPgQyBEsEOQ- +BBoEPgQ9BEEEQgRABEMEOgRCBD4EQA- +ACI- +ADwAPA- this +ADwAPA- endl+ADs- 
	+AH0AOw-


	MyString(const MyString+ACY- other) +AHs-
		cout +ADwAPA- +ACIEGgQ+BD0EQQRCBEAEQwQ6BEIEPgRA- +BDoEPgQ/BDgEQAQ+BDIEMAQ9BDgETw- +ACI- +ADwAPA- this +ADwAPA- endl+ADs-
		this-+AD4-str +AD0- other.str+ADs-
	+AH0-

	MyString+ACY- operator+AD0-(const MyString+ACY- other) +AHs-
		cout +ADwAPA- +ACIEHgQ/BDUEQAQwBEIEPgRA- +BD8EQAQ4BEEEMgQwBDgEMgQwBD0EOARP- +ACI- +ADwAPA- this +ADwAPA- endl+ADs-
		this-+AD4-str +AD0- other.str+ADs-
		return +ACo-this+ADs-
	+AH0-

	string getStr() +AHs-
		return str+ADs-
	+AH0-

	void setStr(string str)	+AHs-
		this-+AD4-str +AD0- str+ADs-
	+AH0-

	void print() +AHs-
		cout +ADwAPA- str +ADwAPA- endl+ADs-
	+AH0-

	+AH4-MyString() +AHs-
		cout +ADwAPA- +ACIEFAQ1BEEEQgRABEMEOgRCBD4EQA- +ACI- +ADwAPA- this +ADwAPA- endl+ADs-
	+AH0-

private:
	string str+ADs-

+AH0AOw-
