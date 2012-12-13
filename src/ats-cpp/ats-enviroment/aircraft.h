#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <string>
#include <vector>

#include "coordinate.h"
#include "stretch.h"
#include "typedefs.h"

namespace ats {
namespace enviroment {

class Aircraft {
    public:
        Aircraft();
        virtual ~Aircraft();

        void setName(std::string name);
        std::string getName();
        void removeStretchAt(int index);
        void setStretchLimitTime(const int index, const UnitTime limitTime);
        UnitTime getStretchLimitTime(const int index) const;
        void setStretchHeading(const int index, const UnitAngle heading);
        UnitAngle getStretchHeading(const int index) const;
        void setStretchSpeed(const int index, const UnitVelocity speed);
        UnitVelocity getStretchSpeed(const int index) const;
        void setStretchInitHeight(const int index, const UnitLength height);
        UnitLength getStretchInitHeight(const int index) const;
        int countStretchs() const;
        bool isFlying(UnitTime time);
        Coordinate evolve(UnitTime time);

    private:
        std::string name;
        std::vector<Stretch> stretchs;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFT_H_ */
