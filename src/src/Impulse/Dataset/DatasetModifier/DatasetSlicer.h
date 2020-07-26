#pragma once

#include "../include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        struct SlicedDataset {
            Dataset input;
            Dataset output;
        };

        namespace DatasetModifier {

            class DatasetSlicer {
            protected:
                Dataset &dataset;

                T_IntVector inputColumns;

                T_IntVector outputColumns;

            public:
                explicit DatasetSlicer(Dataset &dataset);

                void addInputColumn(int columnIndex);

                void addOutputColumn(int columnIndex);

                SlicedDataset slice();
            };
        }
    }
}
