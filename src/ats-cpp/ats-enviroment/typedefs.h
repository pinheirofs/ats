#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/acceleration.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

namespace ats {
namespace enviroment {

typedef boost::units::quantity<boost::units::si::velocity> UnitVelocity;
typedef boost::units::quantity<boost::units::si::length> UnitLength;
typedef boost::units::quantity<boost::units::si::time> UnitTime;
typedef boost::units::quantity<boost::units::si::acceleration> UnitAcceleration;
typedef boost::units::quantity<boost::units::si::plane_angle> UnitAngle;



} /* namespace enviroment */
} /* namespace ats */

#endif /* TYPEDEFS_H_ */
