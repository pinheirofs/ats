#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include <string>
#include <vector>

#include "coordinate.h"
#include "stretch.h"

namespace ats {
namespace enviroment {

/*
 *
 */
class Aircraft {
    public:
        Aircraft();
        virtual ~Aircraft();

        void setName(std::string name);
        std::string getName();
        void removeStretchAt(int index);
        void setStretchLimitTime_ms(const int index, const long limitTime_ms);
        long getStretchLimitTime_ms(const int index) const;
        void setStretchHeading_degrees(const int index, const double heading_degrees);
        double getStretchHeading_degrees(const int index) const;
        void setStretchSpeed_kt(const int index, const double speed_kt);
        double getStretchSpeed_kt(const int index) const;
        void setStretchHeight_ft(const int index, const double height_ft);
        double getStretchHeight_ft(const int index) const;
        int countStretchs() const;
        bool isFlying(long time_ms);
        Coordinate evolve(long time_ms);

    private:
        std::string name;
        std::vector<Stretch> stretchs;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFT_H_ */
