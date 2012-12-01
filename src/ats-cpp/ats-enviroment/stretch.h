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
        double getSpeedChangeRate_kt_ms() const;
        void setSpeedChangeRate_kt_ms(const double speedChangeRate_kt_ms);
        double getHeightChangeRate_ft_ms() const;
        void setHeightChangeRate_ft_ms(const double heghtChangeRate_deg);
        double getInitSpeed_kt() const;
        void setInitSpeed_kt(const double initSpeed_kt);
        double getInitHeight_ft() const;
        void setInitHeight_ft(const double initHeight_ft);

    private:
        long limitTime_ms;
        double heading_degrees;
        double speedChangeRate_kt_ms;
        double heightChangeRate_ft_ms;
        double initSpeed_kt;
        double initHeight_ft;
};

} /* namespace enviroment */
} /* namespace ats */
#endif /* AIRCRAFTCCHANGERATE_H_ */
