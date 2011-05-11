#include <stdint.h>

BEGIN_STRUCT(tenant)
	STRUCT_ELEMENT(uint16_t, Left)
	STRUCT_ELEMENT(uint16_t, Right)
	STRUCT_ELEMENT(int8_t, Tenant Type)
	STRUCT_ELEMENT(uint8_t, Status)
	STRUCT_ELEMENT(uint16_t, Per Type Index)
	STRUCT_ELEMENT(uint32_t, People Offset)
	STRUCT_ELEMENT(int8_t, Index in Floor)
	UNKNOWN_DATA(uint8_t, 3)
	STRUCT_ELEMENT(int8_t, Rent Class)
	UNKNOWN_DATA(uint8_t, 1)
END_STRUCT(tenant)

BEGIN_STRUCT(floor)
	NAMED_STRUCT_ELEMENT(uint16_t, num, Number)
#ifdef OUTPUT_STRUCT
	if (num == 0) important = 0;
#endif
	STRUCT_ELEMENT(uint16_t, Left)
	STRUCT_ELEMENT(uint16_t, Right)
	STRUCT_ELEMENT_STRUCT_ARRAY(tenant, num, Tenant)
	STRUCT_ELEMENT_ARRAY(uint16_t, 94, Index mapping)
END_STRUCT(floor)

BEGIN_STRUCT(person)
	NAMED_STRUCT_ELEMENT(uint8_t, floor, Tenant Floor)
#ifdef OUTPUT_STRUCT
	if (floor == 0) important = 0;
#endif
	STRUCT_ELEMENT(uint8_t, Tenant Floor Index)
	STRUCT_ELEMENT(uint16_t, Index in Tenant)
	STRUCT_ELEMENT(uint8_t, Tenant Type)
	STRUCT_ELEMENT(uint8_t, Status)
	STRUCT_ELEMENT(int8_t, Current Floor)
	UNKNOWN_DATA(uint8_t, 5)
	STRUCT_ELEMENT(uint16_t, Stress)
	STRUCT_ELEMENT(uint16_t, Eval)
END_STRUCT(person)

BEGIN_STRUCT(retail)
	NAMED_STRUCT_ELEMENT(int8_t, floor, Floor)
#ifdef OUTPUT_STRUCT
	if (floor < 0) important = 0;
#endif
	UNKNOWN_DATA(uint8_t, 10)
	STRUCT_ELEMENT(uint8_t, Type)
	UNKNOWN_DATA(uint8_t, 6)
END_STRUCT(retail)

BEGIN_STRUCT(file)
	STRUCT_ELEMENT(uint16_t, Level)
	STRUCT_ELEMENT(int32_t, Current Balance)
	STRUCT_ELEMENT(int32_t, Other Income)
	STRUCT_ELEMENT(int32_t, Construction Costs)
	STRUCT_ELEMENT(int32_t, Last Quarter Money)
	STRUCT_ELEMENT(uint16_t, Frame Time)
	STRUCT_ELEMENT(int32_t, Current Day)
	UNKNOWN_DATA(uint16_t, 6)
	STRUCT_ELEMENT(uint16_t, Screen X)
	STRUCT_ELEMENT(uint16_t, Screen Y)
	UNKNOWN_DATA(uint8_t, 518)
	STRUCT_ELEMENT_STRUCT_ARRAY(floor, 120, Floor)
	NAMED_STRUCT_ELEMENT(uint32_t, peopleCount, Number of People)
	STRUCT_ELEMENT_STRUCT_ARRAY(person, peopleCount, Person)
	STRUCT_ELEMENT_STRUCT_ARRAY(retail, 512, Retail)
END_STRUCT(file)
