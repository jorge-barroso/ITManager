#pragma db object
#include "odb\core.hxx"
class Instance
{
public:
	~Instance();
private:
	friend class odb::access;
	Instance() {}

	#pragma db id
	uint16_t id;
};

