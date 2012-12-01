#ifndef TIMECALCULATOR_H_
#define TIMECALCULATOR_H_

namespace ats {
namespace enviroment {

/*
 *
 */
class StreachCalculator {
    public:
        StreachCalculator();
        virtual ~StreachCalculator();

        void setEndHeight_ft(const double endHeight_ft);
        void setEndLatitude_degrees(const double endLatitude_degrees);
        void setEndLongitude_degrees(const double endLongitude_degrees);
        void setEndSpeed_kt(const double endSpeed_kt);
        double getInitHeight_ft() const;
        void setInitHeight_ft(const double initHeight_ft);
        void setInitLatitude_degrees(const double initLatitude_degrees);
        void setInitLongitude_degrees(const double initLongitude_degrees);
        double getInitSpeed_kt() const;
        void setInitSpeed_kt(const double initSpeed_kt);

        long calculateTimeInterval_ms() const;
        double calculateHeightChangeRate_ft_ms() const;
        double calculateSpeedChangeRate_kt_ms() const;
        double calculateHeading_degrees() const;
        void advance();

    private:
        double initHeight_ft;
        double initLatitude_degrees;
        double initLongitude_degrees;
        double initSpeed_kt;
        double endHeight_ft;
        double endLatitude_degrees;
        double endLongitude_degrees;
        double endSpeed_kt;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* TIMECALCULATOR_H_ */
