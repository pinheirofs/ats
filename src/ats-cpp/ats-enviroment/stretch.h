#ifndef AIRCRAFTCCHANGERATE_H_
#define AIRCRAFTCCHANGERATE_H_

namespace ats {
namespace enviroment {

/*
 *
 */
class Stretch {
    public:
        Stretch();
        virtual ~Stretch();

        long getLimitTime_ms() const;
        void setLimitTime_ms(const long limitTime_ms);
        double getHeading_deg();
        void setHeading_deg(const double heading_deg);
        double getSpeedChangeRate_kt_ms2() const;
        void setSpeedChangeRate_kt_ms2(const double speedChangeRate_kt_ms2);
        double getHeightChangeRate_ft() const;
        void setHeightChangeRate_ft_ms(const double heghtChangeRate_deg);
        double getInitSpeed_kt_ms() const;
        void setInitSpeed_kt_ms(const double initSpeed_kt_ms);

    private:
        long limitTime_ms;
        double heading_degrees;
        double speedChangeRate_kt_ms2;
        double heightChangeRate_ft_ms;
        double initSpeed_kt_ms;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFTCCHANGERATE_H_ */
