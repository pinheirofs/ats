#ifndef COORDINATE_H_
#define COORDINATE_H_

#include "typedefs.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class Coordinate {
public:
	Coordinate();
	Coordinate(UnitLength latitude, UnitLength longitude, UnitLength height);
	virtual ~Coordinate();

	UnitLength getLatitude() const;
	UnitLength getLongitude() const;
	UnitLength getHeight() const;

private:
	UnitLength latitude;
	UnitLength longitude;
	UnitLength height;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* COORDINATE_H_ */
