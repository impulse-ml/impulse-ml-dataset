#ifndef IMPULSE_DATASET_DATASET_H
#define IMPULSE_DATASET_DATASET_H

#include "include.h"

using namespace Impulse::Dataset;

namespace Impulse {

    namespace Dataset {

        typedef std::vector<DatasetSample> DatasetData;

        class Dataset {
        protected:
            DatasetData data;
        public:
            ~Dataset();

            void addSample(DatasetSample sample);

            void addSample(DatasetSample *sample);

            DatasetData *getSamples();

            DatasetSample *getSampleAt(int index);

            void out(T_Size limit = 10);

            T_Size getSize();

            T_Size getColumnsSize();
        };
    }
}

#endif//IMPULSRE