#ifndef IMPULSE_DATASET_DATASETBUILDER_ABSTRACT_H
#define IMPULSE_DATASET_DATASETBUILDER_ABSTRACT_H

#include "../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        namespace DatasetBuilder {

            class Abstract {
            protected:
                Dataset dataset;

                DatasetSample createSample(T_StringVector vec);

            public:
                virtual Dataset build() = 0;

                virtual ~Abstract() {}
            };

        }
    }
}

#endif//IMPULSE_DATASET_DATASETBUILDER_ABSTRACT_H
