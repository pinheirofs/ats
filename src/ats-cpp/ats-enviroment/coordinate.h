#ifndef COORDINATE_H_
#define COORDINATE_H_

namespace ats {
namespace enviroment {

/*
 *
 */
class Coordinate {
    public:
        Coordinate();
        Coordinate(double latitude_deg, double longitude_deg, double height_ft);
        virtual ~Coordinate();

        double getLatitude_deg() const;
        double getLatitude_rad() const;
        double getLongitude_deg() const;
        double getLongitude_rad() const;
        double getHeight_ft() const;

    private:
        double latitude_rad;
        double longitude_rad;
        double height_ft;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* COORDINATE_H_ */
