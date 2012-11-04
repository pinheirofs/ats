#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <vector>

#include "application.h"
#include "traffic.h"

namespace ats {
namespace display {

/*
 *
 */
class Application {
    public:
        Application();
        virtual ~Application();

        std::vector<ats::enviroment::Traffic> getAllTraffics() const;
        void addTraffic(const ats::enviroment::Traffic &newTraffic);

    private:
        std::vector<ats::enviroment::Traffic> traffics;
};

} /* namespace display */
} /* namespace ats */
#endif /* APPLICATION_H_ */
