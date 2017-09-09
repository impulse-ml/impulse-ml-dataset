#include "../include.h"

namespace Impulse {

    namespace Dataset {

        namespace DatasetBuilder {

            DatasetSample Abstract::createSample(T_StringVector vec) {
                DatasetSample sample(vec);
                return sample;
            }
        }
    }
}
