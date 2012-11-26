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

        double convertFtToNm(double value_ft);
        double convertDegreesToNm(double value_degrees);
        double convertRadianToDegrees(double value_rad);
        double convertDegreesToRadian(double value_deg);

    private:
        static const double NM_IN_FT;
        static const double NM_IN_DEGREES;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* CONVERTER_H_ */
