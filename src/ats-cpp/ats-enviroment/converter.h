#ifndef CONVERTER_H_
#define CONVERTER_H_

namespace ats {
namespace enviroment {

/*
 *
 */
class Converter {
    public:
        Converter();
        virtual ~Converter();

        double convertFtToNm(double value_ft) const;
        double convertDegreesToNm(double value_degrees) const;
        double convertNmToDegrees(double value_nm) const;
        double convertRadianToDegrees(double value_rad) const;
        double convertDegreesToRadian(double value_deg) const;
        double convertMillisecondToHour(double value_ms) const;

    private:
        static const double NM_IN_FT;
        static const double NM_IN_DEG;
        static const double DEG_IN_NM;
        static const double MS_IN_HOUR;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* CONVERTER_H_ */
